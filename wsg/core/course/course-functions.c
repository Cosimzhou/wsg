//
//  course-functions.c
//  sgs
//
//  Created by 周志超 on 15/7/2.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "course-functions.h"



errcode
sgs_cf_end(game *game, status_course *course) {
    return ERR_SUCCESS;
}

/**************************
 * 弃牌路线
 *   @'discard'
 **************************/
errcode
sgs_cf_discard_card_showout(game *game, status_course *course) {
    return ERR_SUCCESS;
}

errcode
sgs_cf_discard_card_push_heap(game *game, status_course *course) {
    return ERR_SUCCESS;
}

errcode
sgs_cf_discard_card_end(game *game, status_course *course) {
    return ERR_SUCCESS;
}


/**************************
 * 成为杀的对象路线
 * @'bekilled'
 **************************/
errcode
sgs_cf_bekilled_before(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_bekilled(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_bekilled_dodge(game *game, status_course *course) {
    return ERR_SUCCESS;
}     //吕布的无双在此触发
errcode
sgs_cf_bekilled_after(game *game, status_course *course) {
    return ERR_SUCCESS;
}


/**************************
 * 体力流失路线
 * @'bloodleaking'
 **************************/
errcode
sgs_cf_bloodleaking_before(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_bloodleaking(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_bloodleaking_finish(game *game, status_course *course) {
    return ERR_SUCCESS;
}

/**************************
 * 吃桃路线
 * @'peach'
 **************************/
errcode
sgs_cf_peach_before(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_peach(game *game, status_course *course) {
    return ERR_SUCCESS;
}
errcode
sgs_cf_peach_after(game *game, status_course *course) {
    return ERR_SUCCESS;
}