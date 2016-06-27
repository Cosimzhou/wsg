//
//  skill.h
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__SKILL__H__
#define __WSG__SKILL__H__

#include <map>
#include <vector>
#include <list>
//#include "status.hpp"

WSG_BEGIN
//# 最先拥有该技能的武将-技能名称
typedef enum {
    JN_NONE,
    JN_ANXU,            //YJ101      步练师-安恤
    JN_BAIYIN,          //LE008      司马懿-拜印
    JN_BAONVE,          //QUN006     董卓-[暴虐]
    JN_BAZHEN,          //SHU011     诸葛亮-八阵
    JN_BEIGE,           //QUN012     蔡文姬-悲歌
    JN_BENGHUAI,        //QUN006     董卓-崩坏
    JN_BIYUE,           //QUN003     貂蝉-闭月
    JN_BUQU,            //WU013      周泰-不屈
    JN_BUYI,            //YJ007      吴国太-补益
    JN_CHONGZHEN,       //XSP001     赵云-冲阵
    JN_CHUNLAO,         //YJ103      程普-醇醪
    JN_DAHE,            //XSP005     张飞-大喝
    JN_DANGXIAN,        //YJ107      廖化-当先
    JN_DANJI,           //SP007      关羽-单骑
    JN_DANLAO,          //SP001      杨修-啖酪
    JN_DAWU,            //LE004      诸葛亮-大雾
    JN_DIMENG,          //WU014      鲁肃-缔盟
    JN_DUANCHANG,       //QUN012     蔡文姬-断肠
    JN_DUANLIANG,       //WEI010     徐晃-断粮
    JN_ENYUAN,          //YJ003      法正-恩怨
    JN_FANGQUAN,        //SHU013     刘禅-放权
    JN_FANJIAN,         //WU005      周瑜-反间
    JN_FANKUI,          //WEI002     司马懿-反馈
    JN_FANZHU,          //WEI014     曹丕-放逐
    JN_FEIYING,         //LE005      曹操-飞影
    JN_FUHUN,           //YJ104      关兴&张苞-父魂
    JN_FULI,            //YJ107      廖化-伏枥
    JN_GANGLIE,         //WEI003     夏侯惇-刚烈
    JN_GANLU,           //YJ007      吴国太-甘露
    JN_GONGJI,          //YJ105      韩当-弓骑
    JN_GONGXIN,         //LE002      吕蒙-攻心
    JN_GUANXING,        //SHU004     诸葛亮-观星
    JN_GUHUO,           //QUN011     于吉-蛊惑
    JN_GUICAI,          //WEI002     司马懿-鬼才
    JN_GUIDAO,          //QUN010     张角-鬼道
    JN_GUIXIN,          //LE005      曹操-归心
    JN_GUOSE,           //WU006      大乔-国色
    JN_GUZHENG,         //WU015      张昭&张纮-固政
    JN_HAOSHI,          //WU014      鲁肃-好施
    JN_HONGYAN,         //WU011      小乔-红颜
    JN_HONGYUAN,        //VS001      诸葛瑾-弘援
    JN_HUANGTIAN,       //QUN010     张角-[黄天]
    JN_HUANSHI,         //VS001      诸葛瑾-缓释
    JN_HUASHEN,         //QUN009     左慈-化身
    JN_HUILEI,          //YJ006      马谡-挥泪
    JN_HUJIA,           //WEI001     曹操-[护驾]
    JN_HUNZHI,          //WU010      孙策-魂姿
    JN_HUOJI,           //SHU011     诸葛亮-火计
    JN_HUOSHOU,         //SHU014     孟获-祸首
    JN_JIANG,           //WU010      孙策-激昂
    JN_JIANGCHI,        //YJ102      曹彰-将驰
    JN_JIANXIONG,       //WEI001     曹操-奸雄
    JN_JIE,             //XSP005     张飞-嫉恶
    JN_JIEFAN,          //YJ105      韩当-解烦
    JN_JIEMING,         //WEI013     荀彧-节命
    JN_JIEYIN,          //WU008      孙尚香-结姻
    JN_JIJIANG,         //SHU001     刘备-[激将]
    JN_JIJIU,           //QUN001     华佗-急救
    JN_JILEI,           //SP001      杨修-鸡肋
    JN_JINJIU,          //YJ004      高顺-禁酒
    JN_JIUCHI,          //QUN006     董卓-酒池
    JN_JIUSHI,          //YJ001      曹植-酒诗
    JN_JIUYUAN,         //WU001      孙权-[救援]
    JN_JIZHI,           //SHU007     黄月英-集智
    JN_JUEJING,         //LE007      赵云-绝境
    JN_JUEQING,         //YJ011      张春华-绝情
    JN_JUJIAN,          //YJ009      徐庶-举荐
    JN_JUSHOU,          //WEI011     曹仁-据守
    JN_JUXIANG,         //SHU015     祝融-巨象
    JN_KANPO,           //SHU011     诸葛亮-看破
    JN_KEJI,            //WU003      吕蒙-克己
    JN_KONGCHENG,       //SHU004     诸葛亮-空城
    JN_KUANGBAO,        //LE006      吕布-狂暴
    JN_KUANGFENG,       //LE004      诸葛亮-狂风
    JN_KUANGGU,         //SHU009     魏延-狂骨
    JN_KUIWEI,          //XSP003     曹仁-溃围
    JN_KUROU,           //WU004      黄盖-苦肉
    JN_LEIJI,           //QUN010     张角-雷击
    JN_LIANHUAN,        //SHU010     庞统-连环
    JN_LIANPO,          //LE008      司马懿-连破
    JN_LIANYING,        //WU007      陆逊-连营
    JN_LIEGONG,         //SHU008     黄忠-烈弓
    JN_LIEREN,          //SHU015     祝融-烈刃
    JN_LIHUN,           //XSP002     貂蝉-离魂
    JN_LIHUO,           //YJ103      程普-疠火
    JN_LIJIAN,          //QUN003     貂蝉-离间
    JN_LIULI,           //WU006      大乔-流离
    JN_LONGDAN,         //SHU005     赵云-龙胆
    JN_LONGHUN,         //LE007      赵云-龙魂
    JN_LUANJI,          //QUN004     袁绍-乱击
    JN_LUANWU,          //QUN007     贾诩-乱武
    JN_LUOSHEN,         //WEI007     甄姬-洛神
    JN_LUOYI,           //WEI005     许褚-裸衣
    JN_LUOYING,         //YJ001      曹植-落英
    JN_MANJUAN,         //XSP004     庞统-漫卷
    JN_MASHU,           //SHU006     马超-马术
    JN_MENGJIN,         //QUN008     庞德-猛进
    JN_MIJI,            //YJ110      王异-秘计
    JN_MINGCE,          //YJ002      陈宫-明策
    JN_MINGZHE,         //VS001      诸葛瑾-明哲
    JN_MOUDAN,          //XSP006     吕蒙-谋断
    JN_NIEPAN,          //SHU010     庞统-涅槃
    JN_PAOXIAO,         //SHU003     张飞-咆哮
    JN_POJUN,           //YJ008      徐盛-破军
    JN_QIANGXI,         //WEI012     典韦-强袭
    JN_QIANXI,          //YJ109      马岱-潜袭
    JN_QIANXUN,         //WU007      陆逊-谦逊
    JN_QIAOBIAN,        //WEI009     张郃-巧变
    JN_QICAI,           //SHU007     黄月英-奇才
    JN_QICE,            //YJ111      荀攸-奇策
    JN_QINGGUO,         //WEI007     甄姬-倾国
    JN_QINGNANG,        //QUN001     华佗-青囊
    JN_QINYIN,          //LE003      周瑜-琴音
    JN_QIXI,            //WU002      甘宁-奇袭
    JN_QIXING,          //LE004      诸葛亮-七星
    JN_QUANJI,          //YJ012      钟会-权计
    JN_QUHU,            //WEI013     荀彧-驱虎
    JN_RENDE,           //SHU001     刘备-仁德
    JN_RENJIE,          //LE008      司马懿-忍戒
    JN_ROULIN,          //QUN006     董卓-肉林
    JN_RUOYU,           //SHU013     刘禅-[若愚]
    JN_SHANGSHI,        //YJ011      张春华-伤逝
    JN_SHELIE,          //LE002      吕蒙-涉猎
    JN_SHENFEN,         //LE006      吕布-神愤
    JN_SHENJI,          //SP008      吕布-神戟
    JN_SHENSU,          //WEI008     夏侯渊-神速
    JN_SHENWEI,         //SP008      吕布-神威
    JN_SHIYONG,         //YJ106      华雄-恃勇
    JN_SHUANGXIOANG,    //QUN005     颜良&文丑-双雄
    JN_SONGWEI,         //WEI014     曹丕-[颂威]
    JN_TANHU,           //XSP006     吕蒙-探虎
    JN_TIANDU,          //WEI006     郭嘉-天妒
    JN_TIANXIANG,       //WU011      小乔-天香
    JN_TIANYI,          //WU012      太史慈-天义
    JN_TIAOXIN,         //SHU012     姜维-挑衅
    JN_TIEJI,           //SHU006     马超-铁骑
    JN_TUNTIAN,         //WEI015     邓艾-屯田
    JN_TUXI,            //WEI004     张辽-突袭
    JN_WANSHA,          //QUN007     贾诩-完杀
    JN_WEIDI,           //SP004      袁术-伪帝
    JN_WEIMU,           //QUN007     贾诩-帷幕
    JN_WUHUN,           //LE001      关羽-武魂
    JN_WUMOU,           //LE006      吕布-无谋
    JN_WUQIAN,          //LE006      吕布-无前
    JN_WUSHEN,          //LE001      关羽-武神
    JN_WUSHENG,         //SHU002     关羽-武圣
    JN_WUSHUANG,        //QUN002     吕布-无双
    JN_WUYAN,           //YJ009      徐庶-无言
    JN_XIANGLE,         //SHU013     刘禅-享乐
    JN_XIANZHEN,        //YJ004      高顺-陷阵
    JN_XIAOJI,          //WU008      孙尚香-枭姬
    JN_XINGSHUANG,      //WEI014     曹丕-行殇
    JN_XINSHENG,        //QUN009     左慈-新生
    JN_XINZHAN,         //YJ006      马谡-心战
    JN_XIULUO,          //SP008      吕布-修罗
    JN_XUANFENG,        //YJ005      凌统-旋风
    JN_XUANHUO,         //YJ003      法正-眩惑
    JN_XUEYI,           //QUN004     袁绍-[血裔]
    JN_YANZHENG,        //XSP003     曹仁-严整
    JN_YEYAN,           //LE003      周瑜-业炎
    JN_YICONG,          //SP003      公孙瓒-义从
    JN_YIJI,            //WEI006     郭嘉-遗计
    JN_YINGHUN,         //WU009      孙坚-英魂
    JN_YINGZI,          //WU005      周瑜-英姿
    JN_YIZHONG,         //YJ010      于禁-毅重
    JN_YONGSI,          //SP004      袁术-庸肆
    JN_ZAIQI,           //SHU014     孟获-再起
    JN_ZAOXIAN,         //WEI015     邓艾-凿险
    JN_ZHENLIE,         //YJ110      王异-贞烈
    JN_ZHIBA,           //WU010      孙策-[制霸]
    JN_ZHICHI,          //YJ002      陈宫-智迟
    JN_ZHIHENG,         //WU001      孙权-制衡
    JN_ZHIJI,           //SHU012     姜维-志继
    JN_ZHIJIAN,         //WU015      张昭&张纮-直谏
    JN_ZHIYU,           //YJ111      荀攸-智愚
    JN_ZHUIYI,          //YJ101      步练师-追忆
    JN_ZILI,            //YJ012      钟会-自立(排异)
    JN_ZISHOU,          //YJ108      刘表-自守
    JN_ZONGSHI,         //YJ108      刘表-宗室
    JN_ZUIXIANG,        //XSP004     庞统-醉乡

    JN_CHENGXIANG,      //YJ201      曹冲-称象
    JN_RENXIN,          //YJ201      曹冲-仁心
    JN_ZHUIKONG,        //YJ202      伏皇后-惴恐
    JN_QIUYUAN,         //YJ202      伏皇后-求援
    JN_LONGYIN,         //YJ203      关平-龙吟
    JN_JINGCE,          //YJ204      郭淮-精策
    JN_QIAOSHUI,        //YJ205      简雍-巧说
    JN_ZONGSHI_JY,      //YJ205      简雍-纵适
    JN_JUECE,           //YJ206      李儒-绝策
    JN_MIEJI,           //YJ206      李儒-灭计
    JN_FENCHENG,        //YJ206      李儒-焚城
    JN_XIANSI,          //YJ207      刘封-陷嗣
    JN_JUNXING,         //YJ208      满宠-峻刑
    JN_YUCE,            //YJ208      满宠-御策
    JN_DUODAO,          //YJ209      潘璋&马忠-夺刀
    JN_ANJIAN,          //YJ209      潘璋&马忠-暗箭
    JN_ZONGXUAN,        //YJ210      虞翻-纵玄
    JN_ZHIYAN,          //YJ210      虞翻-直言
    JN_DANSHOU,         //YJ211      朱然-胆守

    JN_XINGWU,          //SP021      大乔&小乔-星舞
    JN_YANLUO,          //SP021      大乔&小乔-雁落
} skill_id_t;


typedef enum {
    JNL_NONE            = 0,
    JNL_MASTER          = (1<<1),
    JNL_LOCKED          = (1<<2),
    JNL_LIMITED         = (1<<3),
    JNL_WAKING          = (1<<4),

} skill_type_mask_t;

typedef enum {
    JNT_SELF,
    JNT_OTHER,
    JNT_ALL,
    JNT_MASTER,
} skill_object_type_t;


typedef bool (*skill_is_runnable_func_t)(Game&, fsm_status_t);
typedef void (*skill_runfunc_t)(Game&);

typedef struct {
    fsm_status_t chance;
    skill_object_type_t object;
} skill_chance_t;

typedef struct {
    skill_id_t sid;
    const char *name;
    const char *describe;
    skill_type_mask_t type;
    int addcondition;
    int chance_cnt;
    const skill_chance_t *chances;
    skill_is_runnable_func_t judge_run;
    skill_runfunc_t run;
} skill_entry_t;

typedef struct {
    const skill_entry_t *entry;
    player_index_t player;
    class SkillRegister *sr;
} skill_t;


typedef skill_t Skill;
typedef std::list<Skill*> Skills;

class SkillRegister
    : public std::vector<std::map<fsm_status_t, Skills>* >
{
public:
    SkillRegister(Game *game);
    ~SkillRegister();

    void assignPlayers(int cnt);

    Skill* install(skill_id_t, player_index_t plr);
//    void uninstall();
private:
    Game *_game;
    std::vector<Skill*> _skills;
};

















#define SKILL_IS_LOCKED(sk)             (sk->type & JNL_LOCKED)
















WSG_END
#endif /* defined(__WSG__SKILL__H__) */
