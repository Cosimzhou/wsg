//
//  error.h
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#ifndef __sgs__error__
#define __sgs__error__

//#include <stdio.h>

//#include "../../../utils/util.h"

#include "types.h"

typedef enum {
    ERR_SUCCESS = 0,
    ERR_NOT_READY,
    ERR_NO_SPACE,
    ERR_DATA_OVERWRITTEN,
    ERR_EODU_HERO,
    ERR_CARD_HEAP_EMPTY,
    ERR_CARD_HEAP_FULL,
    ERR_UNKNOWN_COURSE,
    ERR_UNKNOWN_CARD,
} errcode;

extern const char *
sgs_error_get_infotext(errcode errcode);

#endif /* defined(__sgs__error__) */
