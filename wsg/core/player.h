//
//  player.h
//  wsg
//
//  Created by cosim on 15/6/15.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__PLAYER__H__
#define __WSG__PLAYER__H__

WSG_BEGIN

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
    void setHeroes(const hero_model_t *phm);
    
    int getSelectableHeroesNum() const;
    
    
    
    bool hintPlayer();
    void getPlayerAction();
    
    
    
    const hero_model_t *heroModel[2];
    
    
    
    
};

typedef vector<Player*> Players;


WSG_END
#endif /* defined(__WSG__PLAYER__H__) */