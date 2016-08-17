//
//  wsg-util.h
//  wsg
//
//  Created by 周志超 on 16/8/17.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG_UTIL_H__
#define __WSG_UTIL_H__

WSG_BEGIN

#define SPACE(s)                (wsg_spaces+strlen(wsg_spaces)-(s))

extern const char *wsg_spaces;

WSG_END
#endif /* __WSG_UTIL_H__ */