//
//  skill.cpp
//  sgs
//
//  Created by 周志超 on 15/6/16.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//
#include "skill.h"
WSG_BEGIN
#define __WSG__DECLARE__SKILL__LIST__H__
#   include "skill-funcitem.h"
#undef __WSG__DECLARE__SKILL__LIST__H__


const skill_entry_t* wsg_skill_entries[] = {
    DSKE(NONE),
    DSKE(ANXU),            //YJ101      步练师-安恤
    DSKE(BAIYIN),          //LE008      司马懿-拜印
    DSKE(BAONVE),          //QUN006     董卓-[暴虐]
    DSKE(BAZHEN),          //SHU011     诸葛亮-八阵
    DSKE(BEIGE),           //QUN012     蔡文姬-悲歌
    DSKE(BENGHUAI),        //QUN006     董卓-崩坏
    DSKE(BIYUE),           //QUN003     貂蝉-闭月
    DSKE(BUQU),            //WU013      周泰-不屈
    DSKE(BUYI),            //YJ007      吴国太-补益
    DSKE(CHONGZHEN),       //XSP001     赵云-冲阵
    DSKE(CHUNLAO),         //YJ103      程普-醇醪
    DSKE(DAHE),            //XSP005     张飞-大喝
    DSKE(DANGXIAN),        //YJ107      廖化-当先
    DSKE(DANJI),           //SP007      关羽-单骑
    DSKE(DANLAO),          //SP001      杨修-啖酪
    DSKE(DAWU),            //LE004      诸葛亮-大雾
    DSKE(DIMENG),          //WU014      鲁肃-缔盟
    DSKE(DUANCHANG),       //QUN012     蔡文姬-断肠
    DSKE(DUANLIANG),       //WEI010     徐晃-断粮
    DSKE(ENYUAN),          //YJ003      法正-恩怨
    DSKE(FANGQUAN),        //SHU013     刘禅-放权
    DSKE(FANJIAN),         //WU005      周瑜-反间
    DSKE(FANKUI),          //WEI002     司马懿-反馈
    DSKE(FANZHU),          //WEI014     曹丕-放逐
    DSKE(FEIYING),          //LE005      曹操-飞影
    DSKE(FUHUN),           //YJ104      关兴&张苞-父魂
    DSKE(FULI),            //YJ107      廖化-伏枥
    DSKE(GANGLIE),         //WEI003     夏侯惇-刚烈
    DSKE(GANLU),           //YJ007      吴国太-甘露
    DSKE(GONGJI),          //YJ105      韩当-弓骑
    DSKE(GONGXIN),         //LE002      吕蒙-攻心
    DSKE(GUANXING),        //SHU004     诸葛亮-观星
    DSKE(GUHUO),           //QUN011     于吉-蛊惑
    DSKE(GUICAI),          //WEI002     司马懿-鬼才
    DSKE(GUIDAO),          //QUN010     张角-鬼道
    DSKE(GUIXIN),          //LE005      曹操-归心
    DSKE(GUOSE),           //WU006      大乔-国色
    DSKE(GUZHENG),         //WU015      张昭&张纮-固政
    DSKE(HAOSHI),          //WU014      鲁肃-好施
    DSKE(HONGYAN),         //WU011      小乔-红颜
    DSKE(HONGYUAN),        //VS001      诸葛瑾-弘援
    DSKE(HUANGTIAN),       //QUN010     张角-[黄天]
    DSKE(HUANSHI),         //VS001      诸葛瑾-缓释
    DSKE(HUASHEN),         //QUN009     左慈-化身
    DSKE(HUILEI),          //YJ006      马谡-挥泪
    DSKE(HUJIA),           //WEI001     曹操-[护驾]
    DSKE(HUNZHI),          //WU010      孙策-魂姿
    DSKE(HUOJI),           //SHU011     诸葛亮-火计
    DSKE(HUOSHOU),         //SHU014     孟获-祸首
    DSKE(JIANG),           //WU010      孙策-激昂
    DSKE(JIANGCHI),        //YJ102      曹彰-将驰
    DSKE(JIANXIONG),       //WEI001     曹操-奸雄
    DSKE(JIE),             //XSP005     张飞-嫉恶
    DSKE(JIEFAN),          //YJ105      韩当-解烦
    DSKE(JIEMING),         //WEI013     荀彧-节命
    DSKE(JIEYIN),          //WU008      孙尚香-结姻
    DSKE(JIJIANG),         //SHU001     刘备-[激将]
    DSKE(JIJIU),           //QUN001     华佗-急救
    DSKE(JILEI),           //SP001      杨修-鸡肋
    DSKE(JINJIU),          //YJ004      高顺-禁酒
    DSKE(JIUCHI),          //QUN006     董卓-酒池
    DSKE(JIUSHI),          //YJ001      曹植-酒诗
    DSKE(JIUYUAN),         //WU001      孙权-[救援]
    DSKE(JIZHI),           //SHU007     黄月英-集智
    DSKE(JUEJING),         //LE007      赵云-绝境
    DSKE(JUEQING),         //YJ011      张春华-绝情
    DSKE(JUJIAN),          //YJ009      徐庶-举荐
    DSKE(JUSHOU),          //WEI011     曹仁-据守
    DSKE(JUXIANG),         //SHU015     祝融-巨象
    DSKE(KANPO),           //SHU011     诸葛亮-看破
    DSKE(KEJI),            //WU003      吕蒙-克己
    DSKE(KONGCHENG),       //SHU004     诸葛亮-空城
    DSKE(KUANGBAO),        //LE006      吕布-狂暴
    DSKE(KUANGFENG),       //LE004      诸葛亮-狂风
    DSKE(KUANGGU),         //SHU009     魏延-狂骨
    DSKE(KUIWEI),          //XSP003     曹仁-溃围
    DSKE(KUROU),           //WU004      黄盖-苦肉
    DSKE(LEIJI),           //QUN010     张角-雷击
    DSKE(LIANHUAN),        //SHU010     庞统-连环
    DSKE(LIANPO),          //LE008      司马懿-连破
    DSKE(LIANYING),        //WU007      陆逊-连营
    DSKE(LIEGONG),         //SHU008     黄忠-烈弓
    DSKE(LIEREN),          //SHU015     祝融-烈刃
    DSKE(LIHUN),           //XSP002     貂蝉-离魂
    DSKE(LIHUO),           //YJ103      程普-疠火
    DSKE(LIJIAN),          //QUN003     貂蝉-离间
    DSKE(LIULI),           //WU006      大乔-流离
    DSKE(LONGDAN),         //SHU005     赵云-龙胆
    DSKE(LONGHUN),         //LE007      赵云-龙魂
    DSKE(LUANJI),          //QUN004     袁绍-乱击
    DSKE(LUANWU),          //QUN007     贾诩-乱武
    DSKE(LUOSHEN),         //WEI007     甄姬-洛神
    DSKE(LUOYI),           //WEI005     许褚-裸衣
    DSKE(LUOYING),         //YJ001      曹植-落英
    DSKE(MANJUAN),         //XSP004     庞统-漫卷
    DSKE(MASHU),           //SHU006     马超-马术
    DSKE(MENGJIN),         //QUN008     庞德-猛进
    DSKE(MIJI),            //YJ110      王异-秘计
    DSKE(MINGCE),          //YJ002      陈宫-明策
    DSKE(MINGZHE),         //VS001      诸葛瑾-明哲
    DSKE(MOUDAN),          //XSP006     吕蒙-谋断
    DSKE(NIEPAN),          //SHU010     庞统-涅槃
    DSKE(PAOXIAO),         //SHU003     张飞-咆哮
    DSKE(POJUN),           //YJ008      徐盛-破军
    DSKE(QIANGXI),         //WEI012     典韦-强袭
    DSKE(QIANXI),          //YJ109      马岱-潜袭
    DSKE(QIANXUN),         //WU007      陆逊-谦逊
    DSKE(QIAOBIAN),        //WEI009     张郃-巧变
    DSKE(QICAI),           //SHU007     黄月英-奇才
    DSKE(QICE),            //YJ111      荀攸-奇策
    DSKE(QINGGUO),         //WEI007     甄姬-倾国
    DSKE(QINGNANG),        //QUN001     华佗-青囊
    DSKE(QINYIN),          //LE003      周瑜-琴音
    DSKE(QIXI),            //WU002      甘宁-奇袭
    DSKE(QIXING),          //LE004      诸葛亮-七星
    DSKE(QUANJI),          //YJ012      钟会-权计
    DSKE(QUHU),            //WEI013     荀彧-驱虎
    DSKE(RENDE),           //SHU001     刘备-仁德
    DSKE(RENJIE),          //LE008      司马懿-忍戒
    DSKE(ROULIN),          //QUN006     董卓-肉林
    DSKE(RUOYU),           //SHU013     刘禅-[若愚]
    DSKE(SHANGSHI),        //YJ011      张春华-伤逝
    DSKE(SHELIE),          //LE002      吕蒙-涉猎
    DSKE(SHENFEN),         //LE006      吕布-神愤
    DSKE(SHENJI),          //SP008      吕布-神戟
    DSKE(SHENSU),          //WEI008     夏侯渊-神速
    DSKE(SHENWEI),         //SP008      吕布-神威
    DSKE(SHIYONG),         //YJ106      华雄-恃勇
    DSKE(SHUANGXIOANG),    //QUN005     颜良&文丑-双雄
    DSKE(SONGWEI),         //WEI014     曹丕-[颂威]
    DSKE(TANHU),           //XSP006     吕蒙-探虎
    DSKE(TIANDU),          //WEI006     郭嘉-天妒
    DSKE(TIANXIANG),        //WU011      小乔-天香
    DSKE(TIANYI),          //WU012      太史慈-天义
    DSKE(TIAOXIN),         //SHU012     姜维-挑衅
    DSKE(TIEJI),           //SHU006     马超-铁骑
    DSKE(TUNTIAN),         //WEI015     邓艾-屯田
    DSKE(TUXI),            //WEI004     张辽-突袭
    DSKE(WANSHA),          //QUN007     贾诩-完杀
    DSKE(WEIDI),           //SP004      袁术-伪帝
    DSKE(WEIMU),           //QUN007     贾诩-帷幕
    DSKE(WUHUN),           //LE001      关羽-武魂
    DSKE(WUMOU),           //LE006      吕布-无谋
    DSKE(WUQIAN),          //LE006      吕布-无前
    DSKE(WUSHEN),          //LE001      关羽-武神
    DSKE(WUSHENG),         //SHU002     关羽-武圣
    DSKE(WUSHUANG),        //QUN002     吕布-无双
    DSKE(WUYAN),           //YJ009      徐庶-无言
    DSKE(XIANGLE),         //SHU013     刘禅-享乐
    DSKE(XIANZHEN),        //YJ004      高顺-陷阵
    DSKE(XIAOJI),          //WU008      孙尚香-枭姬
    DSKE(XINGSHUANG),      //WEI014     曹丕-行殇
    DSKE(XINSHENG),        //QUN009     左慈-新生
    DSKE(XINZHAN),         //YJ006      马谡-心战
    DSKE(XIULUO),          //SP008      吕布-修罗
    DSKE(XUANFENG),        //YJ005      凌统-旋风
    DSKE(XUANHUO),         //YJ003      法正-眩惑
    DSKE(XUEYI),           //QUN004     袁绍-[血裔]
    DSKE(YANZHENG),        //XSP003     曹仁-严整
    DSKE(YEYAN),           //LE003      周瑜-业炎
    DSKE(YICONG),          //SP003      公孙瓒-义从
    DSKE(YIJI),            //WEI006     郭嘉-遗计
    DSKE(YINGHUN),         //WU009      孙坚-英魂
    DSKE(YINGZI),          //WU005      周瑜-英姿
    DSKE(YIZHONG),         //YJ010      于禁-毅重
    DSKE(YONGSI),          //SP004      袁术-庸肆
    DSKE(ZAIQI),           //SHU014     孟获-再起
    DSKE(ZAOXIAN),         //WEI015     邓艾-凿险
    DSKE(ZHENLIE),         //YJ110      王异-贞烈
    DSKE(ZHIBA),           //WU010      孙策-[制霸]
    DSKE(ZHICHI),          //YJ002      陈宫-智迟
    DSKE(ZHIHENG),         //WU001      孙权-制衡
    DSKE(ZHIJI),           //SHU012     姜维-志继
    DSKE(ZHIJIAN),         //WU015      张昭&张纮-直谏
    DSKE(ZHIYU),           //YJ111      荀攸-智愚
    DSKE(ZHUIYI),          //YJ101      步练师-追忆
    DSKE(ZILI),            //YJ012      钟会-自立(排异)
    DSKE(ZISHOU),          //YJ108      刘表-自守
    DSKE(ZONGSHI),         //YJ108      刘表-宗室
    DSKE(ZUIXIANG),        //XSP004     庞统-醉乡
    
    DSKE(CHENGXIANG),      //YJ201      曹冲-称象
    DSKE(RENXIN),          //YJ201      曹冲-仁心
    DSKE(ZHUIKONG),        //YJ202      伏皇后-惴恐
    DSKE(QIUYUAN),         //YJ202      伏皇后-求援
    DSKE(LONGYIN),         //YJ203      关平-龙吟
    DSKE(JINGCE),          //YJ204      郭淮-精策
    DSKE(QIAOSHUI),        //YJ205      简雍-巧说
    DSKE(ZONGSHI_JY),      //YJ205      简雍-纵适
    DSKE(JUECE),           //YJ206      李儒-绝策
    DSKE(MIEJI),           //YJ206      李儒-灭计
    DSKE(FENCHENG),        //YJ206      李儒-焚城
    DSKE(XIANSI),          //YJ207      刘封-陷嗣
    DSKE(JUNXING),         //YJ208      满宠-峻刑
    DSKE(YUCE),            //YJ208      满宠-御策
    DSKE(DUODAO),          //YJ209      潘璋&马忠-夺刀
    DSKE(ANJIAN),          //YJ209      潘璋&马忠-暗箭
    DSKE(ZONGXUAN),        //YJ210      虞翻-纵玄
    DSKE(ZHIYAN),          //YJ210      虞翻-直言
    DSKE(DANSHOU),         //YJ211      朱然-胆守
    DSKE(XINGWU),          //SP021      大乔&小乔-星舞
    DSKE(YANLUO)           //SP021      大乔&小乔-雁落
    
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

    const skill_entry_t *pskill = wsg_skill_entries[skid];
    std::map<fsm_status_t, Skills> *pfs;
    Skill* skill = new Skill();
    skill->entry = pskill;
    skill->player = plr;
    skill->sr = this;
    _skills.push_back(skill);

    for (int i = 0; i < pskill->chance_cnt; ++i) {
        skill_object_type_t objt = pskill->chances[i].object;
        switch(objt) {
            case JNT_SELF:
                pfs = (*this)[plr];
                ((*pfs)[pskill->chances[i].chance]).push_back(skill);
                break;
            case JNT_OTHER:
            case JNT_ALL:
            case JNT_SIB:
                for (int p = 0; p < this->_game->players.size(); ++p) {
                    if (objt == JNT_ALL || (objt == JNT_OTHER && p != plr) || (objt == JNT_SIB && 0)) {
                        pfs = (*this)[plr];
                        ((*pfs)[pskill->chances[i].chance]).push_back(skill);
                    }
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