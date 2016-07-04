//
//  hero.cpp
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright {c) 2015年 老虎宝典. All rights reserved.
//

#include "hero.h"


#include <set>
#include <string>



WSG_BEGIN

const hero_model_t wsg_hero_entries[] = {
{HERO_NONE,},

    // qun xiong
{QUN001, "华佗", true, 3, SL_QUN, {JN_JIJIU, JN_QINGNANG}, "神医", "乱世名医", FX_NORMAL},
{QUN002, "吕布", true, 4, SL_QUN, {JN_WUSHUANG,}, "武的化身", "飞将", FX_NORMAL},
{QUN003, "貂蝉", false, 3, SL_QUN, {JN_LIJIAN, JN_BIYUE}, "绝世的舞姬", "倾国倾城", FX_NORMAL},
{QUN004, "袁绍", true, 4, SL_QUN, {JN_LUANJI,}, "高贵的名门", "乱箭肃敌", FX_FIRE},
{QUN005, "颜良&文丑", true, 4, SL_QUN, {JN_SHUANGXIOANG,}, "虎狼兄弟", "其利断金", FX_FIRE},
{QUN006, "董卓", true, 8, SL_QUN, {JN_JIUCHI, JN_ROULIN, JN_BENGHUAI, JN_BAONVE}, "魔王", "肉山", FX_FOREST},
{QUN007, "贾诩", true, 3, SL_QUN, {JN_WANSHA, JN_LUANWU, JN_WEIMU}, "冷酷的毒士", "算无遗策", FX_FOREST},
{QUN008, "庞德", true, 4, SL_QUN, {JN_MENGJIN, JN_MASHU}, "人马一体", "周苛之节", FX_FIRE},
{QUN009, "左慈", true, 3, SL_QUN, {JN_HUASHEN, JN_XINSHENG}, "谜之仙人", "", FX_MOUNT},
{QUN010, "张角", true, 3, SL_QUN, {JN_LEIJI, JN_GUIDAO, JN_HUANGTIAN}, "天公将军", "狂奔的蜗牛", FX_WIND},
{QUN011, "于吉", true, 3, SL_QUN, {JN_GUHUO,}, "太平道人", "神鬼莫测", FX_WIND},
{QUN012, "蔡文姬", false, 3, SL_QUN, {JN_BEIGE, JN_DUANCHANG}, "异乡的孤女", "", FX_MOUNT},

    // wei
{WEI001, "曹操", true, 4, SL_WEI, {JN_JIANXIONG,}, "魏武帝", "乱世的奸雄", FX_NORMAL},
{WEI002, "司马懿", true, 3, SL_WEI, {JN_FANKUI, JN_GUICAI}, "狼顾之鬼", "手眼通天", FX_NORMAL},
{WEI003, "夏侯惇", true, 4, SL_WEI, {JN_GANGLIE,}, "独眼的罗刹", "你死我活", FX_NORMAL},
{WEI004, "张辽", true, 4, SL_WEI, {JN_TUXI,}, "前将军", "掩其无备", FX_NORMAL},
{WEI005, "许褚", true, 4, SL_WEI, {JN_LUOYI,}, "虎痴", "妈，我冷", FX_NORMAL},
{WEI006, "郭嘉", true, 3, SL_WEI, {JN_TIANDU, JN_YIJI}, "早终的先知", "不遗余力", FX_NORMAL},
{WEI007, "甄姬", false, 3, SL_WEI, {JN_LUOSHEN, JN_QINGGUO}, "薄幸的美人", "洛神赋", FX_NORMAL},
{WEI008, "夏侯渊", true, 4, SL_WEI, {JN_SHENSU,}, "疾行的猎豹", "风驰电掣", FX_WIND},
{WEI009, "张郃", true, 4, SL_WEI, {JN_QIAOBIAN,}, "料敌机先", "", FX_MOUNT},
{WEI010, "徐晃", true, 4, SL_WEI, {JN_DUANLIANG,}, "周亚夫之风", "粮尽援绝", FX_FOREST},
{WEI011, "曹仁", true, 4, SL_WEI, {JN_JUSHOU,}, "大将军", "固若金汤", FX_WIND},
{WEI012, "典韦", true, 4, SL_WEI, {JN_QIANGXI,}, "古之恶来", "一夫当关", FX_FIRE},
{WEI013, "荀彧", true, 3, SL_WEI, {JN_QUHU, JN_JIEMING}, "王佐之才", "驱虎吞狼", FX_FIRE},
{WEI014, "曹丕", true, 3, SL_WEI, {JN_XINGSHUANG, JN_FANZHU, JN_SONGWEI}, "霸业的继承者", "魏文帝", FX_FOREST},
{WEI015, "邓艾", true, 4, SL_WEI, {JN_TUNTIAN, JN_ZAOXIAN}, "矫然的壮士", "", FX_MOUNT},

    // shu
{SHU001, "刘备", true, 4, SL_SHU, {JN_RENDE, JN_JIJIANG}, "乱世的枭雄", "纠结之心", FX_NORMAL},
{SHU002, "关羽", true, 4, SL_SHU, {JN_WUSHENG,}, "美髯公", "武圣显灵", FX_NORMAL},
{SHU003, "张飞", true, 4, SL_SHU, {JN_PAOXIAO,}, "万夫不当", "燕人的咆哮", FX_NORMAL},
{SHU004, "诸葛亮", true, 3, SL_SHU, {JN_GUANXING, JN_KONGCHENG}, "迟暮的丞相", "空城绝唱", FX_NORMAL},
{SHU005, "赵云", true, 4, SL_SHU, {JN_LONGDAN,}, "少年将军", "浑身是胆", FX_NORMAL},
{SHU006, "马超", true, 4, SL_SHU, {JN_TIEJI, JN_MASHU}, "一骑当千", "全军突击", FX_NORMAL},
{SHU007, "黄月英", false, 3, SL_SHU, {JN_JIZHI, JN_QICAI}, "归隐的杰女", "锦囊袋", FX_NORMAL},
{SHU008, "黄忠", true, 4, SL_SHU, {JN_LIEGONG,}, "老当益壮", "老将的逆袭", FX_WIND},
{SHU009, "魏延", true, 4, SL_SHU, {JN_KUANGGU,}, "嗜血的独狼", "嗜血成性", FX_WIND},
{SHU010, "庞统", true, 4, SL_SHU, {JN_LIANHUAN, JN_NIEPAN}, "凤雏", "铁锁连舟", FX_FIRE},
{SHU011, "诸葛亮", true, 3, SL_SHU, {JN_BAZHEN, JN_HUOJI, JN_KANPO}, "卧龙", "天火燎原", FX_FIRE},
{SHU012, "姜维", true, 4, SL_SHU, {JN_TIAOXIN, JN_ZHIJI}, "龙的衣钵", "", FX_MOUNT},
{SHU013, "刘禅", true, 3, SL_SHU, {JN_XIANGLE, JN_FANGQUAN, JN_RUOYU}, "无为的真命主", "", FX_MOUNT},
{SHU014, "孟获", true, 4, SL_SHU, {JN_HUOSHOU, JN_ZAIQI}, "南蛮王", "七擒七纵", FX_FOREST},
{SHU015, "祝融", false, 4, SL_SHU, {JN_JUXIANG, JN_LIEREN}, "野性的女王", "刺美人", FX_FOREST},

    // wu
{WU001, "孙权", true, 4, SL_WU, {JN_ZHIHENG, JN_JIUYUAN}, "年轻的贤君", "老不死的", FX_NORMAL},
{WU002, "甘宁", true, 4, SL_WU, {JN_QIXI,}, "锦帆游侠", "神出鬼没", FX_NORMAL},
{WU003, "吕蒙", true, 4, SL_WU, {JN_KEJI,}, "白衣渡江", "伺机待发", FX_NORMAL},
{WU004, "黄盖", true, 4, SL_WU, {JN_KUROU,}, "轻身为国", "无尽的鞭挞", FX_NORMAL},
{WU005, "周瑜", true, 3, SL_WU, {JN_YINGZI, JN_FANJIAN}, "大都督", "无尽的挣扎", FX_NORMAL},
{WU006, "大乔", false, 3, SL_WU, {JN_GUOSE, JN_LIULI}, "矜持之花", "移花接木", FX_NORMAL},
{WU007, "陆逊", true, 3, SL_WU, {JN_QIANXUN, JN_LIANYING}, "儒生雄才", "连绵不绝", FX_NORMAL},
{WU008, "孙尚香", false, 3, SL_WU, {JN_JIEYIN, JN_XIAOJI}, "弓腰姬", "因祸得福", FX_NORMAL},
{WU009, "孙坚", true, 4, SL_WU, {JN_YINGHUN,}, "武烈帝", "破掳大将军", FX_FOREST},
{WU010, "孙策", true, 4, SL_WU, {JN_JIANG, JN_HUNZHI, JN_ZHIBA}, "江东的小霸王", "", FX_MOUNT},
{WU011, "小乔", false, 3, SL_WU, {JN_TIANXIANG, JN_HONGYAN}, "矫情之花", "怜香惜玉", FX_WIND},
{WU012, "太史慈", true, 4, SL_WU, {JN_TIANYI,}, "笃烈之士", "江东之虎", FX_FIRE},
{WU013, "周泰", true, 4, SL_WU, {JN_BUQU,}, "历战之躯", "金枪不倒", FX_WIND},
{WU014, "鲁肃", true, 3, SL_WU, {JN_HAOSHI, JN_DIMENG}, "独断的外交家", "指囷相赠", FX_FOREST},
{WU015, "张昭&张纮", true, 3, SL_WU, {JN_ZHIJIAN, JN_GUZHENG}, "经天纬地", "", FX_MOUNT},
    
    // god
{LE001, "关羽", true, 5, SL_GOD, {JN_WUSHEN, JN_WUHUN}, "鬼神再临", "炼狱武神", FX_WIND},
{LE002, "吕蒙", true, 3, SL_GOD, {JN_SHELIE, JN_GONGXIN}, "圣光之国士", "洞察一切", FX_WIND},
{LE003, "周瑜", true, 4, SL_GOD, {JN_QINYIN, JN_YEYAN}, "赤壁的火神", "红莲业火", FX_FIRE},
{LE004, "诸葛亮", true, 3, SL_GOD, {JN_QIXING, JN_KUANGFENG, JN_DAWU}, "赤壁的妖术师", "换斗移星", FX_FIRE},
{LE005, "曹操", true, 3, SL_GOD, {JN_GUIXIN, JN_FEIYING}, "超世之英杰", "天下归心", FX_FOREST},
{LE006, "吕布", true, 5, SL_GOD, {JN_KUANGBAO, JN_WUMOU, JN_WUQIAN, JN_SHENFEN}, "修罗之道", "神鬼无双", FX_FOREST},
{LE007, "赵云", true, 2, SL_GOD, {JN_JUEJING, JN_LONGHUN}, "神威如龙", "", FX_MOUNT},
{LE008, "司马懿", true, 4, SL_GOD, {JN_RENJIE, JN_BAIYIN, JN_LIANPO}, "晋国之祖", "", FX_MOUNT},

    // yi jiang 1
{YJ001, "曹植", true, 3, SL_WEI, {JN_LUOYING, JN_JIUSHI}, "八斗之才", "八斗之才", FX_GENERAL1},
{YJ002, "陈宫", true, 3, SL_QUN, {JN_MINGCE, JN_ZHICHI}, "刚直壮烈", "", FX_GENERAL1},
{YJ003, "法正", true, 3, SL_SHU, {JN_ENYUAN, JN_XUANHUO}, "蜀汉的辅翼", "蜀汉的辅翼", FX_GENERAL1},
{YJ004, "高顺", true, 4, SL_QUN, {JN_XIANZHEN, JN_JINJIU}, "攻无不克", "攻无不克", FX_GENERAL1},
{YJ005, "凌统", true, 4, SL_WU, {JN_XUANFENG,}, "豪情烈胆", "", FX_GENERAL1},
{YJ006, "马谡", true, 3, SL_SHU, {JN_XINZHAN,JN_HUILEI}, "怀才自负", "怀才自负", FX_GENERAL1},
{YJ007, "吴国太", false, 3, SL_WU, {JN_GANLU, JN_BUYI}, "武烈皇后", "武烈皇后", FX_GENERAL1},
{YJ008, "徐盛", true, 4, SL_WU, {JN_POJUN,}, "江东的铁壁", "江东的铁壁", FX_GENERAL1},
{YJ009, "徐庶", true, 3, SL_SHU, {JN_WUYAN, JN_JUJIAN}, "忠孝的侠士", "忠孝的侠士", FX_GENERAL1},
{YJ010, "于禁", true, 4, SL_WEI, {JN_YIZHONG,}, "魏武之刚", "魏武之刚", FX_GENERAL1},
{YJ011, "张春华", false, 3, SL_WEI, {JN_JUEQING, JN_SHANGSHI}, "冷血皇后", "冷血皇后", FX_GENERAL1},
{YJ012, "钟会", true, 4, SL_WEI, {JN_QUANJI, JN_ZILI}, "桀骜的野心家", "", FX_GENERAL2},

    // yi jiang 2
{YJ101, "步练师", false, 3, SL_WU, {JN_ANXU,JN_ZHUIYI}, "无冕之后", "", FX_GENERAL2},
{YJ102, "曹彰", true, 4, SL_WEI, {JN_JIANGCHI,}, "黄须儿", "", FX_GENERAL2},
{YJ103, "程普", true, 4, SL_WU, {JN_LIHUO,JN_CHUNLAO}, "三朝虎臣", "", FX_GENERAL2},
{YJ104, "关兴&张苞", true, 4, SL_SHU, {JN_FUHUN,}, "将门虎子", "", FX_GENERAL2},
{YJ105, "韩当", true, 4, SL_WU, {JN_GONGJI,JN_JIEFAN}, "石城侯", "", FX_GENERAL2},
{YJ106, "华雄", true, 6, SL_QUN, {JN_SHIYONG,}, "魔将", "", FX_GENERAL2},
{YJ107, "廖化", true, 4, SL_SHU, {JN_DANGXIAN,JN_FULI}, "历尽沧桑", "", FX_GENERAL2},
{YJ108, "刘表", true, 4, SL_QUN, {JN_ZISHOU,JN_ZONGSHI}, "跨蹈汉南", "", FX_GENERAL2},
{YJ109, "马岱", true, 4, SL_SHU, {JN_MASHU,JN_QIANXI}, "临危受命", "", FX_GENERAL2},
{YJ110, "王异", false, 3, SL_WEI, {JN_ZHENLIE,JN_MIJI}, "决意的巾帼", "", FX_GENERAL2},
{YJ111, "荀攸", true, 3, SL_WEI, {JN_QICE,JN_ZHIYU}, "曹魏的谋主", "", FX_GENERAL2},
    
    // yi jiang 3
{YJ201, "曹冲", true, 3, SL_WEI, {JN_CHENGXIANG,JN_RENXIN,}, "仁爱的神童", "", FX_GENERAL3},
{YJ202, "伏皇后", false, 3, SL_QUN, {JN_ZHUIKONG,JN_QIUYUAN}, "孤注一掷", "", FX_GENERAL3},
{YJ203, "关平", true, 4, SL_SHU, {JN_LONGYIN,}, "忠臣孝子", "", FX_GENERAL3},
{YJ204, "郭淮", true, 4, SL_WEI, {JN_JINGCE,}, "垂问秦雍", "", FX_GENERAL3},
{YJ205, "简雍", true, 3, SL_SHU, {JN_QIAOSHUI,JN_ZONGSHI_JY}, "优游风议", "", FX_GENERAL3},
{YJ206, "李儒", true, 3, SL_QUN, {JN_JUECE, JN_MIEJI, JN_FENCHENG}, "魔仕", "", FX_GENERAL3},
{YJ207, "刘封", true, 4, SL_SHU, {JN_XIANSI,}, "骑虎之殇", "", FX_GENERAL3},
{YJ208, "满宠", true, 3, SL_WEI, {JN_JUNXING,JN_YUCE}, "政法兵谋", "", FX_GENERAL3},
{YJ209, "潘璋&马忠", true, 4, SL_WU, {JN_DUODAO,JN_ANJIAN}, "擒龙伏虎", "", FX_GENERAL3},
{YJ210, "虞翻", true, 3, SL_WU, {JN_ZONGXUAN,JN_ZHIYAN}, "狂直之士", "", FX_GENERAL3},
{YJ211, "朱然", true, 4, SL_WU, {JN_DANSHOU,}, "不动之督", "", FX_GENERAL3},


    // SP
//{SP001,},
{SP002, "貂蝉", false, 3, SL_QUN, {JN_LIJIAN, JN_BIYUE}, "绝世的舞姬", "", FX_DESKTOP},
{SP003, "公孙瓒", true, 4, SL_QUN, {JN_YICONG,}, "白马将军", "白马义从", FX_DESKTOP},
{SP004, "袁术", true, 4, SL_QUN, {JN_YONGSI, JN_WEIDI}, "仲家帝", "四世三公", FX_DESKTOP},
{SP005, "孙尚香", false, 3, SL_SHU, {JN_JIEYIN, JN_XIAOJI}, "梦醉良缘", "梦醉良缘", FX_DESKTOP},
{SP006, "庞德", true, 4, SL_WEI, {JN_MASHU, JN_MENGJIN}, "抬榇之悟", "抬榇之悟", FX_DESKTOP},
{SP007, "关羽", true, 4, SL_WEI, {JN_WUSHENG, JN_MASHU}, "汉寿亭侯", "", FX_DESKTOP},
{SP008_1, "吕布", true, 8, SL_GOD, {JN_MASHU, JN_WUSHUANG}, "最强神话", "", FX_DESKTOP},
{SP008_2, "吕布", true, 4, SL_GOD, {JN_MASHU, JN_WUSHUANG, JN_XIULUO, JN_SHENWEI, JN_SHENJI,}, "暴怒的战神", "", FX_DESKTOP},
{SP009, "蔡文姬", false, 3, SL_WEI, {JN_BEIGE, JN_DUANCHANG}, "金璧之才", "", FX_DESKTOP},
{SP010, "杨修", true, 3, SL_WEI, {JN_DANLAO, JN_JILEI}, "恃才放旷", "", FX_DESKTOP},
{SP011, "马超", true, 4, SL_QUN, {JN_MASHU, JN_TIEJI}, "西凉的猛狮", "西凉的猛狮", FX_DESKTOP},
{SP012, "贾诩", true, 3, SL_WEI, {JN_WANSHA, JN_LUANWU, JN_WEIMU}, "算无遗策", "绝杀", FX_DESKTOP},
    
{SP021, "大乔&小乔", false, 3, SL_WU, {JN_XINGWU, JN_YANLUO}, "天香国色", "江东之花", FX_DESKTOP},
    
{XSP001, "赵云", true, 3, SL_QUN, {JN_LONGDAN, JN_CHONGZHEN}, "白马先锋", "白马先锋", FX_DESKTOP},
{XSP002, "貂蝉", false, 3, SL_QUN, {JN_LIHUN, JN_BIYUE}, "暗黑的傀儡师", "暗黑的傀儡师", FX_DESKTOP},
{XSP003, "曹仁", true, 4, SL_WEI, {JN_KUIWEI, JN_YANZHENG}, "险不辞难", "险不辞难", FX_DESKTOP},
{XSP004, "庞统", true, 3, SL_QUN, {JN_MANJUAN, JN_ZUIXIANG}, "荆楚之高俊", "", FX_DESKTOP},
{XSP005, "张飞", true, 4, SL_SHU, {JN_JIE, JN_DAHE}, "横矛立马", "", FX_DESKTOP},
{XSP006, "吕蒙", true, 3, SL_WU, {JN_TANHU, JN_MOUDAN}, "国士之风", "", FX_DESKTOP},
    //
{VS001, "诸葛瑾", true, 3, SL_WU, {JN_HUANSHI, JN_HONGYUAN, JN_MINGZHE}, "联盟的维系者", "联盟的维系者", FX_RACE},
    
{(hero_id_t)0,}// zero triple is useful in C++, but useless in python
};

//void
//test(){
//    printf("element len: %lu\nmax hero id:%d\n", csm_lenof(wsg_hero_entries), VS001);
//}



vector<string>* Hero::getHeroNamesByPackageID(package_mark_t pkm) {
    vector<string> *name_vec = new vector<string>;
    const hero_model_t *hm = wsg_hero_entries;
    set<string> names;

    pkm = (package_mark_t)(~(unsigned int)pkm);
    while ((++hm)->id) {
        if (pkm & hm->package) continue;
        names.insert(string(hm->name));
    }

    name_vec->assign(names.begin(), names.end());
    names.clear();
    
    return name_vec;
}




WSG_END