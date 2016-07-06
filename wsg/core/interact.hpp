//
//  interact.hpp
//  wsg
//
//  Created by cosim on 16/6/29.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__INTERACT__H__
#define __WSG__INTERACT__H__


class interact {
    int timeout;
    
    bool hintAct(void *);
    void getAction(void *);
};

#endif /* defined(__WSG__INTERACT__H__) */