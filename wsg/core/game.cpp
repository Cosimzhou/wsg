//
//  game.cpp
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "game.hpp"

#include <stdlib.h>
//#include <vector>
#include <string>
#include <set>

WSG_BEGIN

Game::Game()
    :players(), fsm(), card_heap(), discard_heap(), sr(this)
{
    
}

Game::Game(const Game &g) : players(), fsm(), card_heap(), discard_heap(), sr(this) {
    
}

void Game::assign_hero() {
    vector<string> *pvec = Hero::getHeroNamesByPackageID((package_mark_t)0x7f);
    vector<vector<string> > psh;
    set<int> sdidx;

    int idx, hnpp = pvec->size()/players.size();
    if (hnpp < 3)
        exit(0);
    if (hnpp > 7) hnpp = 7;

    for(int i = 0; i < this->players.size(); ++i) {
        vector<string> ppna;
        for (int j = 0; j < 5; ++j) {
            idx = rand() % pvec->size();
            while(sdidx.find(idx) != sdidx.end())
                idx = rand() % pvec->size();
            ppna.push_back((*pvec)[idx]);
        }
        psh.push_back(ppna);
    }

    delete pvec;
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

bool Game::hintTriggerSkill() {
    return false;
}


WSG_END
