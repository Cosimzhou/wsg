//
//  game.cpp
//  sgs
//
//  Created by 周志超 on 15/6/16.
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

void Game::assign_hero() {
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
            mvhm[name] = wsg_hero_v_find_by_name(name.c_str());
        }
        vmvhm.push_back(mvhm);
    }

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
