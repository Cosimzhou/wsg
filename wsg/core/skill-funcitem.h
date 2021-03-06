//
//  skill-funcitem.h
//  wsg
//
//  Created by cosim on 16/6/29.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#ifdef  __WSG__DECLARE__SKILL__LIST__H__
#   define __WSG__DECLARE__SKILL__LIST__H__
#   ifndef __WSG__SKILL__LIST__H__

#       define N                                JNL_NONE
#       define F(x,c)                           {x,c}
#       define FS(x)                            F(x,JNT_SELF)
#       define FZ                               F(round_play,JNT_SELF)
#       define DSKFZ(id)                        DSKE(id,FZ)
#       define DSKE(id)                         &__ske_##id##__
#       define DSK(nm,t,id,des,...)                                             \
                                                                                \
static bool sk_##id##_is_runnable(Game &game, fsm_status_t status);             \
static void sk_##id##_run(Game &game);                                          \
const skill_chance_t __skc_##id##_array__[] = {__VA_ARGS__};                    \
const skill_entry_t __ske_##id##__ =                                            \
    {                                                                           \
        JN_##id,                                                                \
        nm,                                                                     \
        des,                                                                    \
        (skill_type_mask_t)(N | (t)),                                           \
        0,                                                                      \
        __lenof__(__skc_##id##_array__),                                        \
        __skc_##id##_array__,                                                   \
        sk_##id##_is_runnable,                                                  \
        sk_##id##_run                                                           \
    }




/* * */

DSK("", N, NONE, "");
DSK("安恤", N, ANXU, "[出牌阶段]限一次，你可以选择两名手牌数不相等的其他角色，令其中手牌少的角色先获得手牌多的角色的一张手牌再展示之，若此牌不为黑桃，你摸一张牌。", FZ);
DSK("拜印", N, BAIYIN, "觉醒技，[准备阶段]开始时，若你拥有的忍标记枚数不小于4，你减1点体力上限，然后获得极略（每当一名角色的判定牌生效前，若你有手牌，你可以弃1枚忍标记发动标记发动鬼才；每当你受到伤害后，你可以弃1枚忍标记，发动放逐；每当你使用锦囊牌时，你可以弃；每当你使用锦囊牌时，你可以弃1枚忍标记，发动集智；[出牌阶段]限一次，若你有牌，你可以弃1枚忍标记，发动制衡；[出牌阶段]，你可以弃1枚忍标记，执行完杀的效果，直到回合结束）。");
DSK("暴虐", JNL_MASTER, BAONVE, "主公技，每当其他群势力角色造成伤害后，其可以进行判定，若结果为黑桃，你回复1点体力。");
DSK("八阵", JNL_LOCKED, BAZHEN, "锁定技，若你的装备区里没有防具牌，你视为装备着【八卦阵】。");
DSK("悲歌", N, BEIGE, "每当一名角色受到【杀】造成的伤害后，你可以弃置一张牌并选择该角色，令其进行判定，结果为：红桃该角色回复1点体力；方块该角色摸两张牌；梅花来源弃置两张牌；黑桃来源将其武将牌翻面。");
DSK("崩坏", JNL_LOCKED, BENGHUAI, "锁定技，[结束阶段]开始时，若有当前的体力值比你小的角色，你选择一项：1.失去1点体力；2.减1点体力上限。");
DSK("闭月", N, BIYUE, "[结束阶段]开始时，你可以摸一张牌。");
DSK("不屈", N, BUQU, "每当你扣减1点体力后，若你当前的体力值为0，你可以将牌堆顶的一张牌置于你的武将牌上，称为创创，若所有，若所有创创的点数均不同，你不会死亡。");
DSK("补益", N, BUYI, "每当一名角色进入濒死状态时，你可以展示其一张手牌，然后若此牌不为基本牌，你令其弃置之，再令其回复1点体力。");
DSK("冲阵", N, CHONGZHEN, "");
DSK("醇醪", N, CHUNLAO, "[结束阶段]开始时，若没有醇醇，你可以将至少一张【杀】置于你的武将牌上，称为，你可以将至少一张【杀】置于你的武将牌上，称为醇醇；每当一名角色处于濒死状态时，你可以将一张；每当一名角色处于濒死状态时，你可以将一张醇醇置入弃牌堆，令该角色视为使用一张【酒】。置入弃牌堆，令该角色视为使用一张【酒】。");
DSK("大喝", N, DAHE, "");
DSK("当先", N, DANGXIAN, "锁定技，回合开始时，你执行一个额外的[出牌阶段]。");
DSK("单骑", N, DANJI, "觉醒技，[准备阶段]开始时，若你的手牌数大于你当前的体力值，且主公为曹操，你减1点体力上限，然后获得马术马术。");
DSK("啖酪", N, DANLAO, "每当你和其他角色成为一张锦囊牌的目标后，你可以摸一张牌，然后此牌对你无效。");
DSK("大雾", N, DAWU, "[结束阶段]开始时，你可以将至少一张星星置入弃牌堆并选择等量的角色，若如此做，你的下回合开始前，每当这些角色受到的非雷电伤害结算开始时，防止此伤害。置入弃牌堆并选择等量的角色，若如此做，你的下回合开始前，每当这些角色受到的非雷电伤害结算开始时，防止此伤害。");
DSK("缔盟", N, DIMENG, "[出牌阶段]限一次，你可以选择两名其他角色并弃置X张牌（X为这两名角色手牌数的差），令这两名角色交换手牌。");
DSK("断肠", JNL_LOCKED, DUANCHANG, "锁定技，当你死亡时，你令杀死你的角色失去其所有武将技能。");
DSK("断粮", N, DUANLIANG, "你可以将一张黑色基本牌或黑色装备牌当【兵粮寸断】使用；锁定技，你能对距离为2的角色使用【兵粮寸断】。");
DSK("恩怨", N, ENYUAN, "锁定技，每当其他角色令你回复1点体力时，你令其摸一张牌；锁定技，每当你受到其他角色对你造成的伤害后，你令其选择一项：1.将一张红桃手牌交给你；2.失去1点体力。");
DSK("放权", N, FANGQUAN, "你可以跳过[出牌阶段]，若如此做，此回合结束时，你可以弃置一张手牌并选择一名其他角色，令其获得一个额外的回合。");
DSK("反间", N, FANJIAN, "[出牌阶段]限一次，若你有手牌，你可以令一名其他角色选择一种花色，然后该角色先获得你的一张手牌再展示之，若此牌的花色与其所选的不同，你对其造成1点伤害。");
DSK("反馈", N, FANKUI, "每当你受到伤害后，你可以获得来源的一张牌。");
DSK("放逐", N, FANZHU, "每当你受到伤害后，你可以令一名其他角色摸X张牌（X为你已损失的体力值），然后该角色将其武将牌翻面。");
DSK("飞影", JNL_LOCKED, FEIYING, "锁定技，其他角色与你的距离+1。", FS(distance_to));
DSK("父魂", N, FUHUN, "[摸牌阶段]开始时，你可以放弃摸牌，从牌堆顶亮出两张牌并获得之，若亮出的牌颜色不同，你拥有武圣、咆哮，直到回合结束。");
DSK("伏枥", N, FULI, "限定技，当你处于濒死状态时，你可以回复至X点体力（X为现存势力数），然后将你的武将牌翻面。");
DSK("刚烈", N, GANGLIE, "每当你受到伤害后，你可以进行判定，若结果不为红桃，来源选择一项：1.弃置两张手牌；2.受到你对其造成的1点伤害。");
DSK("甘露", N, GANLU, "[出牌阶段]限一次，你可以令两名装备数的差不大于X的角色交换装备区里的牌（X为你已损失的体力值）。");
DSK("弓骑", N, GONGJI, "[出牌阶段]限一次，你可以弃置一张牌，令你于此回合内攻击范围无限，然后若你以此法弃置的牌为装备牌，你可以弃置一名其他角色的一张牌。");
DSK("攻心", N, GONGXIN, "[出牌阶段]限一次，你可以观看一名其他角色的手牌，然后你可以展示其中一张红桃牌，选择一项：1.弃置此牌；2.将此牌置于牌堆顶。");
DSK("观星", N, GUANXING, "[回合开始阶段]，你可以观看牌堆顶的X张牌（X为存活角色的数量且最多为5），将其中任意数量的牌以任意顺序置于牌堆顶，其余以任意顺序置于牌堆底。");
DSK("蛊惑", N, GUHUO, "你可以声明一张基本牌或非延时类锦囊牌的名称并背面朝上使用或打出一张手牌。若无其他角色质疑，你亮出此牌，然后按你所述之牌结算。若有其他角色质疑，亮出验明：若为真，质疑者各失去1点体力；若为假，质疑者各摸一张牌。若被质疑的牌为红桃且为真，此牌仍然进行结算，否则无论真假，你将此牌置入弃牌堆。");
DSK("鬼才", N, GUICAI, "每当一名角色的判定牌生效前，你可以打出一张手牌代替之。");
DSK("鬼道", N, GUIDAO, "每当一名角色的判定牌生效前，你可以打出一张黑色牌替换之。");
DSK("归心", N, GUIXIN, "每当你受到1点伤害后，若至少一名其他角色的区域里有牌，你可以选择所有其他角色，获得这些角色区域里的一张牌，然后将你的武将牌翻面。");
DSK("国色", N, GUOSE, "你可以将一张方块牌当【乐不思蜀】使用。");
DSK("固政", N, GUZHENG, "其他角色的[弃牌阶段]结束时，你可以令该角色获得弃牌堆里的其于此阶段内弃置的一张手牌，若如此做，你可以获得弃牌堆里的其余于此阶段内弃置的牌。");
DSK("好施", N, HAOSHI, "[摸牌阶段]，你可以额外摸两张牌，然后若你的手牌多于五张，你将一半（向下取整）的手牌交给手牌数最少的一名其他角色。");
DSK("红颜", JNL_LOCKED, HONGYAN, "锁定技，你的黑桃牌视为红桃牌。", FS(card_pattern));
DSK("弘援", N, HONGYUAN, "[摸牌阶段]，你可以少摸一张牌，令其他己方角色各摸一张牌。");
DSK("黄天", JNL_MASTER, HUANGTIAN, "主公技，其他群势力角色的[出牌阶段]限一次，其可以将一张【闪】或【闪电】交给你。");
DSK("缓释", N, HUANSHI, "每当一名己方角色的判定牌生效前，你可以打出一张牌代替之。");
DSK("化身", N, HUASHEN, "锁定技，所有玩家亮出武将牌后，你随机将两张游戏外的武将牌置于一旁，形成化身牌堆化身牌堆（进入过（进入过化身牌堆化身牌堆的牌称为的牌称为化身牌化身牌，武将牌须背面朝上置入，武将牌须背面朝上置入化身牌堆化身牌堆，，化身牌堆化身牌堆里的牌对你可见），然后选择一张里的牌对你可见），然后选择一张化身牌化身牌；回合开始时；回合开始时/结束后，你可以选择一张化身牌化身牌；锁定技，你的性别和势力属性视为与你武将牌旁的；锁定技，你的性别和势力属性视为与你武将牌旁的化身牌化身牌相同。相同。");
DSK("挥泪", JNL_LOCKED, HUILEI, "锁定技，当你死亡时，你令杀死你的角色弃置其所有的牌。");
DSK("护驾", JNL_MASTER, HUJIA, "主公技，当你需要使用（或打出）一张【闪】时，你可以发动护驾。所有“魏”势力角色按行动顺序依次选择是否打出一张【闪】“提供”给你（然后视为由你使用或打出），直到有—名角色或没有任何角色决定如此做时为止。");
DSK("魂姿", N, HUNZHI, "觉醒技，[准备阶段]开始时，若你当前的体力值为1，你减1点体力上限，然后获得英姿英姿和和英魂英魂。");
DSK("火计", N, HUOJI, "你可以将一张红色手牌当【火攻】使用。");
DSK("祸首", JNL_LOCKED, HUOSHOU, "锁定技，【南蛮入侵】对你无效；锁定技，每当其他角色使用【南蛮入侵】指定目标后，你成为此【南蛮入侵】造成伤害的来源。");
DSK("激昂", JNL_LOCKED, JIANG, "每当你使用一张【决斗】或红色的【杀】指定目标后，或成为一张【决斗】或红色的【杀】的目标后，你可以摸一张牌。");
DSK("将驰", N, JIANGCHI, "[摸牌阶段]，你可以选择一项：1.额外摸一张牌，若如此做，你不能使用或打出【杀】，直到回合结束；2.少摸一张牌，若如此做，你于[出牌阶段]内使用【杀】无距离限制且能额外使用一张【杀】，直到回合结束。");
DSK("奸雄", N, JIANXIONG, "你可以立即获得对你成伤害的牌。");
DSK("嫉恶", N, JIE, "");
DSK("解烦", N, JIEFAN, "限定技，[出牌阶段]，你可以选择一名角色，令攻击范围内含有该角色的所有角色（该角色除外）各选择一项：1.弃置一张武器牌；2.令其摸一张牌。");
DSK("节命", N, JIEMING, "每当你受到1点伤害后，你可以令一名角色将手牌补至X张（X为该角色的体力上限且至多为5）。");
DSK("结姻", N, JIEYIN, "[出牌阶段]限一次，你可以弃置两张手牌并选择一名已受伤的男性角色，令你与其各回复1点体力。");
DSK("激将", JNL_MASTER, JIJIANG, "主公技，当你需要使用（或打出）一张【杀】时，你可以发动激将。所有“蜀”势力角色按行动顺序依次选择是否打出一张【杀】“提供”给你（视为由你使用或打出），直到有一名角色或没有任何角色决定如此做时为止。");

DSK("急救", N, JIJIU, "你于回合外可以将一张红色牌当【桃】使用。");
DSK("鸡肋", N, JILEI, "每当你受到有来源的伤害后，你可以选择一种牌的类别，然后令来源不能使用、打出或弃置其此类别的手牌，直到回合结束。");
DSK("禁酒", N, JINJIU, "锁定技，你的【酒】视为【杀】。");
DSK("酒池", N, JIUCHI, "你可以将一张黑桃手牌当【酒】使用。");
DSK("酒诗", N, JIUSHI, "每当你需要使用【酒】时，若你的武将牌正面朝上，你可以将你的武将牌翻面，视为使用一张【酒】；若你因受到伤害而扣减体力前你的武将牌背面朝上，当此伤害结算结束后，你可以将你背面朝上的武将牌翻面。");
DSK("救援", JNL_MASTER, JIUYUAN, "主公技，锁定技，其他吴势力角色对处于濒死状态的你使用的【桃】回复的体力+1。");
DSK("集智", N, JIZHI, "每当你使用非延时类锦囊牌时，你可以摸一张牌。");
DSK("绝境", N, JUEJING, "锁定技，[摸牌阶段]，若你已受伤，你额外摸X张牌（X为你已损失的体力值）；锁定技，你的手牌上限+2。");
DSK("绝情", JNL_LOCKED, JUEQING, "锁定技，你即将造成的伤害视为失去体力。");
DSK("举荐", N, JUJIAN, "[出牌阶段]限一次，你可以弃置至多三张牌并选择一名其他角色，令其摸等量的牌，然后若你以此法弃置三张相同类别的牌，你回复1点体力。");
DSK("据守", N, JUSHOU, "[结束阶段]开始时，你可以摸三张牌，然后将你的武将牌翻面。");
DSK("巨象", N, JUXIANG, "锁定技，【南蛮入侵】对你无效；锁定技，每当其他角色使用的【南蛮入侵】结算完毕置入弃牌堆时，你获得之。");
DSK("看破", N, KANPO, "你可以将一张黑色手牌当【无懈可击】使用。");
DSK("克己", N, KEJI, "若你未于[出牌阶段]内使用或打出过【杀】，你可以跳过[弃牌阶段]。");
DSK("空城", JNL_LOCKED, KONGCHENG, "锁定技，当你没有手牌时，你不能成为【杀】或【决斗】的目标。");
DSK("狂暴", N, KUANGBAO, "锁定技，游戏开始时，你获得2枚暴怒暴怒标记；锁定技，每当你造成标记；锁定技，每当你造成/受到1点伤害后，你获得1枚暴怒暴怒标记。");
DSK("狂风", N, KUANGFENG, "[结束阶段]开始时，你可以将一张星星置入弃牌堆并选择一名角色，若如此做，你的下回合开始前，每当其受到的火焰伤害结算开始时，此伤害置入弃牌堆并选择一名角色，若如此做，你的下回合开始前，每当其受到的火焰伤害结算开始时，此伤害+1。");
DSK("狂骨", N, KUANGGU, "锁定技，每当你对距离1以内的一名角色造成1点伤害后，若你已受伤，你回复1点体力。");
DSK("溃围", N, KUIWEI, "回合[结束阶段]开始时，你可以摸2+X张牌，然后将你的武将牌翻面。在你的下个[摸牌阶段]开始时，你须弃置X张牌。X等于当时场上装备区内的武器牌的数量。");
DSK("苦肉", N, KUROU, "[出牌阶段]，你可以失去1点体力，摸两张牌。");
DSK("雷击", N, LEIJI, "每当你使用或打出【闪】时，你可以令一名角色进行判定，若结果为黑桃，你对其造成2点雷电伤害。");
DSK("连环", N, LIANHUAN, "你可以将一张梅花手牌当【铁索连环】使用或重铸。");
DSK("连破", N, LIANPO, "若你于一个回合内杀死过的角色数量不小于1，此回合结束后，你可以获得一个额外的回合。");
DSK("连营", N, LIANYING, "每当你失去最后的手牌时，你可以摸一张牌。");
DSK("烈弓", N, LIEGONG, "每当你于[出牌阶段]内使用【杀】指定一名目标角色后，若该角色的手牌数不小于你当前的体力值或不大于你的攻击范围，你可以令其不能使用【闪】响应此【杀】。");
DSK("烈刃", N, LIEREN, "每当你使用【杀】对目标角色造成伤害后，你可以与其拼点。若你赢，你获得其一张牌。");
DSK("离魂", N, LIHUN, "");
DSK("疠火", N, LIHUO, "你可以将一张普通【杀】当火【杀】使用，或将你视为使用一张【杀】当你视为使用一张火【杀】，当此【杀】结算结束后，若此【杀】造成过伤害，你失去1点体力；锁定技，你使用火【杀】选择目标的个数上限+1。");
DSK("离间", N, LIJIAN, "[出牌阶段]限一次，你可以弃置一张牌并选择两名男性角色，令其中一名男性角色视为对另一名男性角色使用一张【决斗】（不能使用【无懈可击】响应此【决斗】）。");
DSK("流离", N, LIULI, "每当你成为【杀】的目标时，你可以弃置一张牌并选择你攻击范围内的一名其他角色，将此【杀】转移给该角色。");
DSK("龙胆", N, LONGDAN, "你可以将你手牌的【杀】当【闪】，【闪】当【杀】使用（或打出）。");
DSK("龙魂", N, LONGHUN, "你可以将花色相同的X张牌按下列规则使用或打出：红桃当【桃】，方块当火【杀】，梅花当【闪】，黑桃当【无懈可击】（X为你当前的体力值且至少为1）。");
DSK("乱击", N, LUANJI, "你可以将两张花色相同的手牌当【万箭齐发】使用。");
DSK("乱武", N, LUANWU, "限定技，[出牌阶段]，你可以选择所有其他角色，这些角色各需对距离最近的另一名角色使用一张【杀】，否则失去1点体力。");
DSK("洛神", N, LUOSHEN, "[准备阶段]开始时，你可以进行判定，若结果为黑色，你获得生效后的判定牌且你可以重复此流程。");
DSK("裸衣", N, LUOYI, "[摸牌阶段]，你可以少摸一张牌，若如此做，每当你于此回合内使用【杀】或【决斗】对目标角色造成伤害时，此伤害+1。");
DSK("落英", N, LUOYING, "每当其他角色的一张梅花牌因弃置或判定而置入弃牌堆时，你可以获得之。");
DSK("漫卷", N, MANJUAN, "每当你将获得任何一张手牌，将之置于弃牌堆。若此情况处于你的回合中，你可依次将与该牌点数相同的一张牌从弃牌堆置于你的手上。");
DSK("马术", JNL_LOCKED, MASHU, "锁定技，当你计算与其他角色的距离时，始终-1。", FS(distance_from));
DSK("猛进", N, MENGJIN, "每当你使用的【杀】被目标角色使用的【闪】抵消时，你可以弃置其一张牌。");
DSK("秘计", N, MIJI, "[准备/结束阶段]开始时，若你已受伤，你可以进行判定，若结果为黑色，你观看牌堆顶的X张牌（X为你已损失的体力值），然后将这些牌交给一名角色。");
DSK("明策", N, MINGCE, "[出牌阶段]限一次，你可以将一张装备牌或【杀】交给一名角色，该角色需视为对其攻击范围内你选择的其使用【杀】的一个合法目标使用一张【杀】，若其未如此做或其攻击范围内没有其使用【杀】的合法目标，其摸一张牌。");
DSK("明哲", N, MINGZHE, "每当你于回合外使用、打出或因弃置而失去一张红色牌时，你可以摸一张牌。");
DSK("谋断", N, MOUDAN, "");
DSK("涅槃", N, NIEPAN, "限定技，当你处于濒死状态时，你可以弃置你区域里所有的牌，然后将你的武将牌恢复至游戏开始时的状态，再摸三张牌，最后回复至3点体力。");
DSK("咆哮", N, PAOXIAO, "[出牌阶段]，你可以使用任意数量的【杀】。");

DSK("破军", N, POJUN, "每当你使用【杀】对目标角色造成伤害后，你可以令该角色摸X张牌（X为其当前的体力值且至多为5），然后该角色将其武将牌翻面。");
DSK("强袭", N, QIANGXI, "[出牌阶段]限一次，你可以失去1点体力或弃置一张武器牌，并选择你攻击范围内的一名其他角色，对其造成1点伤害。");
DSK("潜袭", N, QIANXI, "[准备阶段]开始时，你可以进行判定，然后令一名距离为1的角色不能使用或打出与结果颜色相同的手牌，直到回合结束。");
DSK("谦逊", N, QIANXUN, "锁定技，你不是【顺手牵羊】/【乐不思蜀】的合法目标。");
DSK("巧变", N, QIAOBIAN, "你可以弃置一张手牌，跳过一个阶段（[准备阶段]和[结束阶段]除外）。若以此法跳过[摸牌阶段]，你获得至多两名其他角色的各一张手牌；若以此法跳过[出牌阶段]，你可以将场上的一张牌移动到另一名角色区域里的相应位置。");
DSK("奇才", N, QICAI, "锁定技，你使用锦囊牌无距离限制。");
DSK("奇策", N, QICE, "你可以将所有手牌当一张使用时机为[出牌阶段]空闲时间点的非延时类锦囊牌于此时机使用。每回合限一次。");
DSK("倾国", N, QINGGUO, "你可以将一张黑色手牌当【闪】使用或打出。");
DSK("青囊", N, QINGNANG, "[出牌阶段]限一次，你可以弃置一张手牌并选择一名已受伤的角色，令其回复1点体力。");
DSK("琴音", N, QINYIN, "每当你于[弃牌阶段]内因你的弃置而失去第X张手牌时（X至少为2），你可以选择一项：1.令所有角色各回复1点体力；2.令所有角色各失去1点体力。每回合限一次。");
DSK("奇袭", N, QIXI, "你可以将一张黑色牌当【过河拆桥】使用。");
DSK("七星", N, QIXING, "锁定技，分发起始手牌时，共发你十一张牌，你选择其中四张作为手牌，将其余的牌背面朝上置于你的武将牌旁，称为星；[摸牌阶段]结束时，你可以用至少一张手牌替换等量的；[摸牌阶段]结束时，你可以用至少一张手牌替换等量的星星。");
DSK("权计", N, QUANJI, "每当你受到1点伤害后，你可以摸一张牌，然后将一张手牌置于你的武将牌上，称为权权；锁定技，你的手牌上限；锁定技，你的手牌上限+X（X为权权的数量）。");
DSK("驱虎", N, QUHU, "[出牌阶段]限一次，你可以与一名当前的体力值大于你的角色拼点。若你赢，其对其攻击范围内你选择的另一名角色造成1点伤害。若你没赢，其对你造成1点伤害。");
DSK("仁德", N, RENDE, "[出牌阶段]，你可以将任意数量的手牌以任意分配方式交给其他角色，若你给出的牌张数不少于两张时，你回复1点体力。");

DSK("忍戒", N, RENJIE, "锁定技，每当你受到伤害后，你获得等同于你受到的伤害数量的忍忍标记；锁定技，每当你于[弃牌阶段]内因你的弃置而失去手牌时，你获得等同于你失去的手牌数量的标记；锁定技，每当你于[弃牌阶段]内因你的弃置而失去手牌时，你获得等同于你失去的手牌数量的忍忍标记。标记。");
DSK("肉林", N, ROULIN, "锁定技，每当你使用【杀】指定一名女性目标角色后，其需依次使用两张【闪】才能抵消；锁定技，每当你成为女性角色使用【杀】的目标后，你需依次使用两张【闪】才能抵消。");
DSK("若愚", JNL_MASTER, RUOYU, "主公技，觉醒技，[准备阶段]开始时，若你是当前的体力值最小的角色（或之一），你加1点体力上限，回复1点体力，然后获得激将激将。");
DSK("伤逝", N, SHANGSHI, "每当你的手牌数小于你已损失的体力值时，你可以将手牌数补至等同于你已损失的体力值。");
DSK("涉猎", N, SHELIE, "[摸牌阶段]开始时，你可以放弃摸牌，从牌堆顶亮出五张牌，然后获得其中不同花色的牌各一张，将其余的牌置入弃牌堆。");
DSK("神愤", N, SHENFEN, "[出牌阶段]限一次，你可以弃6枚暴怒暴怒标记并选择所有其他角色，对这些角色各造成标记并选择所有其他角色，对这些角色各造成1点伤害，然后这些角色先各弃置其装备区里的所有牌，再各弃置四张手牌，最后你将你的武将牌翻面。");
DSK("神戟", N, SHENJI, "");
DSK("神速", N, SHENSU, "你可以选择一至两项：1.跳过[判定阶段]和[摸牌阶段]。2.跳过[出牌阶段]并弃置一张装备牌。你每选择一项，视为使用一张【杀】。");
DSK("神威", N, SHENWEI, "");
DSK("恃勇", N, SHIYONG, "锁定技，每当你受到一次红色的【杀】或因【酒】生效而伤害值基数+1的【杀】造成的伤害后，你减1点体力上限。");
DSK("双雄", N, SHUANGXIOANG, "[摸牌阶段]开始时，你可以放弃摸牌，进行判定，当判定牌生效后，你获得此牌，然后你于此回合内可以将一张与此牌颜色不同的手牌当【决斗】使用。");
DSK("颂威", JNL_MASTER, SONGWEI, "主公技，每当一名其他魏势力角色的黑色判定牌生效后，其可以令你摸一张牌。");
DSK("探虎", N, TANHU, "");
DSK("天妒", N, TIANDU, "每当你的判定牌生效后，你可以获得此牌。");
DSK("天香", N, TIANXIANG, "每当你受到伤害时，你可以弃置一张红桃手牌并选择一名其他角色，将此伤害转移给该角色，若如此做，当该角色受到的此伤害结算结束时，其摸X张牌（X为其已损失的体力值）。");
DSK("天义", N, TIANYI, "[出牌阶段]限一次，你可以与一名角色拼点。若你赢，直到回合结束，你能额外使用一张【杀】且使用【杀】无距离限制且使用【杀】选择目标的个数上限+1。若你没赢，你不能使用【杀】，直到回合结束。");
DSK("挑衅", N, TIAOXIN, "[出牌阶段]限一次，你可以选择一名攻击范围内含有你的其他角色，该角色需对你使用一张【杀】，否则你弃置其一张牌。");
DSK("铁骑", N, TIEJI, "每当你使用【杀】指定一名目标角色后，你可以进行判定，若结果为红色，该角色不能使用【闪】响应此【杀】。");
DSK("屯田", N, TUNTIAN, "每当你于回合外失去牌时，你可以进行判定，当非红桃的判定牌生效后，你将此牌置于你的武将牌上，称为田田；锁定技，你与其他角色的距离；锁定技，你与其他角色的距离-X（X为田田的数量）。");
DSK("突袭", N, TUXI, "[摸牌阶段]开始时，你可以放弃摸牌并选择一至两名有手牌的其他角色，获得他们的各一张手牌。");
DSK("完杀", N, WANSHA, "锁定技，不处于濒死状态的其他角色于你的回合内不能使用【桃】。");
DSK("伪帝", N, WEIDI, "锁定技，你视为拥有当前主公的主公技。");
DSK("帷幕", N, WEIMU, "锁定技，你不是黑色锦囊牌的合法目标。");
DSK("武魂", N, WUHUN, "锁定技，每当你受到1点伤害后，你令来源获得1枚梦魇梦魇标记；锁定技，当你死亡时，你令拥有最多该标记的一名其他角色进行判定，若结果不为【桃】或【桃园结义】，其死亡。");
DSK("无谋", N, WUMOU, "锁定技，每当你使用非延时类锦囊牌时，你选择一项：1.弃1枚暴怒暴怒标记；标记；2.失去1点体力。");
DSK("无前", N, WUQIAN, "[出牌阶段]，你可以弃2枚暴怒暴怒标记并选择一名角色，直到回合结束，你拥有标记并选择一名角色，直到回合结束，你拥有无双无双且该角色的防具技能无效。且该角色的防具技能无效。");
DSK("武神", N, WUSHEN, "锁定技，你的红桃手牌视为【杀】；锁定技，你使用红桃【杀】无距离限制。");
DSK("武圣", N, WUSHENG, "你可以将你的任意一张红色牌当【杀】使用或打出。");
DSK("无双", N, WUSHUANG, "锁定技，每当你使用【杀】指定一名目标角色后，其需依次使用两张【闪】才能抵消；锁定技，每当你使用【决斗】指定一名目标角色后，或成为一名角色使用【决斗】的目标后，其每次对你响应此【决斗】需依次打出两张【杀】。");
DSK("无言", N, WUYAN, "锁定技，你使用的非延时类锦囊牌对其他角色无效；锁定技，其他角色使用的非延时类锦囊牌对你无效。");
DSK("享乐", N, XIANGLE, "锁定技，每当你成为一名角色使用【杀】的目标时，该角色需弃置一张基本牌，否则此次对你结算的此【杀】对你无效。");
DSK("陷阵", N, XIANZHEN, "[出牌阶段]限一次，你可以与一名角色拼点。若你赢，直到回合结束，你无视与该角色的距离及其防具且对其使用【杀】无次数限制。若你没赢，你不能使用【杀】，直到回合结束。");
DSK("枭姬", N, XIAOJI, "每当你失去装备区里的一张牌时，你可以摸两张牌。");
DSK("行殇", N, XINGSHUANG, "每当其他角色死亡时，你可以获得其所有牌。");
DSK("新生", N, XINSHENG, "每当你受到1点伤害后，你可以随机将一张游戏外的武将牌置入化身牌堆化身牌堆。");
DSK("心战", N, XINZHAN, "[出牌阶段]限一次，若你的手牌数大于你的体力上限，你可以观看牌堆顶的三张牌，然后先展示其中任意数量的红桃牌再获得之，其余以任意顺序置于牌堆顶。");
DSK("修罗", N, XIULUO, "");
DSK("旋风", N, XUANFENG, "每当你失去装备区里的牌时，或于[弃牌阶段]内（每个[弃牌阶段]限一次）因你的弃置而失去第X张手牌时（X至少为2），你可以依次弃置一至两名其他角色的共计两张牌。每当你失去装备区里的牌时，或于[弃牌阶段]内（每个[弃牌阶段]限一次）因你的弃置而失去第X张手牌时（X至少为2），你可以依次弃置一至两名其他角色的共计两张牌。");
DSK("眩惑", N, XUANHUO, "[出牌阶段]限一次，你可以将一张红桃手牌交给一名角色，获得该角色的一张牌，然后你可以将此牌交给除该角色外的角色。");
DSK("血裔", JNL_MASTER, XUEYI, "主公技，锁定技，你的手牌上限+2X（X为其他群势力角色的数量）。");
DSK("严整", N, YANZHENG, "若你的手牌数大于你的体力值，你可以将你装备区内的牌当【无懈可击】使用。");
DSK("业炎", N, YEYAN, "限定技，[出牌阶段]，你可以对一至三名角色造成至多共3点火焰伤害（你选择目标时任意分配每名目标角色受到的伤害点数）。若你将对一名角色分配的火焰伤害点数不小于2，你须执行弃置四张不同花色的手牌并失去3点体力的消耗。");
DSK("义从", N, YICONG, "锁定技，若你当前的体力值大于2，你与其他角色的距离-1；锁定技，若你当前的体力值不大于2，其他角色与你的距离+1。");
DSK("遗计", N, YIJI, "每当你受到1点伤害后，你可以观看牌堆顶的两张牌，然后将其中一张牌交给一名角色，再将另一张牌交给一名角色。");
DSK("英魂", N, YINGHUN, "[准备阶段]开始时，若你已受伤，你可以选择一项：1.令一名其他角色摸X张牌，然后弃置一张牌；2.令一名其他角色摸一张牌，然后弃置X张牌（X为你已损失的体力值）。");
DSK("英姿", N, YINGZI, "[摸牌阶段]，你可以额外摸一张牌。");
DSK("毅重", N, YIZHONG, "锁定技，若你的装备区里没有防具牌，黑色的【杀】对你无效。");
DSK("庸肆", N, YONGSI, "锁定技，[摸牌阶段]，你额外摸X张牌；锁定技，[弃牌阶段]开始时，你弃置X张牌（X为现存势力数）。");
DSK("再起", N, ZAIQI, "[摸牌阶段]开始时，若你已受伤，你可以放弃摸牌，从牌堆顶亮出X张牌（X为你已损失的体力值），你回复等同于其中红桃牌数量的体力，然后将这些红桃牌置入弃牌堆，最后获得其余的牌。");
DSK("凿险", N, ZAOXIAN, "觉醒技，[准备阶段]开始时，若田田的张数不小于的张数不小于3，你减1点体力上限，然后获得急袭急袭（你可以将一张田当【顺手牵羊】使用）。");
DSK("贞烈", N, ZHENLIE, "每当你的判定牌生效前，你可以从牌堆顶亮出一张牌代替之。");
DSK("制霸", JNL_MASTER, ZHIBA, "主公技，其他吴势力角色的[出牌阶段]限一次，该角色可以与你拼点（若你发动过魂姿魂姿，你可以拒绝此拼点）。若其没赢，你可以获得两张拼点的牌。你可以拒绝此拼点）。若其没赢，你可以获得两张拼点的牌。");
DSK("智迟", N, ZHICHI, "锁定技，每当你于回合外受到伤害后，【杀】或非延时类锦囊牌对你无效，直到回合结束。");
DSK("制衡", N, ZHIHENG, "[出牌阶段]限一次，你可以弃置至少一张牌，摸等量的牌。");
DSK("志继", N, ZHIJI, "觉醒技，[准备阶段]开始时，若你没有手牌，你选择一项：1.回复1点体力；2.摸两张牌。然后你减1点体力上限，获得观星观星。");
DSK("直谏", N, ZHIJIAN, "[出牌阶段]，你可以将手牌中的一张装备牌置于一名其他角色的装备区里，摸一张牌。");
DSK("智愚", N, ZHIYU, "每当你受到伤害后，你可以摸一张牌，然后展示所有手牌，若颜色均相同，来源弃置一张手牌。");
DSK("追忆", N, ZHUIYI, "当你死亡时，你可以令一名其他角色（杀死你的角色除外）摸三张牌，然后令其回复1点体力。");
DSK("自立", N, ZILI, "觉醒技，[准备阶段]开始时，若权的张数不小于的张数不小于3，你减1点体力上限，选择一项：1.回复1点体力；2.摸两张牌。然后你获得排异。");
DSK("自守", N, ZISHOU, "[摸牌阶段]，若你已受伤，你可以额外摸X张牌（X为你已损失的体力值），然后跳过[出牌阶段]。");
DSK("宗室", N, ZONGSHI, "锁定技，你的手牌上限+X（X为现存势力数）。");
DSK("醉乡", N, ZUIXIANG, "限定技，[回合开始阶段]开始时，你可以展示牌库顶的3张牌并置于你的武将牌上，你不可使用或打出与该些牌同类的牌，所有同类牌对你无效。之后每个你的[回合开始阶段]，你须重复展示一次，直至该些牌中任意两张点数相同时，将你武将牌上的全部牌置于你的手上。");
DSK("称象", N, CHENGXIANG, "每当你受到伤害后，你可以亮出牌堆顶的四张牌，然后获得其中点数之和小于13的至少一张牌，将其余的牌置入弃牌堆。");
DSK("仁心", N, RENXIN, "每当一名其他角色处于濒死状态时，你可以将你的武将牌翻面并将所有手牌交给该角色，令其回复1点体力。");
DSK("惴恐", N, ZHUIKONG, "其他角色的回合开始时，若你已受伤，你可以与其拼点。若你赢，该角色跳过其[出牌阶段]。若你没赢，该角色与你的距离视为1，直到回合结束。");
DSK("求援", N, QIUYUAN, "每当你成为【杀】的目标时，你可以令除此【杀】使用者外的一名有手牌的其他角色正面朝上将一张手牌交给你，若此牌不为【闪】，该角色也成为此【杀】的目标。");
DSK("龙吟", N, LONGYIN, "每当一名角色于其[出牌阶段]内使用【杀】时，你可以弃置一张牌，令此【杀】不计入限制的使用次数，然后若此【杀】为红色，你摸一张牌。");
DSK("精策", N, JINGCE, "[出牌阶段]结束时，若你于此回合内使用过的牌的数量不小于你当前的体力值，你可以摸两张牌。");
DSK("巧说", N, QIAOSHUI, "[出牌阶段]开始时，你可以与一名角色拼点。若你赢，你使用下一张基本牌或非延时类锦囊牌能额外（无距离限制）或少选择一个目标，直到回合结束。若你没赢，你不能使用锦囊牌，直到回合结束。");
DSK("纵适", N, ZONGSHI_JY, "每当你拼点赢，你可以获得两张拼点的牌中点数小的一张；每当你拼点没赢，你可以获得你拼点的牌。");
DSK("绝策", N, JUECE, "每当一名角色于你的回合内失去最后的手牌时，若其当前的体力值大于0，你可以对其造成1点伤害。");
DSK("灭计", N, MIEJI, "锁定技，你使用黑色非延时类锦囊牌选择目标的个数上限至少为2。");
DSK("焚城", N, FENCHENG, "限定技，[出牌阶段]，你可以令所有其他角色各选择一项：1.弃置X张牌（X为该角色装备区里牌的张数且至少为1）。2.受到你对其造成的1点火焰伤害。");
DSK("陷嗣", N, XIANSI, "[准备阶段]开始时，你可以将一至两名角色的各一张牌置于你的武将牌上，称为逆逆；每当一名角色需要对你使用【杀】时，该角色可以将两张；每当一名角色需要对你使用【杀】时，该角色可以将两张逆逆置入弃牌堆，视为对你使用一张【杀】（有距离限制且计入[出牌阶段]限制的使用次数）。置入弃牌堆，视为对你使用一张【杀】（有距离限制且计入[出牌阶段]限制的使用次数）。");
DSK("峻刑", N, JUNXING, "[出牌阶段]限一次，你可以弃置至少一张手牌并选择一名其他角色，该角色需弃置一张与你弃置的牌类别均不同的手牌，否则其先将其武将牌翻面再摸X张牌（X为你以此法弃置的手牌数量）。");
DSK("御策", N, YUCE, "每当你受到伤害后，你可以展示一张手牌，来源需弃置一张与此牌类别不同的手牌，否则你回复1点体力。");
DSK("夺刀", N, DUODAO, "每当你受到【杀】造成的伤害后，你可以弃置一张牌，获得来源装备区里的武器牌。");
DSK("暗箭", N, ANJIAN, "锁定技，每当你使用【杀】对目标角色造成伤害时，若你不在其攻击范围内，此伤害+1。");
DSK("纵玄", N, ZONGXUAN, "每当你的牌因弃置而置入弃牌堆前，你可以将其中至少一张牌以任意顺序置于牌堆顶。");
DSK("直言", N, ZHIYAN, "[结束阶段]开始时，你可以令一名角色摸一张牌，然后展示之，若此牌为装备牌，该角色先回复1点体力再使用此牌。");
DSK("胆守", N, DANSHOU, "每当你造成伤害后，你可以摸一张牌，然后终止一切结算，再结束当前回合。");
DSK("星舞", N, XINGWU, "[弃牌阶段]开始时，你可以将一张与你本回合使用的牌颜色均不同的手牌置于武将牌上。若此时你武将牌上的牌达到三张，则弃置这些牌，然后对一名男性角色造成2点伤害并弃置其装备区中所有的牌。");
DSK("雁落", N, YANLUO, "锁定技，若你的武将牌上有牌，你视为拥有技能“天香”和“流离”。");



#       undef N
#       undef F
#       undef FZ
#       undef DSKFZ
#       undef DSK
#   endif /* defined(__WSG__SKILL__LIST__H__) */
#endif /* defined(__WSG__DECLARE__SKILL__LIST__H__) */