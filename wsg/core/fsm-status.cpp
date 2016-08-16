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
#   define SHOW_ME()    do {                                                    \
;                           for(int _i=0;_i<self->_game->fsm.size()-1;++_i) {   \
;                               cout<<"  ";                                     \
;                           }                                                   \
;                           cout<<__func__<<endl;                               \
;                       } while(0)
#else // DEBUG
#   define SHOW_ME()
#endif //DEBUG

#define FSM_NEW(p)      FSM *fsm = new FSM(SCRS(p), self->_game, self->_obj)
#define FSM_NEW_RD(p,r) FSM *fsm = new FSM(SCRS(p), self->_game, r)
#define FSM_SEND()      self->_game->perform(fsm)
#define CURPLAYER       self->_game->players[self->_obj]
#define SCRS(c)         fsm_##c##_courses

/*******************************************************************************
 *
 *  declaring constant part
 *
 *******************************************************************************/

// declare skill array
#define __WSG__DECLARE__FSM__STATUS__H__
#   undef __WSG__FSM__STATUS__H__
#   define FSMB(c)                                                             \
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



int Game::getDistanceBetween(player_index_t from, player_index_t to) {
    if (from == to) return 0;

    FSM *fsm = new FSM(fsm_distance_courses, this, from);
    fsm->params[FP_target_player] = to;
    perform(fsm);

    return fsm->iRet;
}

card_pattern_t Game::getCardPattern(player_index_t obj, card_id_t card) {
    if (obj < 0) return (card_pattern_t)0;

    const fsm_status_t fsa[] = {card_pattern, NULL_PHASE};
    FSM *fsm = new FSM(fsa, this, obj);
    fsm->params[FP_card] = card;
    fsm->params[FP_card_pattern] = POKER_PAT(card);
    perform(fsm);

    return (card_pattern_t)fsm->params[FP_card_pattern];
}

card_point_t Game::getCardPointNum(player_index_t obj, card_id_t card) {
    return (card_point_t)0;
}

void Game::changePlayerBlood(player_index_t obj, int delta) {
    FSM *fsm = new FSM(SCRS(blood_change), this, obj);
    fsm->params[FP_delta_blood] = delta;
    perform(fsm);
}


/*******************************************************************************
 *
 *  all fsm_status_t implemented below
 *
 *******************************************************************************/
#pragma mark - game
int game_begin(FSM *self) {
    SHOW_ME();
    for (int i = 0; i < self->_game->players.size(); ++i) {
        for (int n = 0; n < 4; ++n) {
            card_id_t cid = self->_game->draw_card();
            self->_game->players[i]->hand_cards.push_back(cid);
        }
    }
    return 0;
}
int game_play(FSM *self) {
    SHOW_ME();
    while (true) {
        for (int i = 0; i < self->_game->players.size(); ++i) {
            FSM_NEW_RD(round, i);
            FSM_SEND();
        }
    }
    return 0;
}
int game_over(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - round
int round_begin(FSM *self) {
    cout<<"  * No."<<self->_obj+1<<" ***"<<CURPLAYER->heroModel[0]->name<<"****"<<endl<<"    ";
    for (auto &x: CURPLAYER->hand_cards) {
        cout<< Card::cardinfo(x)<<" ";
    }
    cout<<endl;
    
    SHOW_ME();
    self->params[FP_draw_card_num] = 2;
    
    return 0;
}
int round_judge(FSM *self) {
    SHOW_ME();
    return 0;
}
int round_draw(FSM *self) {
    SHOW_ME();
    int dcn = self->params[FP_draw_card_num];
    self->_game->player_draw_cards(self->_obj, dcn);
    return 0;
}
int round_play(FSM *self) {
    SHOW_ME();

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
    
    return 0;
}
int round_discard(FSM *self) {
    SHOW_ME();
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
    return 0;
}
int round_over(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - card_uplimit
int card_uplimit(FSM *self) {
    SHOW_ME();
    self->iRet = CURPLAYER->blood;
    return 0;
}

#pragma mark - discard
int discard(FSM *self) {
    SHOW_ME();
    
    int dcn = self->param_value(FP_discard_num);
    while (dcn-- > 0) {
        if (CURPLAYER->hand_cards.empty())
            break;
    
        card_id_t cid = CURPLAYER->hand_cards.front();
        CURPLAYER->hand_cards.pop_front();
        self->_game->discard_heap.push_back(cid);
    }
    
    return 0;
}

#pragma mark - card_cpn
int card_pattern(FSM *self) {
    SHOW_ME();
    return 0;
}
int card_color(FSM *self) {
    SHOW_ME();
    return 0;
}
int card_dotnum(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - distance
int distance_calc(FSM *self) {
    SHOW_ME();
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

    self->iRet = d1<d2? d1: d2;

    return 0;
}


int distance_from(FSM *self) {
    SHOW_ME();
    __swap__(self->_obj, self->params[FP_target_player]);
    return 0;
}

int distance_to(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - hurt_give
int hurt_form(FSM *self) {
    SHOW_ME();
    return 0;
}
int hurt_give(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - hurted
int hurt_receive(FSM *self) {
    SHOW_ME();
    return 0;
}
int hurted(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - blood_chang
int blood_change(FSM *self) {
    SHOW_ME();
    CURPLAYER->blood += self->params[FP_delta_blood];
    return 0;
}



int smart_play(FSM *self) {
    return 0;
}
int smart_act_on(FSM *self) {
    return 0;
}


WSG_END