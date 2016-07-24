//
//  interact.hpp
//  wsg
//
//  Created by cosim on 16/6/29.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__INTERACT__H__
#define __WSG__INTERACT__H__

WSG_BEGIN

typedef struct  {
    int num_card;
    card_id_t *cards;
    int num_player;
    player_index_t *players;
} operation_param_t;

typedef struct {
    operation_param_t params;
    char *msg;
} hint_param_t;

typedef struct {
    operation_param_t params;
    int option;
} action_param_t;

class interact {
    int timeout;
    
    bool hintAct(void *);
    void getAction(void *);
};

extern void
wsg_operation_param_fill_with_buffer(void *, operation_param_t *);

WSG_END
#endif /* defined(__WSG__INTERACT__H__) */