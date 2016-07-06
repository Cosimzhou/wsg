//
//  hero.cpp
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright {c) 2015年 Cosim Studio. All rights reserved.
//

#include "hero.h"

WSG_BEGIN



#define HMDEF(id,name,sex,bld,cnt,fm,ss,pk,sk,...)                              \
{id,name,sex,bld,SL_##cnt,sk,fm,ss,pk,#id,__VA_ARGS__}
#define SKS(...)                {__VA_ARGS__}
#define M                       true
#define F                       false

const hero_model_t wsg_hero_model_libs[] = {
//{HERO_NONE,},
// qun xiong
HMDEF(QUN001, "华佗", M, 3, QUN, "神医", "乱世名医", FX_NORMAL, SKS(JN_JIJIU, JN_QINGNANG),0),
HMDEF(QUN002, "吕布", M, 4, QUN, "武的化身", "飞将", FX_NORMAL, SKS(JN_WUSHUANG),0),
HMDEF(QUN003, "貂蝉", F, 3, QUN, "绝世的舞姬", "倾国倾城", FX_NORMAL, SKS(JN_LIJIAN, JN_BIYUE), 0),
HMDEF(QUN004, "袁绍", M, 4, QUN, "高贵的名门", "乱箭肃敌", FX_FIRE, SKS(JN_LUANJI, JN_XUEYI), 0),
HMDEF(QUN005, "颜良&文丑", M, 4, QUN, "虎狼兄弟", "其利断金", FX_FIRE, SKS(JN_SHUANGXIOANG), 0,1),
HMDEF(QUN006, "董卓", M, 8, QUN, "魔王", "肉山", FX_FOREST, SKS(JN_JIUCHI, JN_ROULIN, JN_BENGHUAI, JN_BAONVE), 0),
HMDEF(QUN007, "贾诩", M, 3, QUN, "冷酷的毒士", "算无遗策", FX_FOREST, SKS(JN_WANSHA, JN_LUANWU, JN_WEIMU), 0),
HMDEF(QUN008, "庞德", M, 4, QUN, "人马一体", "周苛之节", FX_FIRE, SKS(JN_MENGJIN, JN_MASHU), 0),
HMDEF(QUN009, "左慈", M, 3, QUN, "谜之仙人", "", FX_MOUNT, SKS(JN_HUASHEN, JN_XINSHENG), 0),
HMDEF(QUN010, "张角", M, 3, QUN, "天公将军", "狂奔的蜗牛", FX_WIND, SKS(JN_LEIJI, JN_GUIDAO, JN_HUANGTIAN), 0),
HMDEF(QUN011, "于吉", M, 3, QUN, "太平道人", "神鬼莫测", FX_WIND, SKS(JN_GUHUO), 0),
HMDEF(QUN012, "蔡文姬", F, 3, QUN, "异乡的孤女", "", FX_MOUNT, SKS(JN_BEIGE, JN_DUANCHANG), 0),
    
    // wei
HMDEF(WEI001, "曹操", M, 4, WEI, "魏武帝", "乱世的奸雄", FX_NORMAL, SKS(JN_JIANXIONG), 0),
HMDEF(WEI002, "司马懿", M, 3, WEI, "狼顾之鬼", "手眼通天", FX_NORMAL, SKS(JN_FANKUI, JN_GUICAI), 0),
HMDEF(WEI003, "夏侯惇", M, 4, WEI, "独眼的罗刹", "你死我活", FX_NORMAL, SKS(JN_GANGLIE), 0),
HMDEF(WEI004, "张辽", M, 4, WEI, "前将军", "掩其无备", FX_NORMAL, SKS(JN_TUXI), 0),
HMDEF(WEI005, "许褚", M, 4, WEI, "虎痴", "妈，我冷", FX_NORMAL, SKS(JN_LUOYI), 0),
HMDEF(WEI006, "郭嘉", M, 3, WEI, "早终的先知", "不遗余力", FX_NORMAL, SKS(JN_TIANDU, JN_YIJI), 0),
HMDEF(WEI007, "甄姬", F, 3, WEI, "薄幸的美人", "洛神赋", FX_NORMAL, SKS(JN_LUOSHEN, JN_QINGGUO), 0),
HMDEF(WEI008, "夏侯渊", M, 4, WEI, "疾行的猎豹", "风驰电掣", FX_WIND, SKS(JN_SHENSU), 0),
HMDEF(WEI009, "张郃", M, 4, WEI, "料敌机先", "", FX_MOUNT, SKS(JN_QIAOBIAN), 0),
HMDEF(WEI010, "徐晃", M, 4, WEI, "周亚夫之风", "粮尽援绝", FX_FOREST, SKS(JN_DUANLIANG), 0),
HMDEF(WEI011, "曹仁", M, 4, WEI, "大将军", "固若金汤", FX_WIND, SKS(JN_JUSHOU), 0),
HMDEF(WEI012, "典韦", M, 4, WEI, "古之恶来", "一夫当关", FX_FIRE, SKS(JN_QIANGXI), 0),
HMDEF(WEI013, "荀彧", M, 3, WEI, "王佐之才", "驱虎吞狼", FX_FIRE, SKS(JN_QUHU, JN_JIEMING), 0),
HMDEF(WEI014, "曹丕", M, 3, WEI, "霸业的继承者", "魏文帝", FX_FOREST, SKS(JN_XINGSHUANG, JN_FANZHU, JN_SONGWEI), 0),
HMDEF(WEI015, "邓艾", M, 4, WEI, "矫然的壮士", "", FX_MOUNT, SKS(JN_TUNTIAN, JN_ZAOXIAN), 0),
    
    // shu
HMDEF(SHU001, "刘备", M, 4, SHU, "乱世的枭雄", "纠结之心", FX_NORMAL, SKS(JN_RENDE, JN_JIJIANG), 0),
HMDEF(SHU002, "关羽", M, 4, SHU, "美髯公", "武圣显灵", FX_NORMAL, SKS(JN_WUSHENG), 0),
HMDEF(SHU003, "张飞", M, 4, SHU, "万夫不当", "燕人的咆哮", FX_NORMAL, SKS(JN_PAOXIAO), 0),
HMDEF(SHU004, "诸葛亮", M, 3, SHU, "迟暮的丞相", "空城绝唱", FX_NORMAL, SKS(JN_GUANXING, JN_KONGCHENG), 0),
HMDEF(SHU005, "赵云", M, 4, SHU, "少年将军", "浑身是胆", FX_NORMAL, SKS(JN_LONGDAN), 0),
HMDEF(SHU006, "马超", M, 4, SHU, "一骑当千", "全军突击", FX_NORMAL, SKS(JN_TIEJI, JN_MASHU), 0),
HMDEF(SHU007, "黄月英", F, 3, SHU, "归隐的杰女", "锦囊袋", FX_NORMAL, SKS(JN_JIZHI, JN_QICAI), 0),
HMDEF(SHU008, "黄忠", M, 4, SHU, "老当益壮", "老将的逆袭", FX_WIND, SKS(JN_LIEGONG), 0),
HMDEF(SHU009, "魏延", M, 4, SHU, "嗜血的独狼", "嗜血成性", FX_WIND, SKS(JN_KUANGGU), 0),
HMDEF(SHU010, "庞统", M, 4, SHU, "凤雏", "铁锁连舟", FX_FIRE, SKS(JN_LIANHUAN, JN_NIEPAN), 0),
HMDEF(SHU011, "诸葛亮", M, 3, SHU, "卧龙", "天火燎原", FX_FIRE, SKS(JN_BAZHEN, JN_HUOJI, JN_KANPO), 0),
HMDEF(SHU012, "姜维", M, 4, SHU, "龙的衣钵", "", FX_MOUNT, SKS(JN_TIAOXIN, JN_ZHIJI), 0),
HMDEF(SHU013, "刘禅", M, 3, SHU, "无为的真命主", "", FX_MOUNT, SKS(JN_XIANGLE, JN_FANGQUAN, JN_RUOYU), 0),
HMDEF(SHU014, "孟获", M, 4, SHU, "南蛮王", "七擒七纵", FX_FOREST, SKS(JN_HUOSHOU, JN_ZAIQI), 0),
HMDEF(SHU015, "祝融", F, 4, SHU, "野性的女王", "刺美人", FX_FOREST, SKS(JN_JUXIANG, JN_LIEREN), 0),
    
    // wu
HMDEF(WU001, "孙权", M, 4, WU, "年轻的贤君", "老不死的", FX_NORMAL, SKS(JN_ZHIHENG, JN_JIUYUAN), 0),
HMDEF(WU002, "甘宁", M, 4, WU, "锦帆游侠", "神出鬼没", FX_NORMAL, SKS(JN_QIXI), 0),
HMDEF(WU003, "吕蒙", M, 4, WU, "白衣渡江", "伺机待发", FX_NORMAL, SKS(JN_KEJI), 0),
HMDEF(WU004, "黄盖", M, 4, WU, "轻身为国", "无尽的鞭挞", FX_NORMAL, SKS(JN_KUROU), 0),
HMDEF(WU005, "周瑜", M, 3, WU, "大都督", "无尽的挣扎", FX_NORMAL, SKS(JN_YINGZI, JN_FANJIAN), 0),
HMDEF(WU006, "大乔", F, 3, WU, "矜持之花", "移花接木", FX_NORMAL, SKS(JN_GUOSE, JN_LIULI), 0),
HMDEF(WU007, "陆逊", M, 3, WU, "儒生雄才", "连绵不绝", FX_NORMAL, SKS(JN_QIANXUN, JN_LIANYING), 0),
HMDEF(WU008, "孙尚香", F, 3, WU, "弓腰姬", "因祸得福", FX_NORMAL, SKS(JN_JIEYIN, JN_XIAOJI), 0),
HMDEF(WU009, "孙坚", M, 4, WU, "武烈帝", "破掳大将军", FX_FOREST, SKS(JN_YINGHUN), 0),
HMDEF(WU010, "孙策", M, 4, WU, "江东的小霸王", "", FX_MOUNT, SKS(JN_JIANG, JN_HUNZHI, JN_ZHIBA), 0),
HMDEF(WU011, "小乔", F, 3, WU, "矫情之花", "怜香惜玉", FX_WIND, SKS(JN_TIANXIANG, JN_HONGYAN), 0),
HMDEF(WU012, "太史慈", M, 4, WU, "笃烈之士", "江东之虎", FX_FIRE, SKS(JN_TIANYI), 0),
HMDEF(WU013, "周泰", M, 4, WU, "历战之躯", "金枪不倒", FX_WIND, SKS(JN_BUQU), 0),
HMDEF(WU014, "鲁肃", M, 3, WU, "独断的外交家", "指囷相赠", FX_FOREST, SKS(JN_HAOSHI, JN_DIMENG), 0),
HMDEF(WU015, "张昭&张纮", M, 3, WU, "经天纬地", "", FX_MOUNT, SKS(JN_ZHIJIAN, JN_GUZHENG), 0, 1),
    
    // god
HMDEF(LE001, "关羽", M, 5, GOD, "鬼神再临", "炼狱武神", FX_WIND, SKS(JN_WUSHEN, JN_WUHUN), 0),
HMDEF(LE002, "吕蒙", M, 3, GOD, "圣光之国士", "洞察一切", FX_WIND, SKS(JN_SHELIE, JN_GONGXIN), 0),
HMDEF(LE003, "周瑜", M, 4, GOD, "赤壁的火神", "红莲业火", FX_FIRE, SKS(JN_QINYIN, JN_YEYAN), 0),
HMDEF(LE004, "诸葛亮", M, 3, GOD, "赤壁的妖术师", "换斗移星", FX_FIRE, SKS(JN_QIXING, JN_KUANGFENG, JN_DAWU), 0),
HMDEF(LE005, "曹操", M, 3, GOD, "超世之英杰", "天下归心", FX_FOREST, SKS(JN_GUIXIN, JN_FEIYING), 0),
HMDEF(LE006, "吕布", M, 5, GOD, "修罗之道", "神鬼无双", FX_FOREST, SKS(JN_KUANGBAO, JN_WUMOU, JN_WUQIAN, JN_SHENFEN), 0),
HMDEF(LE007, "赵云", M, 2, GOD, "神威如龙", "", FX_MOUNT, SKS(JN_JUEJING, JN_LONGHUN), 0),
HMDEF(LE008, "司马懿", M, 4, GOD, "晋国之祖", "", FX_MOUNT, SKS(JN_RENJIE, JN_BAIYIN, JN_LIANPO), 0),
    
    // yi jiang 1
HMDEF(YJ001, "曹植", M, 3, WEI, "八斗之才", "八斗之才", FX_GENERAL1, SKS(JN_LUOYING, JN_JIUSHI), 0),
HMDEF(YJ002, "陈宫", M, 3, QUN, "刚直壮烈", "", FX_GENERAL1, SKS(JN_MINGCE, JN_ZHICHI), 0),
HMDEF(YJ003, "法正", M, 3, SHU, "蜀汉的辅翼", "蜀汉的辅翼", FX_GENERAL1, SKS(JN_ENYUAN, JN_XUANHUO), 0),
HMDEF(YJ004, "高顺", M, 4, QUN, "攻无不克", "攻无不克", FX_GENERAL1, SKS(JN_XIANZHEN, JN_JINJIU), 0),
HMDEF(YJ005, "凌统", M, 4, WU, "豪情烈胆", "", FX_GENERAL1, SKS(JN_XUANFENG), 0),
HMDEF(YJ006, "马谡", M, 3, SHU, "怀才自负", "怀才自负", FX_GENERAL1, SKS(JN_XINZHAN,JN_HUILEI), 0),
HMDEF(YJ007, "吴国太", F, 3, WU, "武烈皇后", "武烈皇后", FX_GENERAL1, SKS(JN_GANLU, JN_BUYI), 0),
HMDEF(YJ008, "徐盛", M, 4, WU, "江东的铁壁", "江东的铁壁", FX_GENERAL1, SKS(JN_POJUN), 0),
HMDEF(YJ009, "徐庶", M, 3, SHU, "忠孝的侠士", "忠孝的侠士", FX_GENERAL1, SKS(JN_WUYAN, JN_JUJIAN), 0),
HMDEF(YJ010, "于禁", M, 4, WEI, "魏武之刚", "魏武之刚", FX_GENERAL1, SKS(JN_YIZHONG), 0),
HMDEF(YJ011, "张春华", F, 3, WEI, "冷血皇后", "冷血皇后", FX_GENERAL1, SKS(JN_JUEQING, JN_SHANGSHI), 0),
HMDEF(YJ012, "钟会", M, 4, WEI, "桀骜的野心家", "", FX_GENERAL2, SKS(JN_QUANJI, JN_ZILI), 0),
    
    // yi jiang 2
HMDEF(YJ101, "步练师", F, 3, WU, "无冕之后", "", FX_GENERAL2, SKS(JN_ANXU,JN_ZHUIYI), 0),
HMDEF(YJ102, "曹彰", M, 4, WEI, "黄须儿", "", FX_GENERAL2, SKS(JN_JIANGCHI), 0),
HMDEF(YJ103, "程普", M, 4, WU, "三朝虎臣", "", FX_GENERAL2, SKS(JN_LIHUO,JN_CHUNLAO), 0),
HMDEF(YJ104, "关兴&张苞", M, 4, SHU, "将门虎子", "", FX_GENERAL2, SKS(JN_FUHUN), 0, 1),
HMDEF(YJ105, "韩当", M, 4, WU, "石城侯", "", FX_GENERAL2, SKS(JN_GONGJI,JN_JIEFAN), 0),
HMDEF(YJ106, "华雄", M, 6, QUN, "魔将", "", FX_GENERAL2, SKS(JN_SHIYONG), 0),
HMDEF(YJ107, "廖化", M, 4, SHU, "历尽沧桑", "", FX_GENERAL2, SKS(JN_DANGXIAN,JN_FULI), 0),
HMDEF(YJ108, "刘表", M, 4, QUN, "跨蹈汉南", "", FX_GENERAL2, SKS(JN_ZISHOU,JN_ZONGSHI), 0),
HMDEF(YJ109, "马岱", M, 4, SHU, "临危受命", "", FX_GENERAL2, SKS(JN_MASHU,JN_QIANXI), 0),
HMDEF(YJ110, "王异", F, 3, WEI, "决意的巾帼", "", FX_GENERAL2, SKS(JN_ZHENLIE,JN_MIJI), 0),
HMDEF(YJ111, "荀攸", M, 3, WEI, "曹魏的谋主", "", FX_GENERAL2, SKS(JN_QICE,JN_ZHIYU), 0),
    
    // yi jiang 3
HMDEF(YJ201, "曹冲", M, 3, WEI, "仁爱的神童", "", FX_GENERAL3, SKS(JN_CHENGXIANG,JN_RENXIN), 0),
HMDEF(YJ202, "伏皇后", F, 3, QUN, "孤注一掷", "", FX_GENERAL3, SKS(JN_ZHUIKONG,JN_QIUYUAN), 0),
HMDEF(YJ203, "关平", M, 4, SHU, "忠臣孝子", "", FX_GENERAL3, SKS(JN_LONGYIN), 0),
HMDEF(YJ204, "郭淮", M, 4, WEI, "垂问秦雍", "", FX_GENERAL3, SKS(JN_JINGCE), 0),
HMDEF(YJ205, "简雍", M, 3, SHU, "优游风议", "", FX_GENERAL3, SKS(JN_QIAOSHUI,JN_ZONGSHI_JY), 0),
HMDEF(YJ206, "李儒", M, 3, QUN, "魔仕", "", FX_GENERAL3, SKS(JN_JUECE, JN_MIEJI, JN_FENCHENG), 0),
HMDEF(YJ207, "刘封", M, 4, SHU, "骑虎之殇", "", FX_GENERAL3, SKS(JN_XIANSI), 0),
HMDEF(YJ208, "满宠", M, 3, WEI, "政法兵谋", "", FX_GENERAL3, SKS(JN_JUNXING,JN_YUCE), 0),
HMDEF(YJ209, "潘璋&马忠", M, 4, WU, "擒龙伏虎", "", FX_GENERAL3, SKS(JN_DUODAO,JN_ANJIAN), 0,1),
HMDEF(YJ210, "虞翻", M, 3, WU, "狂直之士", "", FX_GENERAL3, SKS(JN_ZONGXUAN,JN_ZHIYAN), 0),
HMDEF(YJ211, "朱然", M, 4, WU, "不动之督", "", FX_GENERAL3, SKS(JN_DANSHOU), 0),
    
    
    // SP
//{SP001,},
HMDEF(SP002, "貂蝉", F, 3, QUN, "绝世的舞姬", "", FX_DESKTOP, SKS(JN_LIJIAN, JN_BIYUE), 0),
HMDEF(SP003, "公孙瓒", M, 4, QUN, "白马将军", "白马义从", FX_DESKTOP, SKS(JN_YICONG), 0),
HMDEF(SP004, "袁术", M, 4, QUN, "仲家帝", "四世三公", FX_DESKTOP, SKS(JN_YONGSI, JN_WEIDI), 0),
HMDEF(SP005, "孙尚香", F, 3, SHU, "梦醉良缘", "梦醉良缘", FX_DESKTOP, SKS(JN_JIEYIN, JN_XIAOJI), 0),
HMDEF(SP006, "庞德", M, 4, WEI, "抬榇之悟", "抬榇之悟", FX_DESKTOP, SKS(JN_MASHU, JN_MENGJIN), 0),
HMDEF(SP007, "关羽", M, 4, WEI, "汉寿亭侯", "", FX_DESKTOP, SKS(JN_WUSHENG, JN_MASHU), 0),
HMDEF(SP008_1, "吕布", M, 8, GOD, "最强神话", "", FX_DESKTOP, SKS(JN_MASHU, JN_WUSHUANG), 0),
HMDEF(SP008_2, "吕布", M, 4, GOD, "暴怒的战神", "", FX_DESKTOP, SKS(JN_MASHU, JN_WUSHUANG, JN_XIULUO, JN_SHENWEI, JN_SHENJI), 0),
HMDEF(SP009, "蔡文姬", F, 3, WEI, "金璧之才", "", FX_DESKTOP, SKS(JN_BEIGE, JN_DUANCHANG), 0),
HMDEF(SP010, "杨修", M, 3, WEI, "恃才放旷", "", FX_DESKTOP, SKS(JN_DANLAO, JN_JILEI), 0),
HMDEF(SP011, "马超", M, 4, QUN, "西凉的猛狮", "西凉的猛狮", FX_DESKTOP, SKS(JN_MASHU, JN_TIEJI), 0),
HMDEF(SP012, "贾诩", M, 3, WEI, "算无遗策", "绝杀", FX_DESKTOP, SKS(JN_WANSHA, JN_LUANWU, JN_WEIMU), 0),
    
HMDEF(SP021, "大乔&小乔", F, 3, WU, "天香国色", "江东之花", FX_DESKTOP, SKS(JN_XINGWU, JN_YANLUO), 0,1),
    
HMDEF(XSP001, "赵云", M, 3, QUN, "白马先锋", "白马先锋", FX_DESKTOP, SKS(JN_LONGDAN, JN_CHONGZHEN), 0),
HMDEF(XSP002, "貂蝉", F, 3, QUN, "暗黑的傀儡师", "暗黑的傀儡师", FX_DESKTOP, SKS(JN_LIHUN, JN_BIYUE), 0),
HMDEF(XSP003, "曹仁", M, 4, WEI, "险不辞难", "险不辞难", FX_DESKTOP, SKS(JN_KUIWEI, JN_YANZHENG), 0),
HMDEF(XSP004, "庞统", M, 3, QUN, "荆楚之高俊", "", FX_DESKTOP, SKS(JN_MANJUAN, JN_ZUIXIANG), 0),
HMDEF(XSP005, "张飞", M, 4, SHU, "横矛立马", "", FX_DESKTOP, SKS(JN_JIE, JN_DAHE), 0),
HMDEF(XSP006, "吕蒙", M, 3, WU, "国士之风", "", FX_DESKTOP, SKS(JN_TANHU, JN_MOUDAN), 0),
    //
HMDEF(VS001, "诸葛瑾", M, 3, WU, "联盟的维系者", "联盟的维系者", FX_RACE, SKS(JN_HUANSHI, JN_HONGYUAN, JN_MINGZHE), 0),
    
//{(hero_id_t)0,}// zero triple is useful in C++, but useless in python
};
#undef M
#undef F
#undef SKS
#undef HMDEF


const char *wsg_country_libs[] = {
    "无", "野心家", "群雄", "蜀", "魏", "吴", "神",
};

//FX_NONE             = 0,
//FX_NORMAL           = (1<<0),
//FX_WIND             = (1<<1),
//FX_FIRE             = (1<<2),
//FX_FOREST           = (1<<3),
//FX_MOUNT            = (1<<4),
//FX_GENERAL1         = (1<<5),
//FX_GENERAL2         = (1<<6),
//FX_GENERAL3         = (1<<7),
//FX_RACE             = (1<<8),
//FX_DESKTOP          = (1<<9),
//FX_TOP_NUM
const char *wsg_package_name_libs[] = {
    ""
};


IMP_FIND_ARRAY_FUNC(hero_model_t, wsg_hero_get_info_by_hid, hero_id_t, wsg_hero_model_libs, id);

//IMP_FIND_ARRAY_STRING_FUNC(hero_model_t, wsg_hero_find_by_name, wsg_hero_model_libs, name);
//
//const hero_model_t *wsg_hero_find_by_name(const char *name) {
//    for (int i = 0, len = __lenof__(wsg_hero_model_libs); i < len; ++i) {
//        if (strcmp(wsg_hero_model_libs[i].name, name) == 0) {
//            return wsg_hero_model_libs+i;
//        }
//    }
//    return NULL;
//}


vector<const hero_model_t*>
wsg_hero_v_find_by_name(const char *name) {
    char buff[100] = "&", *ptail;
    const char *phname;
    vector<const hero_model_t*> vhm;
    strcpy(buff+1, name);
    ptail = buff + strlen(buff);
    for (int i = 0, len = __lenof__(wsg_hero_model_libs); i < len; ++i) {
        phname = wsg_hero_model_libs[i].name;
        if (wsg_hero_model_libs[i].multihero) {
            if (strstr(phname, buff)) {
                vhm.push_back(wsg_hero_model_libs+i);
            } else {
                *ptail = '&';
                ptail[1] = 0;
                if (strstr(phname, buff+1) == phname)
                    vhm.push_back(wsg_hero_model_libs+i);
                *ptail = 0;
            }
        } else if (strcmp(phname, name) == 0) {
            vhm.push_back(wsg_hero_model_libs+i);
        }
    }
    return vhm;
}



void
wsg_hero_test_show() {
//    printf("element len: %lu\nmax hero id:%d\n", csm_lenof(wsg_hero_model_libs), VS001);
    
    for (hero_id_t i = (hero_id_t)1; i < TYN001; i = (hero_id_t)((int)i+1)) {
        const hero_model_t *phm = wsg_hero_get_info_by_hid(i);
        if (!phm) continue;
        cout<<phm->name<<endl<<phm->blood<<endl
            <<wsg_country_libs[phm->country]<<endl<<phm->fame<<endl;
        for (int j = 0; j < 16 && phm->skills[j]; ++j) {
            const skill_entry_t *pse = wsg_skill_get_info_by_skid(phm->skills[j]);
            cout<<pse->name<<"  ";
        }
        cout<<endl<<endl;
    }
}


vector<string>
Hero::getHeroNamesByPackageID(package_mark_t pkm) {
    vector<string> name_vec;// = new vector<string>;
    set<string> names;
    char buffer[100];
    const char *sp;
    
    pkm = (package_mark_t)(~(unsigned int)pkm);
    for (int i = 0, num = __lenof__(wsg_hero_model_libs); i < num; ++i) {
        const hero_model_t *hm = wsg_hero_model_libs+i;
        if (pkm & hm->package) continue;

        if ((sp = strstr(hm->name, "&")) != NULL) {
            names.insert(string(sp+1));
            strncpy(buffer, hm->name, sp-hm->name);
            buffer[sp-hm->name] = 0;
            names.insert(string(buffer));
        } else
            names.insert(string(hm->name));
    }

    name_vec.assign(names.begin(), names.end());
    names.clear();
    
    return name_vec;
}












WSG_END