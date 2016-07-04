//
//  game.h
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//


#include "wsg.h"

#ifndef __WSG__GAME__H__
#define __WSG__GAME__H__

#include <stack>
#include <vector>


WSG_BEGIN


class FSM;
class Player;

//typedef enum {
//    STATUS_NONE,
//    STATUS_MASTER,
//    STATUS_LOYAL,
//    STATUS_TRAITOR,
//    STATUS_REBEL,
//    STATUS_COLD,
//    STATUS_WARM,
//} status;

class Game {
public:
    Game();
    Game(const Game&);

    void assign_hero();

    int round_player;
    int current_player;
    
    void perform(FSM*);
    
    void play();
    
    Players players;
    CardHeap card_heap;
    CardHeap discard_heap;


    bool hintTriggerSkill(player_index_t plr, const skill_entry_t *psk) const;

    int getDistanceBetween(player_index_t from, player_index_t to);
    card_pattern_t getCardPattern(player_index_t obj, card_id_t card);
    card_point_t getCardPointNum(player_index_t obj, card_id_t card);

    void changePlayerBlood(player_index_t obj, int delta);

    SkillRegister sr;
//protected:
    std::stack<FSM*> fsm;
    
};

WSG_END
#endif /* defined(__WSG__GAME__H__) */
