//
//  interact.cpp
//  wsg
//
//  Created by cosim on 16/6/29.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "interact.hpp"
WSG_BEGIN


void
wsg_operation_param_fill_with_buffer(void *buffer, operation_param_t *opt) {
    unsigned char *pbuf = (unsigned char *)buffer;
    opt->num_card = *(int*)pbuf;
    pbuf += sizeof(int);
    if (opt->num_card > 0) {
        int len = opt->num_card * sizeof(card_id_t);
        opt->cards = new card_id_t[opt->num_card];
        memcpy(opt->cards, pbuf, len);
        pbuf += len;
    }

    opt->num_player = *(int*)pbuf;
    pbuf += sizeof(int);
    if (opt->num_player > 0) {
        int len = opt->num_player * sizeof(player_index_t);
        opt->players = new player_index_t[opt->num_player];
        memcpy(opt->cards, pbuf, len);
        pbuf += len;
    }
}


void
wsg_operation_param_fill_with_buffer(void **buffer, operation_param_t *opt) {
    unsigned char *pbuf = (unsigned char *)buffer;
    opt->num_card = *(int*)pbuf;
    pbuf += sizeof(int);
    if (opt->num_card > 0) {
        int len = opt->num_card * sizeof(card_id_t);
        opt->cards = new card_id_t[opt->num_card];
        memcpy(opt->cards, pbuf, len);
        pbuf += len;
    }
    
    opt->num_player = *(int*)pbuf;
    pbuf += sizeof(int);
    if (opt->num_player > 0) {
        int len = opt->num_player * sizeof(player_index_t);
        opt->players = new player_index_t[opt->num_player];
        memcpy(opt->cards, pbuf, len);
        pbuf += len;
    }
}
WSG_END