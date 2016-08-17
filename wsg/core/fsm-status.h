//
//  fsm-status.h
//  wsg
//
//  Created by cosim on 16/5/19.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#ifdef  __WSG__DECLARE__FSM__STATUS__H__
#   ifndef __WSG__FSM__STATUS__H__
#       define __WSG__FSM__STATUS__H__
#       if defined(FSMB) && defined(FSME) && defined(R)
//
FSMB(game)
R(game_begin)
R(game_play)
R(game_over)
FSME(game)

//
FSMB(round)
R(round_begin)
R(round_judge)
R(round_draw)
R(round_play)
R(round_discard)
R(round_over)
FSME(round)

//
FSMB(distance)
R(distance_calc)
R(distance_from)
R(distance_to)
FSME(distance)

//
FSMB(hurt_give)
R(hurt_form)
R(hurt_give)
FSME(hurt_give)

//
FSMB(hurted)
R(hurt_receive)
R(hurted)
FSME(hurted)

//
FSMB(blood_change)
R(blood_change)
FSME(blood_change)

//
FSMB(card_uplimit)
R(card_uplimit)
FSME(card_uplimit)

//
FSMB(card_pattern)
R(card_pattern)
FSME(card_pattern)

//
FSMB(discard)
R(discard)
FSME(discard)

//
FSMB(smart)     //
R(smart_show)
R(smart_act_on)
R(smart_play)
FSME(smart)

//
FSMB(selfe)
R(a)
FSME(selfe)

#           undef FSMB
#           undef FSME
#           undef R
#       endif // FSMB, FSME, R
#   endif /* __WSG__FSM__STATUS__H__ */
#endif /* defined(__WSG__DECLARE__FSM__STATUS__H__) */