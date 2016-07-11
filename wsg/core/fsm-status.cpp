//
//  fsm-status.cpp
//  wsg
//
//  Created by cosim on 16/5/19.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "fsm.hpp"
WSG_BEGIN

//#error Oh! no! I don't want this
//#warning Oh! no! I don't want this

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


#define ARR_PHASE(x)    FSM::x,FSM::x##_after
#define FSM_NEW(p)      FSM *fsm = new FSM(SCRS(p), self->_game, self->_obj)
#define FSM_NEW_RD(p,r) FSM *fsm = new FSM(SCRS(p), self->_game, r)
#define FSM_SEND()      self->_game->perform(fsm)
#define CURPLAYER       self->_game->players[self->_obj]
#define SCRS(c)         fsm_##c##_courses
#define DCRS(c,...)                                                             \
const fsm_status_t SCRS(c)[] = {__VA_ARGS__, NULL_PHASE}


/*******************************************************************************
 *
 *  declaring constant variables
 *
 *******************************************************************************/

DCRS(game,
    ARR_PHASE(game_begin),
    ARR_PHASE(game_play),
    ARR_PHASE(game_over)
    );

DCRS(round,
    ARR_PHASE(round_begin),
    ARR_PHASE(round_judge),
    ARR_PHASE(round_draw),
    ARR_PHASE(round_play),
    ARR_PHASE(round_discard),
    ARR_PHASE(round_over)
    );

DCRS(distance,
     ARR_PHASE(distance_calc),
     ARR_PHASE(distance_from),
     ARR_PHASE(distance_to)
     );

//DCRS(card_cpn,
//     ARR_PHASE(card_pattern),
//     ARR_PHASE(card_color),
//     ARR_PHASE(card_dotnum)
//     );

//DCRS(play_card,
//     ARR_PHASE(a),
//     );

DCRS(hurt_give,
     ARR_PHASE(hurt_form),
     ARR_PHASE(hurt_give)
     );

DCRS(hurted,
     ARR_PHASE(hurt_receive),
     ARR_PHASE(hurted)
     );

DCRS(blood_change,
     ARR_PHASE(blood_change)
     );


DCRS(card_uplimit, ARR_PHASE(card_uplimit));

DCRS(discard, ARR_PHASE(discard));
#undef DCRS



//inline Player* FSM::curPlayer() const {
//    return (_game && _obj >= 0)? _game->players[_obj]: NULL;
//}


int Game::getDistanceBetween(player_index_t from, player_index_t to) {
    if (from == to) return 0;

    FSM *fsm = new FSM(fsm_distance_courses, this, from);
    fsm->params[FP_target_player] = to;
    perform(fsm);

    return fsm->iRet;
}

card_pattern_t Game::getCardPattern(player_index_t obj, card_id_t card) {
    if (obj < 0) return (card_pattern_t)0;

    const fsm_status_t fsa[] = {ARR_PHASE(card_pattern), NULL_PHASE};
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
int FSM::game_begin(FSM *self) {
    SHOW_ME();
    for (int i = 0; i < self->_game->players.size(); ++i) {
        for (int n = 0; n < 4; ++n) {
            card_id_t cid = self->_game->draw_card();
            self->_game->players[i]->hand_cards.push_back(cid);
        }
    }
    return 0;
}
int FSM::game_play(FSM *self) {
    SHOW_ME();
    while (true) {
        for (int i = 0; i < self->_game->players.size(); ++i) {
            FSM_NEW_RD(round, i);
            FSM_SEND();
        }
    }
    return 0;
}
int FSM::game_over(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - round
int FSM::round_begin(FSM *self) {
    cout<<"  * No."<<self->_obj+1<<" ***"<<CURPLAYER->heroModel[0]->name<<"****"<<endl<<"    ";
    for (auto &x: CURPLAYER->hand_cards) {
        cout<< Card::cardinfo(x)<<" ";
    }
    cout<<endl;
    
    SHOW_ME();
    self->params[FP_draw_card_num] = 2;
    
    return 0;
}
int FSM::round_judge(FSM *self) {
    SHOW_ME();
    return 0;
}
int FSM::round_draw(FSM *self) {
    SHOW_ME();
    int dcn = self->params[FP_draw_card_num];
    self->_game->player_draw_cards(self->_obj, dcn);
    return 0;
}
int FSM::round_play(FSM *self) {
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
int FSM::round_discard(FSM *self) {
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
int FSM::round_over(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - card_uplimit
int FSM::card_uplimit(FSM *self) {
    SHOW_ME();
    self->iRet = CURPLAYER->blood;
    return 0;
}

#pragma mark - discard
int FSM::discard(FSM *self) {
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
int FSM::card_pattern(FSM *self) {
    SHOW_ME();
    return 0;
}
int FSM::card_color(FSM *self) {
    SHOW_ME();
    return 0;
}
int FSM::card_dotnum(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - distance
int FSM::distance_calc(FSM *self) {
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


int FSM::distance_from(FSM *self) {
    SHOW_ME();
    __swap__(self->_obj, self->params[FP_target_player]);
    return 0;
}

int FSM::distance_to(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - hurt_give
int FSM::hurt_form(FSM *self) {
    SHOW_ME();
    return 0;
}
int FSM::hurt_give(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - hurted
int FSM::hurt_receive(FSM *self) {
    SHOW_ME();
    return 0;
}
int FSM::hurted(FSM *self) {
    SHOW_ME();
    return 0;
}

#pragma mark - blood_chang
int FSM::blood_change(FSM *self) {
    SHOW_ME();
    CURPLAYER->blood += self->params[FP_delta_blood];
    return 0;
}



WSG_END