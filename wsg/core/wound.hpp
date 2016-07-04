//
//  wound.hpp
//  wsg
//
//  Created by 周志超 on 16/7/4.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__WOUND__H__
#define __WSG__WOUND__H__

#include <vector>
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