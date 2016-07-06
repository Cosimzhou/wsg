//
//  card.c
//  wsg
//
//  Created by cosim on 15/6/15.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//

#include "card.h"
#include <time.h>

#define KP_SET_CARDS            (13*4)
#define KP_SET_NUM              3
#define KP_SETCARD_NUM          (KP_SET_NUM*KP_SET_CARDS)
#define KP_TOTAL_NUM            (KP_SETCARD_NUM + 4)

WSG_BEGIN

/* wsg_cards_lib
其中记录了一套牌中常规的156张卡牌的点数和牌面的数据,其中104张标准包常规牌.
后52张为军征包卡牌
以下数据中,每行4张,分别以方片,梅花, 红桃, 黑桃的顺序排列
各行均是以A2345678910JQK的顺序排列, 便于以下标进行点数比较
*/
//    方片, 梅花, 红桃, 黑桃
const card_function_id_t wsg_cards_lib[KP_SETCARD_NUM] = {
KP_ZHUGELIANNU, KP_ZHUGELIANNU, KP_TAOYUANJIEYI, KP_SHANDIAN,               //A
KP_SHAN, KP_BAGUAZHEN, KP_SHAN, KP_BAGUAZHEN,                               //2
KP_SHAN, KP_GUOHECHAIQIAO, KP_TAO, KP_GUOHECHAIQIAO,                        //3
KP_SHAN, KP_GUOHECHAIQIAO, KP_TAO, KP_GUOHECHAIQIAO,                        //4
KP_SHAN, KP_DILU, KP_QILINGONG, KP_QINGLONGYANYUEDAO,                       //5
KP_SHAN, KP_LEBUSISHU, KP_TAO, KP_LEBUSISHU,                                //6
KP_SHAN, KP_NANMANRUQIN, KP_TAO, KP_NANMANRUQIN,                            //7
KP_SHAN, KP_SHA, KP_TAO, KP_SHA,                                            //8
KP_SHAN, KP_SHA, KP_TAO, KP_SHA,                                            //9
KP_SHAN, KP_SHA, KP_SHA, KP_SHA,                                            //10
KP_SHAN, KP_SHA, KP_SHA, KP_WUXIEKEJI,                                      //J
KP_TAO, KP_JIEDAOSHAREN, KP_TAO, KP_ZHANGBASHEMAO,                          //Q
KP_SHA, KP_JIEDAOSHAREN, KP_ZHAOHUANGFEIDAIN, KP_DAWAN,                     //K
////////////////////////////////////////////////////////////////////////////////
KP_JUEDOU, KP_JUEDOU, KP_WANJIANQIFA, KP_JUEDOU,                            //A
KP_SHAN, KP_SHA, KP_SHAN, KP_CIXIONGSHUANGGUJIAN,                           //2
KP_SHUNSHOUQIANYANG, KP_SHA,KP_WUGUFENGDENG, KP_SHUNSHOUQIANYANG,           //3
KP_SHUNSHOUQIANYANG, KP_SHA,KP_WUGUFENGDENG, KP_SHUNSHOUQIANYANG,           //4
KP_GUANSHIFU, KP_SHA, KP_CHITU, KP_JUEYING,                                 //5
KP_SHA, KP_SHA, KP_LEBUSISHU, KP_QINGGANGJIAN,                              //6
KP_SHA, KP_SHA, KP_WUZHONGSHENGYOU, KP_SHA,                                 //7
KP_SHA, KP_SHA, KP_WUZHONGSHENGYOU, KP_SHA,                                 //8
KP_SHA, KP_SHA, KP_WUZHONGSHENGYOU, KP_SHA,                                 //9
KP_SHA, KP_SHA, KP_SHA, KP_SHA,                                             //10
KP_SHAN, KP_SHA, KP_WUZHONGSHENGYOU, KP_SHUNSHOUQIANYANG,                   //J
KP_FANGTIANHUAJI, KP_WUZHONGSHENGYOU, KP_GUOHECHAIQIAO, KP_GUOHECHAIQIAO,   //Q
KP_ZIXING, KP_WUXIEKEJI, KP_SHAN, KP_NANMANRUQIN,                           //K
////////////////////////////////////////////////////////////////////////////////
KP_ZHUQUEYUSHAN, KP_BAIYINSHIZI, KP_WUXIEKEJI, KP_GUDINGDAO,                //A
KP_TAO, KP_TENGJIA, KP_HUOGONG, KP_TENGJIA,                                 //2
KP_TAO, KP_JIU, KP_HUOGONG, KP_JIU,                                         //3
KP_HUOSHA, KP_BINGLIANGCUNDUAN, KP_HUOSHA, KP_LEISHA,                       //4
KP_HUOSHA, KP_LEISHA, KP_TAO, KP_LEISHA,                                    //5
KP_SHAN, KP_LEISHA, KP_TAO, KP_LEISHA,                                      //6
KP_SHAN, KP_LEISHA, KP_HUOSHA, KP_LEISHA,                                   //7
KP_SHAN, KP_LEISHA, KP_SHAN, KP_LEISHA,                                     //8
KP_JIU, KP_JIU, KP_SHAN, KP_JIU,                                            //9
KP_SHAN, KP_TIESUOLIANHUAN, KP_HUOSHA, KP_BINGLIANGCUNDUAN,                 //10
KP_SHAN, KP_TIESUOLIANHUAN, KP_SHAN, KP_TIESUOLIANHUAN,                     //J
KP_HUOGONG, KP_TIESUOLIANHUAN, KP_SHAN, KP_TIESUOLIANHUAN,                  //Q
KP_HUALIU, KP_TIESUOLIANHUAN, KP_WUXIEKEJI, KP_WUXIEKEJI,                   //K
////////////////////////////////////////////////////////////////////////////////
};

const card_info_t wsg_cards_data_lib[] = {
//基本牌
{KP_SHA, "杀", "【杀】\n出牌时机：出牌阶段\n使用目标：除你外，你攻击范围内的一名角色\n作用效果：【杀】对目标角色造成1点伤害"},
{KP_HUOSHA, "火杀", "【火杀】\n出牌时机：出牌阶段\n使用目标：除你外，你攻击范围内的一名角色\n作用效果：【杀】对目标角色造成1点火属性伤害"},
{KP_LEISHA, "雷杀", "【雷杀】\n出牌时机：出牌阶段\n使用目标：除你外，你攻击范围内的一名角色\n作用效果：【杀】对目标角色造成1点雷属性伤害"},
{KP_SHAN ,"闪", "【闪】\n出牌时机：以你为目标的【杀】开始结算时\n使用目标：以你为目标的【杀】\n作用效果：抵消目标【杀】的效果"},
{KP_TAO, "桃", "【桃】\n出牌时机：1、出牌阶段。2、有角色处于濒死状态时\n使用目标：1、你。2、处于濒死状态的一名角色\n作用效果：目标角色回复1点体力"},
{KP_JIU, "酒", "【酒】\n出牌阶段，对自己使用，令自己的下一张使用的【杀】造成的伤害+1（每回合限使用1次）；任何时候，当自己进入濒死阶段时，对自己使用，立即回复1点体力值"},
    
//锦囊牌
{KP_SHUNSHOUQIANYANG, "顺手牵羊", "【顺手牵羊】\n出牌时机：出牌阶段。\n使用目标：除你以外，与你距离1以内的一名角色。\n作用效果：你选择并获得目标角色手牌（随机选择）、装备区或判定区里的一张牌"},
{KP_GUOHECHAIQIAO, "过河拆桥", "【过河拆桥】\n出牌时机：出牌阶段。\n使用目标：除你以外，任意一名角色。\n作用效果：你选择并弃掉目标角色手牌（随机选择）、装备区或判定区里的一张牌"},
{KP_JIEDAOSHAREN, "借刀杀人", "【借刀杀人】\n出牌时机：出牌阶段。\n使用目标：除你以外，装备区里有武器牌的一名角色A。（你需要在此阶段选择另一个A使用【杀】能攻击到的角色B）。\n作用效果：A需对B使用一张【杀】，否则A必须将其装备的武器牌交给你"},
{KP_JUEDOU, "决斗", "【决斗】\n出牌时机：出牌阶段\n使用目标：除你以外，任意一名角色\n作用效果：由目标角色先开始，你和他（她）轮流打出一张【杀】，【决斗】对首先不出【杀】的一方造成1点伤害；另一方成为此伤害的来源"},
{KP_WANJIANQIFA, "万箭齐发", "【万箭齐发】\n出牌时机：出牌阶段。\n使用目标：除你以外的所有角色。\n作用效果：按行动顺序结算，除非目标角色打出1张【闪】，否则该角色受到【万箭齐发】对其造成的1点伤害"},
{KP_NANMANRUQIN, "南蛮入侵", "【南蛮入侵】\n出牌时机：出牌阶段。\n使用目标：除你以外的所有角色。\n作用效果：按行动顺序结算，除非目标角色打出1张【杀】，否则该角色受到【南蛮入侵】对其造成的1点伤害"},
{KP_TAOYUANJIEYI, "桃园结义", "【桃园结义】\n出牌时机：出牌阶段。\n使用目标：所有角色。\n作用效果：按行动顺序结算，目标角色回复1点体力"},
{KP_WUGUFENGDENG, "五谷丰登", "【五谷丰登】\n出牌时机：出牌阶段。\n使用目标：所有角色。\n作用效果：按你从牌堆顶亮出等同于现存角色数量的牌，然后按行动顺序结算，目标角色选择并获得这些牌中的一张"},
{KP_WUZHONGSHENGYOU, "无中生有", "【无中生有】\n出牌时机：出牌阶段。\n使用目标：你\n作用效果：摸两张牌"},
{KP_WUXIEKEJI, "无懈可击", "【无懈可击】\n出牌时机：目标锦囊对目标角色生效前。\n使用目标：目标锦囊。\n作用效果：抵消该锦囊对其指定的一名目标角色产生的效果"},
{KP_HUOGONG, "火攻", "【火攻】\n出牌阶段，对任一有手牌的角色使用。目标角色展示1张手牌，若你弃置1张与之相同花色的手牌，则你对目标角色造成1点火焰伤害"},
{KP_TIESUOLIANHUAN, "铁锁连环", "【铁索连环】\n连环，出牌阶段使用，选择1至2个角色，分别横置或重置这些角色。处于“连环状态”。重铸，出牌阶段，你可以从手里弃掉这张牌，然后摸1张牌"},
//延时类锦囊牌
{KP_LEBUSISHU, "乐不思蜀", "【乐不思蜀】\n出牌时机：出牌阶段。\n使用目标：除你以外，任意一名角色。\n作用效果：将【乐不思蜀】横置于目标角色判定区里，目标角色回合判定阶段，进行判定；若判定结果不为红桃，则跳过目标角色的出牌结算，将【乐不思蜀】弃置"},
{KP_SHANDIAN, "闪电", "【闪电】\n出牌时机：出牌阶段。\n使用目标：你。\n作用效果：将【闪电】横置于目标角色判定区里，目标角色回合判定阶段，进行判定；若判定结果为黑桃2-9之间（包括黑桃2和9），则【闪电】对目标角色造成3点雷属性伤害，将闪电弃置。若判定结果不为黑桃2-9之间（包括黑桃2和9），将【闪电】移动到当前目标角色下家（【闪电】的目标变为该角色）的判定区"},
{KP_BINGLIANGCUNDUAN, "兵粮寸断", "【兵粮寸断】\n出牌阶段，对除你以外，与你距离为1以内的角色使用（横置于该角色的判定区内）若其判定的结果不为梅花，则跳过该角色的摸牌阶段"},
    
//装备牌
//武器
{KP_ZHUGELIANNU, "诸葛连弩", "【诸葛连弩】\n攻击范围：１\n武器特效：出牌阶段，你可以使用任意张【杀】", 1},
{KP_QINGGANGJIAN, "青釭剑", "【青釭剑】\n攻击范围：２\n武器特效：锁定技，每当你使用【杀】时，无视目标角色的防具", 2},
{KP_CIXIONGSHUANGGUJIAN, "雌雄双股剑", "【雌雄双股剑】\n攻击范围：２\n武器特效：你使用【杀】时，指定了一名异性角色后，在【杀】结算前，你可以令对方选择一项：自己弃一张手牌或者让你从牌堆摸一张牌", 2},
{KP_QINGLONGYANYUEDAO, "青龙偃月刀", "【青龙偃月刀】\n攻击范围：３\n武器特效：当你使用的【杀】被【闪】抵消时，你可以立即对相同的目标再使用一张【杀】直到【杀】生效或你不愿意出了为止", 3},
{KP_FANGTIANHUAJI, "方天画戟", "【方天画戟】\n攻击范围：４\n武器特效：当你使用的【杀】是你的最后一张手牌时，你可以为这张【杀】指定至多三名目标角色，然后按行动顺序依次结算之", 4},
{KP_GUANSHIFU, "贯石斧", "【贯石斧】\n攻击范围：３\n武器特效：目标角色使用【闪】抵消你使用【杀】的效果时，你可以弃两张牌，则【杀】依然造成伤害", 3},
{KP_ZHANGBASHEMAO, "丈八蛇矛", "【丈八蛇矛】\n攻击范围：３\n武器特效：当你需要使用（或打出）一张【杀】时，你可以将两张手牌当一张【杀】使用（或打出）", 3},
{KP_QILINGONG, "麒麟弓", "【麒麟弓】\n攻击范围：５\n武器特效：你使用【杀】对目标角色造成伤害时，你可以将其装备区里的一匹马弃置", 5},
{KP_HANBINGJIAN, "寒冰剑", "【寒冰剑】\n攻击范围：２\n武器特效：当你使用【杀】造成伤害时，你可以防止此伤害，改为弃置该目标角色的两张牌（弃完第一张再弃第二张）", 2},
{KP_GUDINGDAO, "古锭刀", "【古锭刀】\n攻击范围：２\n武器特效：锁定技，当你使用的【杀】造成伤害时，若指定目标没有手牌，则该伤害+1", 2},
{KP_ZHUQUEYUSHAN, "朱雀羽扇", "【朱雀羽扇】\n攻击范围：４\n武器特效：你可以将你的任一普通杀当作具火焰伤害的杀来使用", 4},
{KP_YINYUEQIANG, "银月枪", "【银月枪】\n攻击范围：3\n武器特效：你的回合外，每当你使用或打出了一张黑色手牌（若为使用则在它结算之前），你可以立即对你攻击范围内的任意一名角色使用一张【杀】", 3},
//防具
{KP_BAGUAZHEN, "八卦阵", "【八卦阵】\n防具效果：每当你需要使用（或打出）一张【闪】时，你可以进行一次判定：若结果为红色，则视为你使用（或打出）了一张【闪】；若为黑色，则你仍可从手牌里使用（或打出）。 ★由八卦使用或打出的【闪】，并非从你的手牌中使用或打出"},
{KP_RENWANGDUN, "仁王盾", "【仁王盾】\n防具效果：锁定技，黑色的【杀】对你无效"},
{KP_TENGJIA, "藤甲", "【藤甲】\n锁定技，南蛮入侵、万箭齐发和普通杀对你无效。每次受到火焰伤害时，该伤害+1"},
{KP_BAIYINSHIZI, "白银狮子", "【白银狮子】\n锁定技，每次你受到伤害时，最多承受1点伤害（防止多余的伤害）；当你失去装备区里的白银狮子时，你回复1点体力值"},
//坐骑
//+1
{KP_DILU, "的卢", "【的卢】\n其他角色计算与你的距离时，始终+1。"},
{KP_HUALIU, "骅骝", "【骅骝】\n其他角色计算与你的距离时，始终+1。"},
{KP_JUEYING, "绝影", "【绝影】\n其他角色计算与你的距离时，始终+1。"},
{KP_ZHAOHUANGFEIDAIN, "爪黄飞电", "【爪黄飞电】\n其他角色计算与你的距离时，始终+1。"},
//-1
{KP_CHITU, "赤兔", "【赤兔】\n你计算与其他角色的距离时，始终-1。"},
{KP_DAWAN, "大宛", "【大宛】\n你计算与其他角色的距离时，始终-1。"},
{KP_ZIXING, "紫骍", "【紫骍】\n你计算与其他角色的距离时，始终-1。"}
};

//    wsg_exend_cards
// 其中记录了标准包中的4张拓展牌点和牌面的关系
//
const card_lib_extend_t wsg_exend_cards[4] = {
    {POKER(CP_DIAMOND, CP_QUEEN), KP_WUXIEKEJI},     //方片Q 无懈可击
    {POKER(CP_CLUB, CP_2), KP_RENWANGDUN},            //梅花2 仁王盾
    {POKER(CP_HEART, CP_QUEEN), KP_SHANDIAN},     //红桃Q 闪电
    {POKER(CP_SAPDE, CP_2), KP_HANBINGJIAN}        //黑桃2 寒冰剑
};

const char* wsg_card_pattern_list[] = {
//    "♦︎","♣︎","♥︎","♠︎","🀆"
//    "♢","♧","♡","♤","🀆"
    "♢","♣︎","♡","♠︎","🀆"
};
const char* wsg_card_point_list[] = {
    "A","2","3","4","5","6","7","8","9","10","J","Q","K","0"
};
/////////////////////////////////////////////////////////
//      inner funcitons
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////

inline card_function_id_t
wsg_card_get_function_by_id(card_id_t idx) {
    if (0 <= idx && idx < KP_TOTAL_NUM) {
        if (KP_SETCARD_NUM <= idx) {
            return wsg_exend_cards[idx-KP_SETCARD_NUM].func;
        }
        return wsg_cards_lib[idx];
    }
    return KP_NONE;
}

inline card_pattern_t
wsg_card_get_pattern_by_id(card_id_t idx) {
    if (0 <= idx && idx < KP_TOTAL_NUM)
        return idx % 4;
    return 4;
}

inline card_point_t
wsg_card_get_point_by_id(card_id_t idx) {
    if (0 <= idx && idx < KP_TOTAL_NUM) {
        if (KP_SETCARD_NUM <= idx) {
            return POKER_PNT(wsg_exend_cards[idx-KP_SETCARD_NUM].pattern);
        }
        return POKER_PNT(idx)%13;
    }
    return 13;
}

inline void
wsg_card_get_fpn_by_id(card_id_t idx, card_function_id_t &cfi, card_pattern_t &cp, card_point_t &cpn) {
    if (0 <= idx && idx < KP_TOTAL_NUM) {
        cp = POKER_PAT(idx);
        if (KP_SETCARD_NUM <= idx) {
            cfi = wsg_exend_cards[idx-KP_SETCARD_NUM].func;
            cpn = POKER_PNT(wsg_exend_cards[idx-KP_SETCARD_NUM].pattern);
        } else {
            cfi = wsg_cards_lib[idx];
            cpn = POKER_PNT(idx)%13;
        }
    } else {
        cp = 4;
        cpn = 13;
        cfi = KP_NONE;
    }
}

IMP_FIND_ARRAY_FUNC(card_info_t, wsg_card_get_info_by_cfid, card_function_id_t, wsg_cards_data_lib, id);



void wsg_card_test_show() {
    
    CardHeap ch;
    for (card_id_t i = 0; i < KP_TOTAL_NUM; ++i)
        ch<<i;
    ch.shuffle();
    
    for (auto chi = ch.begin(); chi != ch.end(); ++chi)
        cout<<Card::cardinfo(*chi)<<endl;
    return;

    card_function_id_t cfi;
    card_point_t cpn;
    card_pattern_t cp;
    for (card_id_t i = 0; i < KP_TOTAL_NUM; ++i) {
        wsg_card_get_fpn_by_id(i, cfi, cp, cpn);
        const card_info_t *pci = wsg_card_get_info_by_cfid(cfi);
        if (!pci) {
            cout<<cfi<<","<<i<<endl;
            return;
        }
        cout<<wsg_card_pattern_list[cp]
                 <<wsg_card_point_list[cpn]
                 <<"【"<<pci->name<<"】"<<endl;
    }
}

/*******************************************************
 *      card heap related functions
 *******************************************************/
#define _IS_INVALID_CARDHEAP(ch)                                                    \
    (NULL != ch && NULL != ch->cards && NULL != ch->top && NULL != ch->tail && ch->size >= 108 &&     \
     ch->top >= ch->cards && ch->tail >= ch->cards && ch->cards > ch->top-ch->size &&   \
     ch->tail >= ch->cards && ch->cards >= ch->tail-ch->size)
#define _IS_FULL_CARDHEAP(ch)                                                       \
    ((ch->tail + 1 == ch->top) || (ch->top == ch->cards && ch->tail + 1 == ch->top + ch->size))
#define _IS_EMPTY_CARDHEAP(ch)                                                      \
    (ch->top == ch->tail)
#define _END_OF_CARDHEAP(ch)                                                        \
    (ch->cards + ch->size)

CardHeap::~CardHeap() {
    list<card_id_t>::~list<card_id_t>();
}

void CardHeap::shuffle() {
    vector<card_id_t> buff;
    buff.assign(size(), ((card_id_t)0));
    copy(begin(), end(), buff.begin());
    for (size_t i = 0, j; i < buff.size(); ++i) {
        j = rand()%buff.size();
        __swap__(buff[i], buff[j]);
    }
    copy(buff.begin(), buff.end(), begin());
}


/*******************************************************
 *      card related functions
 *******************************************************/
string Card::cardinfo(card_id_t i) {
    card_function_id_t cfi;
    card_point_t cpn;
    card_pattern_t cp;

    wsg_card_get_fpn_by_id(i, cfi, cp, cpn);
    const card_info_t *pci = wsg_card_get_info_by_cfid(cfi);
    if (!pci) {
        return string("<null>");
    }
    
    stringstream sstr;
    sstr<<wsg_card_pattern_list[cp]<<wsg_card_point_list[cpn]<<"【"<<pci->name<<"】";
    
    return sstr.str();
}

//int
//sgs_card_get_info_by_id(card_id_t idx, card_instance_info_t *info) {
//    if (info == NULL)
//        return ERR_NO_SPACE;
//    info->id = sgs_card_get_function_by_id(idx);
//    if (info->id == KP_NONE)
//        return ERR_UNKNOWN_CARD;
//
//    find_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
//    
//    bool isFound = 0;
//    for (int i = 0; i < csm_lenof(sgs_cards_data_lib); ++i) {
//        if (sgs_cards_data_lib[i].id == info->id) {
//            *(card_info*)info = sgs_cards_data_lib[i];
//            isFound = 1;
//            break;
//        }
//    }
//    
//    if (!isFound)
//        return ERR_UNKNOWN_CARD;
//    
//    info->dot = (idx % KP_SET_CARDS) >> 2;
//    info->pattern = idx % 4;
//    return ERR_SUCCESS;
//}

WSG_END