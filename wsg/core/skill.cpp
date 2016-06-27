//
//  skill.cpp
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "skill.h"

WSG_BEGIN


//#define FOR(f,X,...)                    f(X); FOR(f,__VA_ARGS__)

#define F(x,c)                          {FSM::x,c}
#define FZ                              F(round_play,JNT_SELF)
#define DSK(id,nm,t,des)                                                        \
    {                                                                           \
        JN_##id,                                                                \
        nm,                                                                     \
        des,                                                                    \
        (skill_type_mask_t)(JNL_NONE | (t)),                                    \
        0,                                                                      \
        __lenof__(skc_##id##_array),                                            \
        skc_##id##_array,                                                       \
        sk_##id##_is_runnable,                                                  \
        sk_##id##_run                                                           \
    }


#define DSKFUNC(id,...)                                                         \
static bool sk_##id##_is_runnable(Game &game, fsm_status_t status);             \
static void sk_##id##_run(Game &game);                                          \
const skill_chance_t skc_##id##_array[] = {__VA_ARGS__}
#define DSKFZ(id)                       DSKFUNC(id,FZ)








/* * */



DSKFUNC(NONE);
//YJ101      步练师-安恤
DSKFUNC(ANXU, FZ);

DSKFUNC(BAIYIN);          //LE008      司马懿-拜印
DSKFUNC(BAONVE);          //QUN006     董卓-[暴虐]
DSKFUNC(BAZHEN);          //SHU011     诸葛亮-八阵
DSKFUNC(BEIGE);           //QUN012     蔡文姬-悲歌
DSKFUNC(BENGHUAI);        //QUN006     董卓-崩坏
DSKFUNC(BIYUE);           //QUN003     貂蝉-闭月
DSKFUNC(BUQU);            //WU013      周泰-不屈
DSKFUNC(BUYI);            //YJ007      吴国太-补益
DSKFUNC(CHONGZHEN);       //XSP001     赵云-冲阵
DSKFUNC(CHUNLAO);         //YJ103      程普-醇醪
DSKFUNC(DAHE);            //XSP005     张飞-大喝
DSKFUNC(DANGXIAN);        //YJ107      廖化-当先
DSKFUNC(DANJI);           //SP007      关羽-单骑
DSKFUNC(DANLAO);          //SP001      杨修-啖酪
DSKFUNC(DAWU);            //LE004      诸葛亮-大雾
DSKFUNC(DIMENG);          //WU014      鲁肃-缔盟
DSKFUNC(DUANCHANG);       //QUN012     蔡文姬-断肠
DSKFUNC(DUANLIANG);       //WEI010     徐晃-断粮
DSKFUNC(ENYUAN);          //YJ003      法正-恩怨
DSKFUNC(FANGQUAN);        //SHU013     刘禅-放权
DSKFUNC(FANJIAN);         //WU005      周瑜-反间
DSKFUNC(FANKUI);          //WEI002     司马懿-反馈
DSKFUNC(FANZHU);          //WEI014     曹丕-放逐
//LE005      曹操-飞影
DSKFUNC(FEIYING, F(distance_to, JNT_SELF));
DSKFUNC(FUHUN);           //YJ104      关兴&张苞-父魂
DSKFUNC(FULI);            //YJ107      廖化-伏枥
DSKFUNC(GANGLIE);         //WEI003     夏侯惇-刚烈
DSKFUNC(GANLU);           //YJ007      吴国太-甘露
DSKFUNC(GONGJI);          //YJ105      韩当-弓骑
DSKFUNC(GONGXIN);         //LE002      吕蒙-攻心
DSKFUNC(GUANXING);        //SHU004     诸葛亮-观星
DSKFUNC(GUHUO);           //QUN011     于吉-蛊惑
DSKFUNC(GUICAI);          //WEI002     司马懿-鬼才
DSKFUNC(GUIDAO);          //QUN010     张角-鬼道
DSKFUNC(GUIXIN);          //LE005      曹操-归心
DSKFUNC(GUOSE);           //WU006      大乔-国色
DSKFUNC(GUZHENG);         //WU015      张昭&张纮-固政
DSKFUNC(HAOSHI);          //WU014      鲁肃-好施
//WU011      小乔-红颜
DSKFUNC(HONGYAN, F(card_pattern, JNT_SELF));
DSKFUNC(HONGYUAN);        //VS001      诸葛瑾-弘援
DSKFUNC(HUANGTIAN);       //QUN010     张角-[黄天]
DSKFUNC(HUANSHI);         //VS001      诸葛瑾-缓释
DSKFUNC(HUASHEN);         //QUN009     左慈-化身
DSKFUNC(HUILEI);          //YJ006      马谡-挥泪
DSKFUNC(HUJIA);           //WEI001     曹操-[护驾]
DSKFUNC(HUNZHI);          //WU010      孙策-魂姿
DSKFUNC(HUOJI);           //SHU011     诸葛亮-火计
DSKFUNC(HUOSHOU);         //SHU014     孟获-祸首
DSKFUNC(JIANG);           //WU010      孙策-激昂
DSKFUNC(JIANGCHI);        //YJ102      曹彰-将驰
DSKFUNC(JIANXIONG);       //WEI001     曹操-奸雄
DSKFUNC(JIE);             //XSP005     张飞-嫉恶
DSKFUNC(JIEFAN);          //YJ105      韩当-解烦
DSKFUNC(JIEMING);         //WEI013     荀彧-节命
DSKFUNC(JIEYIN);          //WU008      孙尚香-结姻
DSKFUNC(JIJIANG);         //SHU001     刘备-[激将]
DSKFUNC(JIJIU);           //QUN001     华佗-急救
DSKFUNC(JILEI);           //SP001      杨修-鸡肋
DSKFUNC(JINJIU);          //YJ004      高顺-禁酒
DSKFUNC(JIUCHI);          //QUN006     董卓-酒池
DSKFUNC(JIUSHI);          //YJ001      曹植-酒诗
DSKFUNC(JIUYUAN);         //WU001      孙权-[救援]
DSKFUNC(JIZHI);           //SHU007     黄月英-集智
DSKFUNC(JUEJING);         //LE007      赵云-绝境
DSKFUNC(JUEQING);         //YJ011      张春华-绝情
DSKFUNC(JUJIAN);          //YJ009      徐庶-举荐
DSKFUNC(JUSHOU);          //WEI011     曹仁-据守
DSKFUNC(JUXIANG);         //SHU015     祝融-巨象
DSKFUNC(KANPO);           //SHU011     诸葛亮-看破
DSKFUNC(KEJI);            //WU003      吕蒙-克己
DSKFUNC(KONGCHENG);       //SHU004     诸葛亮-空城
DSKFUNC(KUANGBAO);        //LE006      吕布-狂暴
DSKFUNC(KUANGFENG);       //LE004      诸葛亮-狂风
DSKFUNC(KUANGGU);         //SHU009     魏延-狂骨
DSKFUNC(KUIWEI);          //XSP003     曹仁-溃围
DSKFUNC(KUROU);           //WU004      黄盖-苦肉
DSKFUNC(LEIJI);           //QUN010     张角-雷击
DSKFUNC(LIANHUAN);        //SHU010     庞统-连环
DSKFUNC(LIANPO);          //LE008      司马懿-连破
DSKFUNC(LIANYING);        //WU007      陆逊-连营
DSKFUNC(LIEGONG);         //SHU008     黄忠-烈弓
DSKFUNC(LIEREN);          //SHU015     祝融-烈刃
DSKFUNC(LIHUN);           //XSP002     貂蝉-离魂
DSKFUNC(LIHUO);           //YJ103      程普-疠火
DSKFUNC(LIJIAN);          //QUN003     貂蝉-离间
DSKFUNC(LIULI);           //WU006      大乔-流离
DSKFUNC(LONGDAN);         //SHU005     赵云-龙胆
DSKFUNC(LONGHUN);         //LE007      赵云-龙魂
DSKFUNC(LUANJI);          //QUN004     袁绍-乱击
DSKFUNC(LUANWU);          //QUN007     贾诩-乱武
DSKFUNC(LUOSHEN);         //WEI007     甄姬-洛神
DSKFUNC(LUOYI);           //WEI005     许褚-裸衣
DSKFUNC(LUOYING);         //YJ001      曹植-落英
DSKFUNC(MANJUAN);         //XSP004     庞统-漫卷
//SHU006     马超-马术
DSKFUNC(MASHU, F(distance_from, JNT_SELF));
DSKFUNC(MENGJIN);         //QUN008     庞德-猛进
DSKFUNC(MIJI);            //YJ110      王异-秘计
DSKFUNC(MINGCE);          //YJ002      陈宫-明策
DSKFUNC(MINGZHE);         //VS001      诸葛瑾-明哲
DSKFUNC(MOUDAN);          //XSP006     吕蒙-谋断
DSKFUNC(NIEPAN);          //SHU010     庞统-涅槃
DSKFUNC(PAOXIAO);         //SHU003     张飞-咆哮
DSKFUNC(POJUN);           //YJ008      徐盛-破军
DSKFUNC(QIANGXI);         //WEI012     典韦-强袭
DSKFUNC(QIANXI);          //YJ109      马岱-潜袭
DSKFUNC(QIANXUN);         //WU007      陆逊-谦逊
DSKFUNC(QIAOBIAN);        //WEI009     张郃-巧变
DSKFUNC(QICAI);           //SHU007     黄月英-奇才
DSKFUNC(QICE);            //YJ111      荀攸-奇策
DSKFUNC(QINGGUO);         //WEI007     甄姬-倾国
DSKFUNC(QINGNANG);        //QUN001     华佗-青囊
DSKFUNC(QINYIN);          //LE003      周瑜-琴音
DSKFUNC(QIXI);            //WU002      甘宁-奇袭
DSKFUNC(QIXING);          //LE004      诸葛亮-七星
DSKFUNC(QUANJI);          //YJ012      钟会-权计
DSKFUNC(QUHU);            //WEI013     荀彧-驱虎
DSKFUNC(RENDE);           //SHU001     刘备-仁德
DSKFUNC(RENJIE);          //LE008      司马懿-忍戒
DSKFUNC(ROULIN);          //QUN006     董卓-肉林
DSKFUNC(RUOYU);           //SHU013     刘禅-[若愚]
DSKFUNC(SHANGSHI);        //YJ011      张春华-伤逝
DSKFUNC(SHELIE);          //LE002      吕蒙-涉猎
DSKFUNC(SHENFEN);         //LE006      吕布-神愤
DSKFUNC(SHENJI);          //SP008      吕布-神戟
DSKFUNC(SHENSU);          //WEI008     夏侯渊-神速
DSKFUNC(SHENWEI);         //SP008      吕布-神威
DSKFUNC(SHIYONG);         //YJ106      华雄-恃勇
DSKFUNC(SHUANGXIOANG);    //QUN005     颜良&文丑-双雄
DSKFUNC(SONGWEI);         //WEI014     曹丕-[颂威]
DSKFUNC(TANHU);           //XSP006     吕蒙-探虎
DSKFUNC(TIANDU);          //WEI006     郭嘉-天妒
//WU011      小乔-天香
DSKFUNC(TIANXIANG);//, F(0, JNT_SELF));
DSKFUNC(TIANYI);          //WU012      太史慈-天义
DSKFUNC(TIAOXIN);         //SHU012     姜维-挑衅
DSKFUNC(TIEJI);           //SHU006     马超-铁骑
DSKFUNC(TUNTIAN);         //WEI015     邓艾-屯田
DSKFUNC(TUXI);            //WEI004     张辽-突袭
DSKFUNC(WANSHA);          //QUN007     贾诩-完杀
DSKFUNC(WEIDI);           //SP004      袁术-伪帝
DSKFUNC(WEIMU);           //QUN007     贾诩-帷幕
DSKFUNC(WUHUN);           //LE001      关羽-武魂
DSKFUNC(WUMOU);           //LE006      吕布-无谋
DSKFUNC(WUQIAN);          //LE006      吕布-无前
DSKFUNC(WUSHEN);          //LE001      关羽-武神
DSKFUNC(WUSHENG);         //SHU002     关羽-武圣
DSKFUNC(WUSHUANG);        //QUN002     吕布-无双
DSKFUNC(WUYAN);           //YJ009      徐庶-无言
DSKFUNC(XIANGLE);         //SHU013     刘禅-享乐
DSKFUNC(XIANZHEN);        //YJ004      高顺-陷阵
DSKFUNC(XIAOJI);          //WU008      孙尚香-枭姬
DSKFUNC(XINGSHUANG);      //WEI014     曹丕-行殇
DSKFUNC(XINSHENG);        //QUN009     左慈-新生
DSKFUNC(XINZHAN);         //YJ006      马谡-心战
DSKFUNC(XIULUO);          //SP008      吕布-修罗
DSKFUNC(XUANFENG);        //YJ005      凌统-旋风
DSKFUNC(XUANHUO);         //YJ003      法正-眩惑
DSKFUNC(XUEYI);           //QUN004     袁绍-[血裔]
DSKFUNC(YANZHENG);        //XSP003     曹仁-严整
DSKFUNC(YEYAN);           //LE003      周瑜-业炎
DSKFUNC(YICONG);          //SP003      公孙瓒-义从
DSKFUNC(YIJI);            //WEI006     郭嘉-遗计
DSKFUNC(YINGHUN);         //WU009      孙坚-英魂
DSKFUNC(YINGZI);          //WU005      周瑜-英姿
DSKFUNC(YIZHONG);         //YJ010      于禁-毅重
DSKFUNC(YONGSI);          //SP004      袁术-庸肆
DSKFUNC(ZAIQI);           //SHU014     孟获-再起
DSKFUNC(ZAOXIAN);         //WEI015     邓艾-凿险
DSKFUNC(ZHENLIE);         //YJ110      王异-贞烈
DSKFUNC(ZHIBA);           //WU010      孙策-[制霸]
DSKFUNC(ZHICHI);          //YJ002      陈宫-智迟
DSKFUNC(ZHIHENG);         //WU001      孙权-制衡
DSKFUNC(ZHIJI);           //SHU012     姜维-志继
DSKFUNC(ZHIJIAN);         //WU015      张昭&张纮-直谏
DSKFUNC(ZHIYU);           //YJ111      荀攸-智愚
DSKFUNC(ZHUIYI);          //YJ101      步练师-追忆
DSKFUNC(ZILI);            //YJ012      钟会-自立(排异)
DSKFUNC(ZISHOU);          //YJ108      刘表-自守
DSKFUNC(ZONGSHI);         //YJ108      刘表-宗室
DSKFUNC(ZUIXIANG);        //XSP004     庞统-醉乡

DSKFUNC(CHENGXIANG);      //YJ201      曹冲-称象
DSKFUNC(RENXIN);          //YJ201      曹冲-仁心
DSKFUNC(ZHUIKONG);        //YJ202      伏皇后-惴恐
DSKFUNC(QIUYUAN);         //YJ202      伏皇后-求援
DSKFUNC(LONGYIN);         //YJ203      关平-龙吟
DSKFUNC(JINGCE);          //YJ204      郭淮-精策
DSKFUNC(QIAOSHUI);        //YJ205      简雍-巧说
DSKFUNC(ZONGSHI_JY);      //YJ205      简雍-纵适
DSKFUNC(JUECE);           //YJ206      李儒-绝策
DSKFUNC(MIEJI);           //YJ206      李儒-灭计
DSKFUNC(FENCHENG);        //YJ206      李儒-焚城
DSKFUNC(XIANSI);          //YJ207      刘封-陷嗣
DSKFUNC(JUNXING);         //YJ208      满宠-峻刑
DSKFUNC(YUCE);            //YJ208      满宠-御策
DSKFUNC(DUODAO);          //YJ209      潘璋&马忠-夺刀
DSKFUNC(ANJIAN);          //YJ209      潘璋&马忠-暗箭
DSKFUNC(ZONGXUAN);        //YJ210      虞翻-纵玄
DSKFUNC(ZHIYAN);          //YJ210      虞翻-直言
DSKFUNC(DANSHOU);         //YJ211      朱然-胆守

DSKFUNC(XINGWU);          //SP021      大乔&小乔-星舞
DSKFUNC(YANLUO);          //SP021      大乔&小乔-雁落






const skill_entry_t wsg_skill_entries[] = {
    DSK(NONE, "", 0, ""),
    DSK(ANXU, "安恤", 0, ""),
    DSK(BAIYIN, "拜印", 0, ""),
    DSK(BAONVE, "暴虐", JNL_MASTER, ""),
    DSK(BAZHEN, "八阵", 0, ""),
    DSK(BEIGE, "悲歌", 0, ""),
    DSK(BENGHUAI, "崩坏", 0, ""),
    DSK(BIYUE, "闭月", 0, ""),
    DSK(BUQU, "不屈", 0, ""),
    DSK(BUYI, "补益", 0, ""),
    DSK(CHONGZHEN, "冲阵", 0, ""),
    DSK(CHUNLAO, "醇醪", 0, ""),
    DSK(DAHE, "大喝", 0, ""),
    DSK(DANGXIAN, "当先", 0, ""),
    DSK(DANJI, "单骑", 0, ""),
    DSK(DANLAO, "啖酪", 0, ""),
    DSK(DAWU, "大雾", 0, ""),
    DSK(DIMENG, "缔盟", 0, ""),
    DSK(DUANCHANG, "断肠", 0, ""),
    DSK(DUANLIANG, "断粮", 0, ""),
    DSK(ENYUAN, "恩怨", 0, ""),
    DSK(FANGQUAN, "放权", 0, ""),
    DSK(FANJIAN, "反间", 0, ""),
    DSK(FANKUI, "反馈", 0, ""),
    DSK(FANZHU, "放逐", 0, ""),
    DSK(FEIYING, "飞影", JNL_LOCKED, ""),
    DSK(FUHUN, "父魂", 0, ""),
    DSK(FULI, "伏枥", 0, ""),
    DSK(GANGLIE, "刚烈", 0, ""),
    DSK(GANLU, "甘露", 0, ""),
    DSK(GONGJI, "弓骑", 0, ""),
    DSK(GONGXIN, "攻心", 0, ""),
    DSK(GUANXING, "观星", 0, ""),
    DSK(GUHUO, "蛊惑", 0, ""),
    DSK(GUICAI, "鬼才", 0, ""),
    DSK(GUIDAO, "鬼道", 0, ""),
    DSK(GUIXIN, "归心", 0, ""),
    DSK(GUOSE, "国色", 0, ""),
    DSK(GUZHENG, "固政", 0, ""),
    DSK(HAOSHI, "好施", 0, ""),
    DSK(HONGYAN, "红颜", JNL_LOCKED, ""),
    DSK(HONGYUAN, "弘援", 0, ""),
    DSK(HUANGTIAN, "黄天", JNL_MASTER, ""),
    DSK(HUANSHI, "缓释", 0, ""),
    DSK(HUASHEN, "化身", 0, ""),
    DSK(HUILEI, "挥泪", 0, ""),
    DSK(HUJIA, "护驾", JNL_MASTER, ""),
    DSK(HUNZHI, "魂姿", 0, ""),
    DSK(HUOJI, "火计", 0, ""),
    DSK(HUOSHOU, "祸首", 0, ""),
    DSK(JIANG, "激昂", 0, ""),
    DSK(JIANGCHI, "将驰", 0, ""),
    DSK(JIANXIONG, "奸雄", 0, ""),
    DSK(JIE, "嫉恶", 0, ""),
    DSK(JIEFAN, "解烦", 0, ""),
    DSK(JIEMING, "节命", 0, ""),
    DSK(JIEYIN, "结姻", 0, ""),
    DSK(JIJIANG, "激将", JNL_MASTER, ""),
    DSK(JIJIU, "急救", 0, ""),
    DSK(JILEI, "鸡肋", 0, ""),
    DSK(JINJIU, "禁酒", 0, ""),
    DSK(JIUCHI, "酒池", 0, ""),
    DSK(JIUSHI, "酒诗", 0, ""),
    DSK(JIUYUAN, "救援", JNL_MASTER, ""),
    DSK(JIZHI, "集智", 0, ""),
    DSK(JUEJING, "绝境", 0, ""),
    DSK(JUEQING, "绝情", 0, ""),
    DSK(JUJIAN, "举荐", 0, ""),
    DSK(JUSHOU, "据守", 0, ""),
    DSK(JUXIANG, "巨象", 0, ""),
    DSK(KANPO, "看破", 0, ""),
    DSK(KEJI, "克己", 0, ""),
    DSK(KONGCHENG, "空城", 0, ""),
    DSK(KUANGBAO, "狂暴", 0, ""),
    DSK(KUANGFENG, "狂风", 0, ""),
    DSK(KUANGGU, "狂骨", 0, ""),
    DSK(KUIWEI, "溃围", 0, ""),
    DSK(KUROU, "苦肉", 0, ""),
    DSK(LEIJI, "雷击", 0, ""),
    DSK(LIANHUAN, "连环", 0, ""),
    DSK(LIANPO, "连破", 0, ""),
    DSK(LIANYING, "连营", 0, ""),
    DSK(LIEGONG, "烈弓", 0, ""),
    DSK(LIEREN, "烈刃", 0, ""),
    DSK(LIHUN, "离魂", 0, ""),
    DSK(LIHUO, "疠火", 0, ""),
    DSK(LIJIAN, "离间", 0, ""),
    DSK(LIULI, "流离", 0, ""),
    DSK(LONGDAN, "龙胆", 0, ""),
    DSK(LONGHUN, "龙魂", 0, ""),
    DSK(LUANJI, "乱击", 0, ""),
    DSK(LUANWU, "乱武", 0, ""),
    DSK(LUOSHEN, "洛神", 0, ""),
    DSK(LUOYI, "裸衣", 0, ""),
    DSK(LUOYING, "落英", 0, ""),
    DSK(MANJUAN, "漫卷", 0, ""),
    DSK(MASHU, "马术", JNL_LOCKED, ""),
    DSK(MENGJIN, "猛进", 0, ""),
    DSK(MIJI, "秘计", 0, ""),
    DSK(MINGCE, "明策", 0, ""),
    DSK(MINGZHE, "明哲", 0, ""),
    DSK(MOUDAN, "谋断", 0, ""),
    DSK(NIEPAN, "涅槃", 0, ""),
    DSK(PAOXIAO, "咆哮", 0, ""),
    DSK(POJUN, "破军", 0, ""),
    DSK(QIANGXI, "强袭", 0, ""),
    DSK(QIANXI, "潜袭", 0, ""),
    DSK(QIANXUN, "谦逊", 0, ""),
    DSK(QIAOBIAN, "巧变", 0, ""),
    DSK(QICAI, "奇才", 0, ""),
    DSK(QICE, "奇策", 0, ""),
    DSK(QINGGUO, "倾国", 0, ""),
    DSK(QINGNANG, "青囊", 0, ""),
    DSK(QINYIN, "琴音", 0, ""),
    DSK(QIXI, "奇袭", 0, ""),
    DSK(QIXING, "七星", 0, ""),
    DSK(QUANJI, "权计", 0, ""),
    DSK(QUHU, "驱虎", 0, ""),
    DSK(RENDE, "仁德", 0, ""),
    DSK(RENJIE, "忍戒", 0, ""),
    DSK(ROULIN, "肉林", 0, ""),
    DSK(RUOYU, "若愚", JNL_MASTER, ""),
    DSK(SHANGSHI, "伤逝", 0, ""),
    DSK(SHELIE, "涉猎", 0, ""),
    DSK(SHENFEN, "神愤", 0, ""),
    DSK(SHENJI, "神戟", 0, ""),
    DSK(SHENSU, "神速", 0, ""),
    DSK(SHENWEI, "神威", 0, ""),
    DSK(SHIYONG, "恃勇", 0, ""),
    DSK(SHUANGXIOANG, "双雄", 0, ""),
    DSK(SONGWEI, "颂威", JNL_MASTER, ""),
    DSK(TANHU, "探虎", 0, ""),
    DSK(TIANDU, "天妒", 0, ""),
    DSK(TIANXIANG, "天香", 0, ""),
    DSK(TIANYI, "天义", 0, ""),
    DSK(TIAOXIN, "挑衅", 0, ""),
    DSK(TIEJI, "铁骑", 0, ""),
    DSK(TUNTIAN, "屯田", 0, ""),
    DSK(TUXI, "突袭", 0, ""),
    DSK(WANSHA, "完杀", 0, ""),
    DSK(WEIDI, "伪帝", 0, ""),
    DSK(WEIMU, "帷幕", 0, ""),
    DSK(WUHUN, "武魂", 0, ""),
    DSK(WUMOU, "无谋", 0, ""),
    DSK(WUQIAN, "无前", 0, ""),
    DSK(WUSHEN, "武神", 0, ""),
    DSK(WUSHENG, "武圣", 0, ""),
    DSK(WUSHUANG, "无双", 0, ""),
    DSK(WUYAN, "无言", 0, ""),
    DSK(XIANGLE, "享乐", 0, ""),
    DSK(XIANZHEN, "陷阵", 0, ""),
    DSK(XIAOJI, "枭姬", 0, ""),
    DSK(XINGSHUANG, "行殇", 0, ""),
    DSK(XINSHENG, "新生", 0, ""),
    DSK(XINZHAN, "心战", 0, ""),
    DSK(XIULUO, "修罗", 0, ""),
    DSK(XUANFENG, "旋风", 0, ""),
    DSK(XUANHUO, "眩惑", 0, ""),
    DSK(XUEYI, "血裔", JNL_MASTER, ""),
    DSK(YANZHENG, "严整", 0, ""),
    DSK(YEYAN, "业炎", 0, ""),
    DSK(YICONG, "义从", 0, ""),
    DSK(YIJI, "遗计", 0, ""),
    DSK(YINGHUN, "英魂", 0, ""),
    DSK(YINGZI, "英姿", 0, ""),
    DSK(YIZHONG, "毅重", 0, ""),
    DSK(YONGSI, "庸肆", 0, ""),
    DSK(ZAIQI, "再起", 0, ""),
    DSK(ZAOXIAN, "凿险", 0, ""),
    DSK(ZHENLIE, "贞烈", 0, ""),
    DSK(ZHIBA, "制霸", JNL_MASTER, ""),
    DSK(ZHICHI, "智迟", 0, ""),
    DSK(ZHIHENG, "制衡", 0, ""),
    DSK(ZHIJI, "志继", 0, ""),
    DSK(ZHIJIAN, "直谏", 0, ""),
    DSK(ZHIYU, "智愚", 0, ""),
    DSK(ZHUIYI, "追忆", 0, ""),
    DSK(ZILI, "自立(排异)", 0, ""),
    DSK(ZISHOU, "自守", 0, ""),
    DSK(ZONGSHI, "宗室", 0, ""),
    DSK(ZUIXIANG, "醉乡", 0, ""),
    DSK(CHENGXIANG, "称象", 0, ""),
    DSK(RENXIN, "仁心", 0, ""),
    DSK(ZHUIKONG, "惴恐", 0, ""),
    DSK(QIUYUAN, "求援", 0, ""),
    DSK(LONGYIN, "龙吟", 0, ""),
    DSK(JINGCE, "精策", 0, ""),
    DSK(QIAOSHUI, "巧说", 0, ""),
    DSK(ZONGSHI_JY, "纵适", 0, ""),
    DSK(JUECE, "绝策", 0, ""),
    DSK(MIEJI, "灭计", 0, ""),
    DSK(FENCHENG, "焚城", 0, ""),
    DSK(XIANSI, "陷嗣", 0, ""),
    DSK(JUNXING, "峻刑", 0, ""),
    DSK(YUCE, "御策", 0, ""),
    DSK(DUODAO, "夺刀", 0, ""),
    DSK(ANJIAN, "暗箭", 0, ""),
    DSK(ZONGXUAN, "纵玄", 0, ""),
    DSK(ZHIYAN, "直言", 0, ""),
    DSK(DANSHOU, "胆守", 0, ""),
    DSK(XINGWU, "星舞", 0, ""),
    DSK(YANLUO, "雁落", 0, ""),
};

//
//Skill::Skill(){
//    
//}
//
//Skill* Skill::getSkillByID(skill_id_t id) {
//    const skill_entry_t *pske = skillEntries + id;
//
////    sk_2_is_runnable(Game(), NULL);
//    return NULL;
//}
//
//
//
//void Skill::install() {
//
//}
//
//
//void Skill::uninstall() {
//
//}
//




SkillRegister::SkillRegister(Game *game): _game(game) {

}
SkillRegister::~SkillRegister() {

}


void SkillRegister::assignPlayers(int cnt) {
    for (std::vector<Skill*>::iterator iter = _skills.begin(); iter != _skills.end(); ++iter)
        delete *iter;
    _skills.clear();

    for(int i = 0; i < cnt; ++i) {
        if (size() <= i) {
            push_back(new std::map<fsm_status_t, Skills>());
        } else {
            (*this)[i]->clear();// = new std::map<fsm_status_t, Skills>();
        }
    }
}

Skill* SkillRegister::install(skill_id_t skid, player_index_t plr) {
    if (plr > this->size() || skid <= 0) {
        return NULL;
    }

    const skill_entry_t *pskill = wsg_skill_entries + skid;
    std::map<fsm_status_t, Skills> *pfs;
    Skill* skill = new Skill();
    skill->entry = pskill;
    skill->player = plr;
    skill->sr = this;
    _skills.push_back(skill);

    for (int i = 0; i < pskill->chance_cnt; ++i) {
        switch(pskill->chances[i].object) {
            case JNT_SELF:
                pfs = (*this)[plr];
                ((*pfs)[pskill->chances[i].chance]).push_back(skill);
                break;
            case JNT_OTHER:
                for (int p = 0; p < this->_game->players.size(); ++p) {
                    if (p == plr) continue;
                    pfs = (*this)[plr];
                    ((*pfs)[pskill->chances[i].chance]).push_back(skill);
                }
                break;
            case JNT_ALL:
                for (int p = 0; p < this->_game->players.size(); ++p) {
                    pfs = (*this)[plr];
                    ((*pfs)[pskill->chances[i].chance]).push_back(skill);
                }
                break;
            case JNT_MASTER:
                break;
            default:
                break;
        }
    }

    return NULL;
}



























#define  __SKILL_SOURCE_C__
#include "skill-funcitem.c"
#undef   __SKILL_SOURCE_C__
WSG_END