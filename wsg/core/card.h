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

#define WSG_USING_CHAR_AS_ENUM

#define POKER(h, d)     (h+(d<<2))

typedef int card_id_t;

#ifdef WSG_USING_CHAR_AS_ENUM
typedef unsigned char card_pattern_t;

#   define CP_DIAMOND       ((card_pattern_t)0)
#   define CP_CLUB          ((card_pattern_t)1)
#   define CP_HEART         ((card_pattern_t)2)
#   define CP_SAPDE         ((card_pattern_t)3)

typedef unsigned char card_point_t;

#   define CP_ACE           ((card_point_t)0)
#   define CP_2             ((card_point_t)1)
#   define CP_3             ((card_point_t)2)
#   define CP_4             ((card_point_t)3)
#   define CP_5             ((card_point_t)4)
#   define CP_6             ((card_point_t)5)
#   define CP_7             ((card_point_t)6)
#   define CP_8             ((card_point_t)7)
#   define CP_9             ((card_point_t)8)
#   define CP_10            ((card_point_t)9)
#   define CP_JACK          ((card_point_t)10)
#   define CP_QUEEN         ((card_point_t)11)
#   define CP_KING          ((card_point_t)12)


typedef unsigned char property_type_t;

#   define PT_NONE          ((property_type_t)0)
#   define PT_LIGHTNING     ((property_type_t)1)
#   define PT_FIRE          ((property_type_t)2)


typedef unsigned char card_type_t;

#   define CT_NONE          ((card_type_t)0)
#   define CT_BASIC         ((card_type_t)1)
#   define CT_EQUIPMENT     ((card_type_t)2)
#   define CT_SMART         ((card_type_t)3)


#else //defined(WSG_USING_CHAR_AS_ENUM)
typedef enum {
    CP_DIAMOND,
    CP_CLUB,
    CP_HEART,
    CP_SAPDE,
} card_pattern_t;

typedef enum {
    CP_ACE,
    CP_2,
    CP_3,
    CP_4,
    CP_5,
    CP_6,
    CP_7,
    CP_8,
    CP_9,
    CP_10,
    CP_JACK,
    CP_QUEEN,
    CP_KING,
} card_point_t;

typedef enum {
    PT_NONE,
    PT_LIGHTNING,
    PT_FIRE,
} property_type_t;

typedef enum {
    CT_NONE,
    CT_BASIC,
    CT_EQUIPMENT,
    CT_SMART,
} card_type_t;

#endif //defined(WSG_USING_CHAR_AS_ENUM)

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

    
    
class CardHeap: std::list<card_id_t> {
public:
    
    CardHeap& operator<<(card_id_t cardid) {
        this->push_back(cardid);
        return *this;
    }
    
    CardHeap& operator>>(card_id_t &cardid) {
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
    Card(card_id_t);
    
//    static void cardinfo(card_id_t, card_instance_info_t &cii);

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
//sgs_card_heap_pop_card(card_heap *card_heap, card_id_t *card);
//extern errcode
//sgs_card_heap_push_card(card_heap *card_heap, card_id_t card);
//extern errcode
//sgs_card_heap_tail_card(card_heap *card_heap, card_id_t card);
//extern errcode
//sgs_card_heap_copy(card_heap *card_heap, const card_heap *source_heap);
//extern errcode
//sgs_card_heap_shuffle(const card_heap *card_heap);
//extern errcode
//sgs_card_heap_count_card(const card_heap *card_heap, int *count);



//extern errcode
//sgs_card_get_info_by_id(card_id_t idx, card_instance_info_t *info);
//
//extern card_function_id
//sgs_card_get_function_by_id(card_id_t idx);

    
WSG_END;
#endif /* defined(__WSG__CARD__H__) */