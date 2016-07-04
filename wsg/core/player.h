//
//  player.h
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__PLAYER__H__
#define __WSG__PLAYER__H__



#include <vector>
WSG_BEGIN

//#include "card.h"

class Player {
public:
    Player();
    int id;
    int blood;
    int blood_limit;
    
    bool reversed;
    bool alive;
    
    Cards hand_cards;
    
    void selectHeroes(int i);
    
    int getSelectableHeroesNum();
    
    
    
    bool hintPlayer();
    void getPlayerAction();
    
    
    
    
    
    
    
    
};

typedef std::vector<Player*> Players;
typedef int player_index_t;

WSG_END
#endif /* defined(__WSG__PLAYER__H__) */
