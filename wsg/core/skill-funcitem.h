//
//  skill-funcitem.h
//  wsg
//
//  Created by 周志超 on 16/6/29.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#ifdef  __WSG__DECLARE__SKILL__LIST__H__
#   define __WSG__DECLARE__SKILL__LIST__H__
#   ifndef __WSG__SKILL__LIST__H__

#       define F(x,c)                          {FSM::x,c}
#       define FZ                              F(round_play,JNT_SELF)
#       define DSKFZ(id)                       DSKE(id,FZ)
#       define DSKE(id)                        &__ske_##id##__
#       define DSK(id,nm,des,t,...)                                             \
                                                                                \
static bool sk_##id##_is_runnable(Game &game, fsm_status_t status);             \
static void sk_##id##_run(Game &game);                                          \
const skill_chance_t __skc_##id##_array__[] = {__VA_ARGS__};                    \
const skill_entry_t __ske_##id##__ =                                            \
    {                                                                           \
        JN_##id,                                                                \
        nm,                                                                     \
        des,                                                                    \
        (skill_type_mask_t)(JNL_NONE | (t)),                                    \
        0,                                                                      \
        __lenof__(__skc_##id##_array__),                                        \
        __skc_##id##_array__,                                                   \
        sk_##id##_is_runnable,                                                  \
        sk_##id##_run                                                           \
    }




/* * */

DSK(NONE, "", "", 0);
DSK(ANXU, "安恤", "", 0, FZ);
DSK(BAIYIN, "拜印", "", 0);
DSK(BAONVE, "暴虐", "", JNL_MASTER);
DSK(BAZHEN, "八阵", "", 0);
DSK(BEIGE, "悲歌", "", 0);
DSK(BENGHUAI, "崩坏", "", 0);
DSK(BIYUE, "闭月", "", 0);
DSK(BUQU, "不屈", "", 0);
DSK(BUYI, "补益", "", 0);
DSK(CHONGZHEN, "冲阵", "", 0);
DSK(CHUNLAO, "醇醪", "", 0);
DSK(DAHE, "大喝", "", 0);
DSK(DANGXIAN, "当先", "", 0);
DSK(DANJI, "单骑", "", 0);
DSK(DANLAO, "啖酪", "", 0);
DSK(DAWU, "大雾", "", 0);
DSK(DIMENG, "缔盟", "", 0);
DSK(DUANCHANG, "断肠", "", 0);
DSK(DUANLIANG, "断粮", "", 0);
DSK(ENYUAN, "恩怨", "", 0);
DSK(FANGQUAN, "放权", "", 0);
DSK(FANJIAN, "反间", "", 0);
DSK(FANKUI, "反馈", "", 0);
DSK(FANZHU, "放逐", "", 0);
DSK(FEIYING, "飞影", "", JNL_LOCKED, F(distance_to, JNT_SELF));
DSK(FUHUN, "父魂", "", 0);
DSK(FULI, "伏枥", "", 0);
DSK(GANGLIE, "刚烈", "", 0);
DSK(GANLU, "甘露", "", 0);
DSK(GONGJI, "弓骑", "", 0);
DSK(GONGXIN, "攻心", "", 0);
DSK(GUANXING, "观星", "回合开始阶段，你可以观看牌堆顶的X张牌（X为存活角色的数量且最多为5），将其中任意数量的牌以任意顺序置于牌堆顶，其余以任意顺序置于牌堆底。", 0);
DSK(GUHUO, "蛊惑", "", 0);
DSK(GUICAI, "鬼才", "", 0);
DSK(GUIDAO, "鬼道", "", 0);
DSK(GUIXIN, "归心", "", 0);
DSK(GUOSE, "国色", "", 0);
DSK(GUZHENG, "固政", "", 0);
DSK(HAOSHI, "好施", "", 0);
DSK(HONGYAN, "红颜", "", JNL_LOCKED, F(card_pattern, JNT_SELF));
DSK(HONGYUAN, "弘援", "", 0);
DSK(HUANGTIAN, "黄天", "", JNL_MASTER);
DSK(HUANSHI, "缓释", "", 0);
DSK(HUASHEN, "化身", "", 0);
DSK(HUILEI, "挥泪", "", 0);
DSK(HUJIA, "护驾", "主公技，当你需要使用（或打出）一张【闪】时，你可以发动护驾。所有“魏”势力角色按行动顺序依次选择是否打出一张【闪】“提供”给你（然后视为由你使用或打出），直到有—名角色或没有任何角色决定如此做时为止。", JNL_MASTER);
DSK(HUNZHI, "魂姿", "", 0);
DSK(HUOJI, "火计", "", 0);
DSK(HUOSHOU, "祸首", "", 0);
DSK(JIANG, "激昂", "", 0);
DSK(JIANGCHI, "将驰", "", 0);
DSK(JIANXIONG, "奸雄", "你可以立即获得对你成伤害的牌。", 0);
DSK(JIE, "嫉恶", "", 0);
DSK(JIEFAN, "解烦", "", 0);
DSK(JIEMING, "节命", "", 0);
DSK(JIEYIN, "结姻", "", 0);
DSK(JIJIANG, "激将",
    "主公技，当你需要使用（或打出）一张【杀】时，你可以发动激将。所有\"蜀\"势力角色按行动顺序依次选择是否打出一张【杀】\"提供\"给你（视为由你使用或打出），直到有一名角色或没有任何角色决定如此做时为止。", JNL_MASTER);

DSK(JIJIU, "急救", "", 0);
DSK(JILEI, "鸡肋", "", 0);
DSK(JINJIU, "禁酒", "", 0);
DSK(JIUCHI, "酒池", "", 0);
DSK(JIUSHI, "酒诗", "", 0);
DSK(JIUYUAN, "救援", "", JNL_MASTER);
DSK(JIZHI, "集智", "", 0);
DSK(JUEJING, "绝境", "", 0);
DSK(JUEQING, "绝情", "", 0);
DSK(JUJIAN, "举荐", "", 0);
DSK(JUSHOU, "据守", "", 0);
DSK(JUXIANG, "巨象", "", 0);
DSK(KANPO, "看破", "", 0);
DSK(KEJI, "克己", "", 0);
DSK(KONGCHENG, "空城", "锁定技，当你没有手牌时，你不能成为【杀】或【决斗】的目标。", 0);
DSK(KUANGBAO, "狂暴", "", 0);
DSK(KUANGFENG, "狂风", "", 0);
DSK(KUANGGU, "狂骨", "", 0);
DSK(KUIWEI, "溃围", "", 0);
DSK(KUROU, "苦肉", "", 0);
DSK(LEIJI, "雷击", "", 0);
DSK(LIANHUAN, "连环", "", 0);
DSK(LIANPO, "连破", "", 0);
DSK(LIANYING, "连营", "", 0);
DSK(LIEGONG, "烈弓", "", 0);
DSK(LIEREN, "烈刃", "", 0);
DSK(LIHUN, "离魂", "", 0);
DSK(LIHUO, "疠火", "", 0);
DSK(LIJIAN, "离间", "", 0);
DSK(LIULI, "流离", "", 0);
DSK(LONGDAN, "龙胆", "你可以将你手牌的【杀】当【闪】，【闪】当【杀】使用（或打出）。", 0);
DSK(LONGHUN, "龙魂", "", 0);
DSK(LUANJI, "乱击", "", 0);
DSK(LUANWU, "乱武", "", 0);
DSK(LUOSHEN, "洛神", "", 0);
DSK(LUOYI, "裸衣", "", 0);
DSK(LUOYING, "落英", "", 0);
DSK(MANJUAN, "漫卷", "", 0);
DSK(MASHU, "马术", "锁定技，当你计算与其他角色的距离时，始终-1。", JNL_LOCKED, F(distance_from, JNT_SELF));
DSK(MENGJIN, "猛进", "", 0);
DSK(MIJI, "秘计", "", 0);
DSK(MINGCE, "明策", "", 0);
DSK(MINGZHE, "明哲", "", 0);
DSK(MOUDAN, "谋断", "", 0);
DSK(NIEPAN, "涅槃", "", 0);
DSK(PAOXIAO, "咆哮",
    "出牌阶段，你可以使用任意数量的【杀】。", 0);

DSK(POJUN, "破军", "", 0);
DSK(QIANGXI, "强袭", "", 0);
DSK(QIANXI, "潜袭", "", 0);
DSK(QIANXUN, "谦逊", "", 0);
DSK(QIAOBIAN, "巧变", "", 0);
DSK(QICAI, "奇才", "", 0);
DSK(QICE, "奇策", "", 0);
DSK(QINGGUO, "倾国", "", 0);
DSK(QINGNANG, "青囊", "", 0);
DSK(QINYIN, "琴音", "", 0);
DSK(QIXI, "奇袭", "", 0);
DSK(QIXING, "七星", "", 0);
DSK(QUANJI, "权计", "", 0);
DSK(QUHU, "驱虎", "", 0);
DSK(RENDE, "仁德",
    "出牌阶段，你可以将任意数量的手牌以任意分配方式交给其他角色，若你给出的牌张数不少于两张时，你回复1点体力。", 0);

DSK(RENJIE, "忍戒", "", 0);
DSK(ROULIN, "肉林", "", 0);
DSK(RUOYU, "若愚", "", JNL_MASTER);
DSK(SHANGSHI, "伤逝", "", 0);
DSK(SHELIE, "涉猎", "", 0);
DSK(SHENFEN, "神愤", "", 0);
DSK(SHENJI, "神戟", "", 0);
DSK(SHENSU, "神速", "", 0);
DSK(SHENWEI, "神威", "", 0);
DSK(SHIYONG, "恃勇", "", 0);
DSK(SHUANGXIOANG, "双雄", "", 0);
DSK(SONGWEI, "颂威", "", JNL_MASTER);
DSK(TANHU, "探虎", "", 0);
DSK(TIANDU, "天妒", "", 0);
DSK(TIANXIANG, "天香", "", 0);
DSK(TIANYI, "天义", "", 0);
DSK(TIAOXIN, "挑衅", "", 0);
DSK(TIEJI, "铁骑", "", 0);
DSK(TUNTIAN, "屯田", "", 0);
DSK(TUXI, "突袭", "", 0);
DSK(WANSHA, "完杀", "", 0);
DSK(WEIDI, "伪帝", "", 0);
DSK(WEIMU, "帷幕", "", 0);
DSK(WUHUN, "武魂", "", 0);
DSK(WUMOU, "无谋", "", 0);
DSK(WUQIAN, "无前", "", 0);
DSK(WUSHEN, "武神", "", 0);
DSK(WUSHENG, "武圣", "你可以将你的任意一张红色牌当【杀】使用或打出。", 0);
DSK(WUSHUANG, "无双", "", 0);
DSK(WUYAN, "无言", "", 0);
DSK(XIANGLE, "享乐", "", 0);
DSK(XIANZHEN, "陷阵", "", 0);
DSK(XIAOJI, "枭姬", "", 0);
DSK(XINGSHUANG, "行殇", "", 0);
DSK(XINSHENG, "新生", "", 0);
DSK(XINZHAN, "心战", "", 0);
DSK(XIULUO, "修罗", "", 0);
DSK(XUANFENG, "旋风", "", 0);
DSK(XUANHUO, "眩惑", "", 0);
DSK(XUEYI, "血裔", "", JNL_MASTER);
DSK(YANZHENG, "严整", "", 0);
DSK(YEYAN, "业炎", "", 0);
DSK(YICONG, "义从", "", 0);
DSK(YIJI, "遗计", "", 0);
DSK(YINGHUN, "英魂", "", 0);
DSK(YINGZI, "英姿", "", 0);
DSK(YIZHONG, "毅重", "", 0);
DSK(YONGSI, "庸肆", "", 0);
DSK(ZAIQI, "再起", "", 0);
DSK(ZAOXIAN, "凿险", "", 0);
DSK(ZHENLIE, "贞烈", "", 0);
DSK(ZHIBA, "制霸", "", JNL_MASTER);
DSK(ZHICHI, "智迟", "", 0);
DSK(ZHIHENG, "制衡", "", 0);
DSK(ZHIJI, "志继", "", 0);
DSK(ZHIJIAN, "直谏", "", 0);
DSK(ZHIYU, "智愚", "", 0);
DSK(ZHUIYI, "追忆", "", 0);
DSK(ZILI, "自立(排异)", "", 0);
DSK(ZISHOU, "自守", "", 0);
DSK(ZONGSHI, "宗室", "", 0);
DSK(ZUIXIANG, "醉乡", "", 0);
DSK(CHENGXIANG, "称象", "", 0);
DSK(RENXIN, "仁心", "", 0);
DSK(ZHUIKONG, "惴恐", "", 0);
DSK(QIUYUAN, "求援", "", 0);
DSK(LONGYIN, "龙吟", "", 0);
DSK(JINGCE, "精策", "", 0);
DSK(QIAOSHUI, "巧说", "", 0);
DSK(ZONGSHI_JY, "纵适", "", 0);
DSK(JUECE, "绝策", "", 0);
DSK(MIEJI, "灭计", "", 0);
DSK(FENCHENG, "焚城", "", 0);
DSK(XIANSI, "陷嗣", "", 0);
DSK(JUNXING, "峻刑", "", 0);
DSK(YUCE, "御策", "", 0);
DSK(DUODAO, "夺刀", "", 0);
DSK(ANJIAN, "暗箭", "", 0);
DSK(ZONGXUAN, "纵玄", "", 0);
DSK(ZHIYAN, "直言", "", 0);
DSK(DANSHOU, "胆守", "", 0);
DSK(XINGWU, "星舞", "", 0);
DSK(YANLUO, "雁落", "", 0);




#       undef F
#       undef FZ
#       undef DSKFZ
#       undef DSK
#   endif /* __WSG__SKILL__LIST__H__ */
#endif /* __WSG__DECLARE__SKILL__LIST__H__ */