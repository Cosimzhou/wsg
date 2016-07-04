//
//  interact.hpp
//  wsg
//
//  Created by 周志超 on 16/6/29.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__INTERACT__H__
#define __WSG__INTERACT__H__


class interact {
    int timeout;
    
    bool hintAct(void *);
    void getAction(void *);
};

#endif /* __WSG__INTERACT__H__ */
