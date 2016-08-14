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
    void *buff;
    int num_card;
    int num_player;
    card_id_t *cards;
    player_index_t *players;
} operation_param_t;

typedef struct {
    operation_param_t params;
    const char *msg;
} hint_param_t;

typedef struct {
    operation_param_t params;
    int option;
} action_param_t;

class interact {
public:
    int timeout;
    
    bool hintAct(const hint_param_t *);
    void getAction(operation_param_t *);
};

extern void
wsg_operation_param_fill_with_buffer(void *, operation_param_t *);
extern void
wsg_operation_param_fill_to_buffer(void **buffer, operation_param_t *opt);
WSG_END
#endif /* defined(__WSG__INTERACT__H__) */