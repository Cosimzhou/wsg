//
//  card.h
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__CARD__H__
#define __WSG__CARD__H__

#include <list>

WSG_BEGIN


#define POKER(h, d)     (h+(d<<2))

typedef int card_id;

typedef enum {
    HS_DIAMOND,
    HS_CLUB,
    HS_HEART,
    HS_SAPDE,
} card_pattern_t;

typedef enum {
    DS_ACE,
    DS_2,
    DS_3,
    DS_4,
    DS_5,
    DS_6,
    DS_7,
    DS_8,
    DS_9,
    DS_10,
    DS_JACK,
    DS_QUEEN,
    DS_KING,
} card_point_t;

typedef enum {
    KP_NONE =                0x0000,  //空，非法牌
    KP_UNKNOWN,
    //攻击
    KP_JIBEN_BEGIN,
    KP_SHA = KP_JIBEN_BEGIN,
    KP_HUOSHA,
    KP_LEISHA,
    KP_ALLSHA,
    //防守
    KP_SHAN,
    //其它
    KP_TAO,
    KP_JIU,
    KP_JIBEN_END = KP_JIU,
    
    //锦囊牌
    KP_JINNANG_BEGIN = 0x0011,
    //非延时类锦囊
    KP_JINNANG_FEIYANCHI_BEGIN = KP_JINNANG_BEGIN,
    KP_SHUNSHOUQIANYANG = KP_JINNANG_BEGIN,
    KP_GUOHECHAIQIAO,
    KP_JIEDAOSHAREN,
    KP_JUEDOU,
    KP_WANJIANQIFA,
    KP_NANMANRUQIN,
    KP_TAOYUANJIEYI,
    KP_WUGUFENGDENG,
    KP_WUZHONGSHENGYOU,
    KP_WUXIEKEJI,
    KP_HUOGONG,
    KP_TIESUOLIANHUAN,
    KP_JINNANG_FEIYANCHI_END = KP_TIESUOLIANHUAN,
    //延时类锦囊
    KP_JINNANG_YANCHI_BEGIN = 0x0031,
    KP_LEBUSISHU = KP_JINNANG_YANCHI_BEGIN,
    KP_SHANDIAN,
    KP_BINGLIANGCUNDUAN,
    KP_JINNANG_YANCHI_END = KP_BINGLIANGCUNDUAN,
    KP_JINNANG_END = KP_JINNANG_YANCHI_END,
    
    //装备牌
    //武器
    KP_ZHUANGBEI_BEGIN = 0x0051,
    KP_ZHUANGBEI_WUQI_BEGIN = KP_ZHUANGBEI_BEGIN,
    KP_ZHUGELIANNU = KP_ZHUANGBEI_WUQI_BEGIN,
    KP_QINGGANGJIAN,
    KP_CIXIONGSHUANGGUJIAN,
    KP_QINGLONGYANYUEDAO,
    KP_FANGTIANHUAJI,
    KP_GUANSHIFU,
    KP_ZHANGBASHEMAO,
    KP_QILINGONG,
    KP_HANBINGJIAN,
    KP_GUDINGDAO,
    KP_ZHUQUEYUSHAN,
    KP_YINYUEQIANG,
    KP_ZHUANGBEI_WUQI_END = KP_YINYUEQIANG,
    //防具
    KP_ZHUANGBEI_FANGJU_BEGIN = 0x0081,
    KP_BAGUAZHEN = KP_ZHUANGBEI_FANGJU_BEGIN,
    KP_RENWANGDUN,
    KP_TENGJIA,
    KP_BAIYINSHIZI,
    KP_ZHUANGBEI_FANGJU_END = KP_BAIYINSHIZI,
    
    //坐骑
    KP_ZHUANGBEI_ZUOJI_BEGIN = 0x00a1,
    //+1
    KP_ZHUANGBEI_JIAYI_BEGIN = KP_ZHUANGBEI_ZUOJI_BEGIN,
    KP_DILU = KP_ZHUANGBEI_JIAYI_BEGIN,
    KP_HUALIU,
    KP_JUEYING,
    KP_ZHAOHUANGFEIDAIN,
    KP_ZHUANGBEI_JIAYI_END = KP_ZHAOHUANGFEIDAIN,
    //-1
    KP_ZHUANGBEI_JIANYI_BEGIN = 0x00c1,
    KP_CHITU = KP_ZHUANGBEI_JIANYI_BEGIN,
    KP_DAWAN,
    KP_ZIXING,
    KP_ZHUANGBEI_JIANYI_END = KP_ZIXING,
    KP_ZHUANGBEI_ZUOJI_END = KP_ZHUANGBEI_JIANYI_END,
    KP_ZHUANGBEI_END = KP_ZHUANGBEI_ZUOJI_END
} card_function_id_t;

typedef struct {
    int pattern;
    card_function_id_t func;
} card_lib_extend_t;

typedef struct {
    card_function_id_t id;
    const char *name;
    const char *description;
    int extended;
} card_info_t;

//typedef struct {
//    card_function_id_t id;
//    const char *name;
//    const char *description;
//    int extended;
//    int dot;
//    int pattern;
//} card_instance_info_t;

    
    
class CardHeap: std::list<card_id> {
public:
    
    CardHeap& operator<<(card_id cardid) {
        this->push_back(cardid);
        return *this;
    }
    
    CardHeap& operator>>(card_id &cardid) {
        if (this->empty())
            cardid = 0;
        else {
            cardid = this->front();
            this->pop_front();
        }
        return *this;
    }
    
    void shuffle();
};


class Card {
public:
    Card(card_id);
    
//    static void cardinfo(card_id, card_instance_info_t &cii);

};

typedef std::list<Card*> Cards;

//extern errcode
//sgs_card_heap_create(card_heap *card_heap);
//extern errcode
//sgs_card_heap_destroy(card_heap *card_heap);
//
//extern errcode
//sgs_card_heap_init_with_cards(card_heap *card_heap, int type);
//extern errcode
//sgs_card_heap_pop_card(card_heap *card_heap, card_id *card);
//extern errcode
//sgs_card_heap_push_card(card_heap *card_heap, card_id card);
//extern errcode
//sgs_card_heap_tail_card(card_heap *card_heap, card_id card);
//extern errcode
//sgs_card_heap_copy(card_heap *card_heap, const card_heap *source_heap);
//extern errcode
//sgs_card_heap_shuffle(const card_heap *card_heap);
//extern errcode
//sgs_card_heap_count_card(const card_heap *card_heap, int *count);



//extern errcode
//sgs_card_get_info_by_id(card_id idx, card_instance_info_t *info);
//
//extern card_function_id
//sgs_card_get_function_by_id(card_id idx);

    
WSG_END;
#endif /* defined(__WSG__CARD__H__) */
