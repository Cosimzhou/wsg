//
//  hero.h
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "wsg.h"

#ifndef __WSG__HERO__H__
#define __WSG__HERO__H__


#include <vector>

WSG_BEGIN

// 武将ID宏标签定义
// 注意：这里的枚举与武将原型数组里的定义顺序是一致的，即可以用作其下标
typedef enum {
// 群雄武将
    HERO_NONE,
    QUN001,        //华佗
    QUN002,        //吕布
    QUN003,        //貂蝉
    QUN004,        //袁绍
    QUN005,        //颜良&文丑
    QUN006,        //董卓
    QUN007,        //贾诩
    QUN008,        //庞德
    QUN009,        //左慈
    QUN010,        //张角
    QUN011,        //于吉
    QUN012,        //蔡文姬
// 魏将
    WEI001,      //曹操
    WEI002,      //司马懿
    WEI003,      //夏侯惇
    WEI004,      //张辽
    WEI005,      //许褚
    WEI006,      //郭嘉
    WEI007,      //甄姬
    WEI008,      //夏侯渊
    WEI009,      //张郃
    WEI010,      //徐晃
    WEI011,      //曹仁
    WEI012,      //典韦
    WEI013,      //荀彧
    WEI014,      //曹丕
    WEI015,      //邓艾
// 蜀将
    SHU001,      //刘备
    SHU002,      //关羽
    SHU003,      //张飞
    SHU004,      //诸葛亮
    SHU005,      //赵云
    SHU006,      //马超
    SHU007,      //黄月英
    SHU008,      //黄忠
    SHU009,      //魏延
    SHU010,      //庞统
    SHU011,      //火诸葛亮
    SHU012,      //姜维
    SHU013,      //刘禅
    SHU014,      //孟获
    SHU015,      //祝融
// 吴将
    WU001,      //孙权
    WU002,      //甘宁
    WU003,      //吕蒙
    WU004,      //黄盖
    WU005,      //周瑜
    WU006,      //大乔
    WU007,      //陆逊
    WU008,      //孙尚香
    WU009,      //孙坚
    WU010,      //孙策
    WU011,      //小乔
    WU012,      //太史慈
    WU013,      //周泰
    WU014,      //鲁肃
    WU015,      //张昭&张纮

// 神将篇
    LE001,      //神关羽
    LE002,      //神吕蒙
    LE003,      //神周瑜
    LE004,      //神诸葛亮
    LE005,      //神曹操
    LE006,      //神吕布
    LE007,      //神赵云
    LE008,      //神司马懿

//一将成名篇
    YJ001,      //曹植
    YJ002,      //陈宫
    YJ003,      //法正
    YJ004,      //高顺
    YJ005,      //凌统
    YJ006,      //马谡
    YJ007,      //吴国太
    YJ008,      //徐盛
    YJ009,      //徐庶
    YJ010,      //于禁
    YJ011,      //张春华
    YJ012,      //钟会

// 一将成名篇 1
    YJ101,      //步练师
    YJ102,      //曹彰
    YJ103,      //程普
    YJ104,      //关兴&张苞
    YJ105,      //韩当
    YJ106,      //华雄
    YJ107,      //廖化
    YJ108,      //刘表
    YJ109,      //马岱
    YJ110,      //王异
    YJ111,      //荀攸

// 一将成名篇 2
    YJ201,      //曹冲
    YJ202,      //伏皇后
    YJ203,      //关平
    YJ204,      //郭淮
    YJ205,      //简雍
    YJ206,      //李儒
    YJ207,      //刘封
    YJ208,      //满宠
    YJ209,      //潘璋&马忠
    YJ210,      //虞翻
    YJ211,      //朱然


// SP 篇 1
    SP001,
    SP002,
    SP003,
    SP004,
    SP005,
    SP006,
    SP007,
    SP008_1,
    SP008_2,
    SP009,
    SP010,
    SP011,
    SP012,
    SP021,

// SP 篇 2
    XSP001,
    XSP002,
    XSP003,
    XSP004,
    XSP005,
    XSP006,

// VS 篇
    VS001,

// 太阳能三国杀拓展篇
    TYN001,
} hero_id_t;

typedef enum {
    SL_NONE,
    SL_AMBITIONIST,
    SL_QUN,
    SL_SHU,
    SL_WEI,
    SL_WU,
    SL_GOD,
} country_id_t;

typedef enum {
    FX_NONE             = 0,
    FX_NORMAL           = (1<<0),
    FX_WIND             = (1<<1),
    FX_FIRE             = (1<<2),
    FX_FOREST           = (1<<3),
    FX_MOUNT            = (1<<4),
    FX_GENERAL1         = (1<<5),
    FX_GENERAL2         = (1<<6),
    FX_GENERAL3         = (1<<7),
    FX_RACE             = (1<<8),
    FX_DESKTOP          = (1<<9),
    FX_TOP_NUM
} package_mark_t;

typedef struct {
    hero_id_t id;
    const char *name;
    bool male;
    int blood;
    country_id_t country;
    skill_id_t skills[16];
    const char *fame;
    const char *nick;
    package_mark_t package;
} hero_model_t;


class Hero {
public:
    Hero();
    ~Hero();

    static Hero* getHeroByID(hero_id_t);
    static Hero* getHeroesByID(hero_id_t);
    static vector<string>* getHeroNamesByPackageID(package_mark_t);
};


extern void
test();



WSG_END;
#endif /* defined(__WSG__HERO__H__) */
