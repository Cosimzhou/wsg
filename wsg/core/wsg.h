//
//  wsg.h
//  wsg
//
//  Created by 周志超 on 16/4/27.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#ifndef __WSG__H__
#define __WSG__H__

//#define USING_WSG_NAMESPACE
#ifdef USING_WSG_NAMESPACE
#   define WSG_BEGIN       namespace WSG{
#   define WSG_END         }
#else //USING_WSG_NAMESPACE
#   define WSG_BEGIN
#   define WSG_END
#endif//USING_WSG_NAMESPACE


#define __VA_ARGC__(...)        CSM_NARG(__VA_ARGS__,CSM_N_SEQ())
#define CSM_NARG(...)           CSM_ARG_N(__VA_ARGS__)
#define CSM_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9,_10,  \
                  _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
                  _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
                  _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
                  _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
                  _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
                  _61,_62,_63,N,...)              \
                                N

#define CSM_N_SEQ()             63,62,61,60, \
                                59,58,57,56,55,54,53,52,51,50, \
                                49,48,47,46,45,44,43,42,41,40, \
                                39,38,37,36,35,34,33,32,31,30, \
                                29,28,27,26,25,24,23,22,21,20, \
                                19,18,17,16,15,14,13,12,11,10, \
                                9,8,7,6,5,4,3,2,1,0

#define __lenof__(arr)          (sizeof(arr)/sizeof(*arr))
#define __swap__(x,y)           do{__typeof__(x) t=x;x=y;y=t;}while(0)
//PP_NARG

using namespace std;

#include "card.h"

#include "player.h"

#include "status.hpp"

#include "skill.h"
#include "hero.h"



#include "game.hpp"




#endif /* __WSG__H__ */
