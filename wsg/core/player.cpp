//
//  player.c
//  sgs
//
//  Created by 周志超 on 15/6/15.
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

}

void Player::selectHeroes(int i) {
    
}

int Player::getSelectableHeroesNum() {
    return 5;
}
WSG_END