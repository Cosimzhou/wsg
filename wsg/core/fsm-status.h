//
//  fsm-status.h
//  wsg
//
//  Created by 周志超 on 16/5/19.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#ifdef  __WSG__DECLARE__FSM__STATUS__H__
#   ifndef __WSG__FSM__STATUS__H__
#       define __WSG__FSM__STATUS__H__
#       define DEF_PHASE(p)     static int p(FSM*);                             \
                                static int p##_after(FSM*){return 0;}

DEF_PHASE(game_begin);
DEF_PHASE(game_play);
DEF_PHASE(game_over);

DEF_PHASE(round_begin);
DEF_PHASE(round_judge);
DEF_PHASE(round_draw);
DEF_PHASE(round_play);
DEF_PHASE(round_discard);
DEF_PHASE(round_over);

DEF_PHASE(discard);

DEF_PHASE(distance_calc);
DEF_PHASE(distance_to);
DEF_PHASE(distance_from);

DEF_PHASE(card_color);
DEF_PHASE(card_pattern);
DEF_PHASE(card_dotnum);

DEF_PHASE(card_uplimit);


DEF_PHASE(hurt_form);
DEF_PHASE(hurt_give);

DEF_PHASE(hurt_receive);
DEF_PHASE(hurted);

DEF_PHASE(blood_change);











#       undef DEF_PHASE
#   endif /* __WSG__FSM__STATUS__H__ */
#endif /* __WSG__DECLARE__FSM__STATUS__H__ */