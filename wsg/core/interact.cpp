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
    opt->buff = buffer;
    opt->num_card = CSM_READ_NCB(*(int*)pbuf);
    pbuf += sizeof(int);
    opt->num_player = CSM_READ_NCB(*(int*)pbuf);
    pbuf += sizeof(int);
    
    if (opt->num_card > 0) {
        int len = opt->num_card * sizeof(card_id_t);
        opt->cards = (card_id_t*)pbuf;
        pbuf += len;
    }
    

    if (opt->num_player > 0) {
        int len = opt->num_player * sizeof(player_index_t);
        opt->players = (card_id_t*)pbuf;
        pbuf += len;
    }
}


void
wsg_operation_param_fill_to_buffer(void **buffer, operation_param_t *opt) {
    *buffer = malloc(sizeof(int)*(2+opt->num_card+opt->num_player));
    unsigned char *pbuf = (unsigned char*)buffer;
    *(int*)pbuf = opt->num_card;
    pbuf += sizeof(int);
    
    *(int*)pbuf = opt->num_player;
    pbuf += sizeof(int);
    
    if (opt->num_card > 0) {
        int len = opt->num_card * sizeof(card_id_t);
        memcpy(pbuf, opt->cards, len);
        pbuf += len;
    }
    
    if (opt->num_player > 0) {
        int len = opt->num_player * sizeof(player_index_t);
        memcpy(pbuf, opt->cards, len);
        pbuf += len;
    }
}

void
wsg_operation_param_free(operation_param_t *opt) {
    if (opt->cards) delete opt->cards;
    if (opt->players) delete opt->players;
    opt->cards = opt->players = NULL;
}

bool interact::hintAct(const hint_param_t *) {
    return true;
}
void interact::hintActAsync(const hint_param_t *) {
    
}
void interact::getAction(operation_param_t *) {

}

WSG_END