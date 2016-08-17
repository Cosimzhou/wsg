//
//  fsm-status.cpp
//  wsg
//
//  Created by cosim on 16/5/19.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "fsm.hpp"
WSG_BEGIN

/*******************************************************************************
 *
 *  macro utilities
 *
 *******************************************************************************/

#ifdef DEBUG
#   define SHOW_ME()    cout<<SPACE(self->_game->fsm.size()*2-2)<<__func__<<endl
#else // DEBUG
#   define SHOW_ME()
#endif //DEBUG

#define DEF(f)          int f(FSM *self) { int ret = 0; SHOW_ME();
#define ENDEF           return ret;}

#define FSM_NEW(p)      FSM *fsm = new FSM(SCRS(p), self->_game, self->_obj)
#define FSM_NEW_RD(p,r) FSM *fsm = new FSM(SCRS(p), self->_game, r)
#define FSM_SEND()      self->_game->perform(fsm)
#define CURPLAYER       self->_game->players[self->_obj]

/*******************************************************************************
 *
 *  declaring constant part
 *
 *******************************************************************************/

// declare skill array
#define __WSG__DECLARE__FSM__STATUS__H__
#   undef __WSG__FSM__STATUS__H__
#   define FSMB(c)                                                              \
const fsm_status_t SCRS(c)[] = {
#   define FSME(c)              NULL_PHASE};
#   define R(p)                 p, p##_after,
#   include "fsm-status.h"
#undef __WSG__DECLARE__FSM__STATUS__H__

// declare skill after function
#define __WSG__DECLARE__FSM__STATUS__H__
#   undef __WSG__FSM__STATUS__H__
#   define FSMB(c)
#   define FSME(c)
#   define R(p)                 int p##_after(FSM*){return 0;}
#   include "fsm-status.h"
#undef __WSG__DECLARE__FSM__STATUS__H__



/*******************************************************************************
 *
 *  all fsm_status_t implemented below
 *
 *******************************************************************************/
#pragma mark - game
DEF(game_begin) {
    for (int i = 0; i < self->_game->players.size(); ++i) {
        for (int n = 0; n < 4; ++n) {
            card_id_t cid = self->_game->draw_card();
            self->_game->players[i]->hand_cards.push_back(cid);
        }
    }
} ENDEF;

DEF(game_play) {
    while (true) {
        for (int i = 0; i < self->_game->players.size(); ++i) {
            FSM_NEW_RD(round, i);
            FSM_SEND();
        }
    }

    
} ENDEF;

DEF(game_over) {
} ENDEF;

#pragma mark - round
DEF(round_begin) {
    cout<<"  * No."<<self->_obj+1<<" ***"<<CURPLAYER->heroModel[0]->name<<"****"<<endl<<"    ";
    for (auto &x: CURPLAYER->hand_cards) {
        cout<< Card::cardinfo(x)<<" ";
    }
    cout<<endl;
    
    SHOW_ME();
    self->params[FP_draw_card_num] = 2;
    
    return 0;
} ENDEF;

DEF(round_judge) {
} ENDEF;

DEF(round_draw) {
    if (self->params[FP_round_draw_skip])
        return 0;
    
    int dcn = self->params[FP_draw_card_num];
    self->_game->player_draw_cards(self->_obj, dcn);
} ENDEF;

DEF(round_play) {
    if (self->params[FP_round_play_skip])
        return 0;
    
    int dist = self->_game->getDistanceBetween(self->_obj, 0);
    cout<<"    dist:"<<dist<<endl;
    cout<<"    ";
    for (auto &x: self->_game->players[self->_obj]->hand_cards) {
        cout<<Card::cardinfo(x)<<" ";
        if (Card::card_function(x) == KP_NANMANRUQIN) {
            //xxx
            break;
        }
    }
    cout<<endl;
} ENDEF;

DEF(round_discard) {
    int cardlim = 0;
    {
        FSM_NEW(card_uplimit);
        FSM_SEND();
        cardlim = fsm->iRet;
    }  {
        cardlim = (int)CURPLAYER->hand_cards.size() - cardlim;
        if (cardlim > 0) {
            FSM_NEW(discard);
            fsm->params[FP_discard_num] = cardlim;
            FSM_SEND();
        }
    }
} ENDEF;

DEF(round_over) {
} ENDEF;

#pragma mark - card_uplimit
DEF(card_uplimit) {
    self->iRet = CURPLAYER->blood;
} ENDEF;

#pragma mark - discard
DEF(discard) {
    int dcn = self->param_value(FP_discard_num);
    while (dcn-- > 0) {
        if (CURPLAYER->hand_cards.empty())
            break;
    
        card_id_t cid = CURPLAYER->hand_cards.front();
        CURPLAYER->hand_cards.pop_front();
        self->_game->discard_heap.push_back(cid);
    }
} ENDEF;

#pragma mark - card_cpn
DEF(card_pattern) {
} ENDEF;
DEF(card_color) {
} ENDEF;
DEF(card_dotnum) {
} ENDEF;

#pragma mark - distance
DEF(distance_calc) {
    int i, p, plrcnt = (int)self->_game->players.size();
    int d1 = 0, d2 = 0, plr = self->params[FP_target_player];

    if (self->_obj == plr)
        return 0;

    for (i = 1; i < plrcnt; ++i) {
        p = self->_obj + i;
        if (p >= plrcnt) p -= plrcnt;
        if (self->_game->players[p]->alive) ++d1;
        if (plr == p) break;
    }

    for (i = 1; i < plrcnt; ++i) {
        p = self->_obj - i;
        if (p < 0) p += plrcnt;
        if (self->_game->players[p]->alive) ++d2;
        if (plr == p) break;
    }

    self->iRet = min(d1, d2);
} ENDEF;


DEF(distance_from) {
    __swap__(self->_obj, self->params[FP_target_player]);
} ENDEF;

DEF(distance_to) {
} ENDEF;

#pragma mark - hurt_give
DEF(hurt_form) {
} ENDEF;
DEF(hurt_give) {
} ENDEF;

#pragma mark - hurted
DEF(hurt_receive) {
} ENDEF;
DEF(hurted) {
} ENDEF;

#pragma mark - blood_chang
DEF(blood_change) {
    CURPLAYER->blood += self->params[FP_delta_blood];
} ENDEF;


#pragma mark - smart
DEF(smart_play) {
} ENDEF;
DEF(smart_act_on) {
} ENDEF;
DEF(smart_show) {
} ENDEF;

#pragma mark - EXAMPLE FUNCTION
DEF(a) {

} ENDEF;
WSG_END