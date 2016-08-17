//
//  fsm.hpp
//  wsg
//
//  Created by cosim on 16/4/27.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__STATUS__HPP__
#define __WSG__STATUS__HPP__

WSG_BEGIN

class Game;
class Player;
class FSM;

typedef int (*fsm_status_t)(FSM*);
#define NULL_PHASE                      ((fsm_status_t)0)
#define SCRS(c)                         fsm_##c##_courses


typedef enum {
    FP_distance,                //
    FP_draw_card_num,           // round draw card number
    FP_discard_num,             //
    FP_target_player,           //
    FP_card,                    //
    FP_card_pattern,            //
    FP_delta_blood,             //
    FP_round_draw_skip,         //
    FP_round_play_skip,         //
} fsm_param_type_t;

typedef map<fsm_param_type_t, int> fsm_param_t;

class FSM: public queue<const fsm_status_t> {
public:
    FSM(Game *game);

    /**
     *  is need to continue this FSM. if false, FSM will be poped out
     *  and go the prevous FSM in game stack.
     */
    bool operator++();

    Game *_game;
    player_index_t _obj;

    union {
        int iRet;
        char *sRet;
    };

    fsm_param_t params;
    
    bool param_valid(fsm_param_type_t) const;
    int param_value(fsm_param_type_t) const;
    
    friend class Game;
//protected:
    FSM(const fsm_status_t *fsm_course, Game *game, player_index_t plr);
    void triggerSkill(const fsm_status_t st);

};

#define __WSG__DECLARE__FSM__STATUS__H__
#   undef __WSG__FSM__STATUS__H__
#   define FSMB(c)  extern const fsm_status_t SCRS(c)[];
#   define FSME(c)
#   define R(p)                                                                 \
extern int p(FSM*);                                                             \
extern int p##_after(FSM*);
#   include "fsm-status.h"
#undef __WSG__DECLARE__FSM__STATUS__H__
WSG_END
#endif /* defined(__WSG__STATUS__HPP__) */