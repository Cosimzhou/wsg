//
//  player.c
//  wsg
//
//  Created by cosim on 15/6/15.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//

#include "player.h"

WSG_BEGIN


//errcode
//sgs_player_die(player_seq *players, int index) {
//    if (0 <= index && index < players->player_num) {
//        if (players->players[index].id) {
//            return ERR_SUCCESS;
//        }
//    }
//    return ERR_EODU_HERO;
//}


Player::Player(): alive(true) {
    heroModel[0] = NULL;
    heroModel[1] = NULL;
}

void Player::selectHeroes(int i) {
    
}

int Player::getSelectableHeroesNum() const {
    return 5;
}


void Player::setHeroes(const hero_model_t *phm) {
    this->blood_limit = phm->blood;
//    this->
}

WSG_END