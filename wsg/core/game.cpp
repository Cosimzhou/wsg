//
//  game.cpp
//  wsg
//
//  Created by cosim on 15/6/16.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//

#include "game.hpp"
#include <stdlib.h>

WSG_BEGIN

Game::Game()
    :players(), fsm(), card_heap(), discard_heap(), sr(this)
{
    
}

Game::Game(const Game &g) : players(), fsm(), card_heap(), discard_heap(), sr(this) {
    
}

GameHeroOptions Game::heroChoosenOptions() const {
    vector<string> vec = Hero::getHeroNamesByPackageID((package_mark_t)0x7f);
    set<int> sdidx;
    
    //    int hnpp = (int)vec.size()/players.size();
    //    if (hnpp < 3) exit(0);
    //    if (hnpp > 7) hnpp = 7;
    
    GameHeroOptions vmvhm;
    for(int i = 0; i < this->players.size(); ++i) {
        PlayerHeroOptions mvhm;
        for (int j = 0; j < this->players[i]->getSelectableHeroesNum(); ++j) {
            int idx = rand() % vec.size();
            while(sdidx.find(idx) != sdidx.end())
                idx = rand() % vec.size();
            sdidx.insert(idx);
            string name = vec[idx];
            mvhm[name] = wsg_hero_find_model_vector_by_name(name.c_str());
        }
        vmvhm.push_back(mvhm);
    }
    
    return vmvhm;
}
void Game::assign_hero() {
    GameHeroOptions vmvhm = heroChoosenOptions();

    for (auto i = vmvhm.begin(); i != vmvhm.end(); ++i) {
        for (auto j = i->begin(); j != i->end(); ++j) {
            cout<<j->first<<"(";
            for (auto k = j->second.begin(); k != j->second.end(); ++k) {
                if (k != j->second.begin()) cout<<" ";
                cout<<(*k)->name<<(*k)->heroid;
            }            
            cout<<")  ";
        }
        cout<<endl;
    }
    
    
    const hero_model_t *phm;
    for (int i = 0; i < players.size(); ++i) {
        players[i]->heroModel[0] = vmvhm[i].begin()->second[0];
        for (auto vi = vmvhm[i].begin(); vi != vmvhm[i].end(); ++vi) {
            if (rand()%5 > 3) {
                players[i]->heroModel[0] = vi->second[rand() % vi->second.size()];
                break;
            }
        }
        phm = players[i]->heroModel[0];
        cout<<"在"<<i+1<<"号位玩家选择了："<<phm->name<<"("<<phm->heroid<<")"<<endl;
        
        for (int s = 0; s < 16 && phm->skills[s]; ++s) {
            sr.install(phm->skills[s], i);
        }
    }
}

void Game::perform(FSM *pfsm){
    fsm.push(pfsm);
    
    while (++(*pfsm)) {
        
    }
    
    fsm.pop();
    delete pfsm;
}

void Game::play() {
    FSM *fsm = new FSM(this);
    perform(fsm);
}

bool Game::hintTriggerSkill(player_index_t plr, const skill_entry_t *psk) const {
    cout<<"will you act skill "<<psk->name<<"?"<<endl;
    return false;
}


WSG_END
