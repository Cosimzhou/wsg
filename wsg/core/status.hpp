//
//  status.hpp
//  wsg
//
//  Created by 周志超 on 16/4/27.
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
extern const fsm_status_t fsm_game_courses[];
#define NULL_PHASE                      ((fsm_status_t)0)



typedef enum {
    FP_Distance,
} fsm_param_t;





class FSM: queue<const fsm_status_t> {
public:
    FSM(Game *game);

    /**
     *  is need to continue this FSM. if false, FSM will be poped out
     *  and go the prevous FSM in game stack.
     */
    bool operator++();


#define __WSG__DECLARE__FSM__STATUS__H__
#   include "fsm-status.h"
#undef __WSG__DECLARE__FSM__STATUS__H__



    Game *_game;
    player_index_t _obj;

    union {
        int iRet;
        char *sRet;
    };

    int param[16];

    friend class Game;
protected:
    FSM(const fsm_status_t *fsm_course, Game *game);
    
    Player* curPlayer() const;

    void triggerSkill(const fsm_status_t st);

};

WSG_END
#endif /* __WSG__STATUS__HPP__ */