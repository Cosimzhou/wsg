//
//  type.h
//  wsg
//
//  Created by cosim on 16/7/6.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//
#include "wsg.h"
#ifndef __WSG__TYPE__H__
#define __WSG__TYPE__H__

WSG_BEGIN

typedef int player_index_t;
typedef int card_id_t;

#ifdef WSG_USING_CHAR_AS_ENUM
typedef     unsigned char       card_pattern_t;
typedef     unsigned char       card_point_t;
typedef     unsigned char       property_type_t;
typedef     unsigned char       card_type_t;
#endif// WSG_USING_CHAR_AS_ENUM


WSG_END
#endif /* defined(__WSG__TYPE__H__) */