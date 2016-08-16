//
//  wsg.h
//  wsg
//
//  Created by cosim on 16/4/27.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#ifndef __WSG__H__
#define __WSG__H__


#define WSG_USING_CHAR_AS_ENUM
#define WSG_USING_WSG_NAMESPACE
#ifdef WSG_USING_WSG_NAMESPACE
#   define WSG_BEGIN            namespace WSG{
#   define WSG_END              };
#   define WSG_USING            using namespace WSG
#else //WSG_USING_WSG_NAMESPACE
#   define WSG_BEGIN
#   define WSG_END
#   define WSG_USING
#endif //WSG_USING_WSG_NAMESPACE


#define __xbig__(x)          ({__typeof__(x) t = x;                             \
                               __xbit##sizeof(x)##__((unsigned char*)&t);       \
                               t})
#define __xbit1__(b)          (b)
#define __xbit2__(b)          __swap__((b)[0],(b)[1])
#define __xbit4__(b)          __swap__((b)[0],(b)[3]),__swap__((b)[1],(b)[2])
#define __xbit8__(b)          __swap__((b)[0],(b)[7]),__swap__((b)[1],(b)[6]),  \
                              __swap__((b)[2],(b)[5]),__swap__((b)[3],(b)[4])

#if WSG_USING_NTOH
#   define CSM_READ_NCB          NTOHL
#   define CSM_WRITE_NCB         HTONL
#else//WSG_USING_NTOH
#   if LITTLE_ENDIAN
#       define CSM_READ_NCB(x)   __xbig__(x)
#       define CSM_WRITE_NCB(x)  __xbig__(x)
#   else//LITTLE_ENDIAN
#       define CSM_READ_NCB(x)   (x)
#       define CSM_WRITE_NCB(x)  (x)
#   endif//LITTLE_ENDIAN
#endif//WSG_USING_NTOH

#define CSM_NARG(...)           CSM_ARG_N(__VA_ARGS__)
#define CSM_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9,_10,                       \
                  _11,_12,_13,_14,_15,_16,_17,_18,_19,_20,                      \
                  _21,_22,_23,_24,_25,_26,_27,_28,_29,_30,                      \
                  _31,_32,_33,_34,_35,_36,_37,_38,_39,_40,                      \
                  _41,_42,_43,_44,_45,_46,_47,_48,_49,_50,                      \
                  _51,_52,_53,_54,_55,_56,_57,_58,_59,_60,                      \
                  _61,_62,_63,N,...)                                            \
                                N
#define CSM_N_SEQ()             63,62,61,60,                                    \
                                59,58,57,56,55,54,53,52,51,50,                  \
                                49,48,47,46,45,44,43,42,41,40,                  \
                                39,38,37,36,35,34,33,32,31,30,                  \
                                29,28,27,26,25,24,23,22,21,20,                  \
                                19,18,17,16,15,14,13,12,11,10,                  \
                                9,8,7,6,5,4,3,2,1,0
#define __VA_ARGC__(...)        CSM_NARG(__VA_ARGS__,CSM_N_SEQ())
#define __lenof__(arr)          (sizeof(arr)/sizeof(*arr))
#define __swap__(x,y)           do{__typeof__(x) t=x;x=y;y=t;}while(0)
#define __offset__(cls,var)     ((long)&(((cls*)0)->var))
#define __cntnr__(cls,var,addr) ((cls*)((addr)-__offset__(cls, var)))

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#include "type.h"
#include "algorithm.h"
#include "card.h"
#include "interact.hpp"
#include "fsm.hpp"
#include "skill.h"
#include "hero.h"
#include "player.h"
#include "wound.hpp"
#include "game.hpp"

#endif /* defined(__WSG__H__) */