//
//  course-functions.h
//  sgs
//
//  Created by 周志超 on 15/7/2.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#ifndef __sgs__course_functions__
#define __sgs__course_functions__

#include "engine.h"
#include "game.h"
#include "course.h"

extern errcode
sgs_cf_end(game*, status_course*);

/**************************
 * 弃牌路线
 *   @'discard'
 **************************/
extern errcode
sgs_cf_discard_card_showout(game*, status_course*);
extern errcode
sgs_cf_discard_card_push_heap(game*, status_course*);
extern errcode
sgs_cf_discard_card_end(game*, status_course*);


/**************************
 * 成为杀的对象路线
 * @'bekilled'
 **************************/
extern errcode
sgs_cf_bekilled_before(game*, status_course*);
extern errcode
sgs_cf_bekilled(game*, status_course*);
extern errcode
sgs_cf_bekilled_dodge(game*, status_course*);     //吕布的无双在此触发
extern errcode
sgs_cf_bekilled_after(game*, status_course*);


/**************************
 * 体力流失路线
 * @'bloodleaking'
 **************************/
extern errcode
sgs_cf_bloodleaking_before(game*, status_course*);
extern errcode
sgs_cf_bloodleaking(game*, status_course*);
extern errcode
sgs_cf_bloodleaking_finish(game*, status_course*);

/**************************
 * 吃桃路线
 * @'peach'
 **************************/
extern errcode
sgs_cf_peach_before(game*, status_course*);
extern errcode
sgs_cf_peach(game*, status_course*);
extern errcode
sgs_cf_peach_after(game*, status_course*);


#endif /* defined(__sgs__course_functions__) */
