//
//  wound.hpp
//  wsg
//
//  Created by cosim on 16/7/4.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__WOUND__H__
#define __WSG__WOUND__H__

WSG_BEGIN

class Wound {
    vector<card_id_t> source_cards;
    property_type_t property;
    player_index_t source_player;
    vector<player_index_t> target_player;
    int quantity;
};



WSG_END
#endif /* defined(__WSG__WOUND__H__) */