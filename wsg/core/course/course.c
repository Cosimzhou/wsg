//
//  course.c
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#include "course.h"
#include "course-functions.h"


const status_course_lib_item sgc_courses_lib[] = {
    {"discard","",{sgs_cf_discard_card_showout,
        sgs_cf_discard_card_push_heap,
        sgs_cf_discard_card_end,
        sgs_cf_end}},
    {"bekilled","",{sgs_cf_bekilled_before,
        sgs_cf_bekilled,
        sgs_cf_bekilled_dodge,
        sgs_cf_bekilled_after,
        sgs_cf_end}},
};


static errcode
sgs_course_find_model_by_name(const char*, const status_course_lib_item**);
/////////////////////////////////////////////////////////////////

errcode
sgs_course_create_by_name(game *game, status_course *course, const char *name) {
    if (!game || !course)
        return ERR_NOT_READY;
    
    const status_course_lib_item *crs_model;
    errcode err= sgs_course_find_model_by_name(name, &crs_model);
    if (ERR_SUCCESS != err)
        return err;
    
    course->skipover = false;
    course->step = 0;
    course->nodes = csm_malloc_ntype(16, course_node);
    for (int i = 0; i < 16; ++i) {
        if (sgs_cf_end == crs_model->nodes[i]) {
            course->nodes[i].func = sgs_cf_end;
            course->length = i+1;
            break;
        }
        course->nodes[i].func = crs_model->nodes[i];
    }
    
    return ERR_SUCCESS;
}

errcode
sgs_course_destroy(status_course *course) {
    if (course->nodes) {
        free(course->nodes);
    }
    
    free(course);
    return ERR_SUCCESS;
}

errcode
sgs_course_perform(game *game, status_course *course) {
    if (!game || !course)
        return ERR_NOT_READY;

    errcode err;
    while (course->step < course->length) {
        err = sgs_course_perform_runnode(game, course);
        if (ERR_SUCCESS != err)
            return err;
        if (course->skipover) {
            break;
        }
        
        ++(course->step);
    }
    
    return ERR_SUCCESS;
}


errcode
sgs_course_perform_runnode(game *game, status_course *course) {
    if (!game || !course)
        return ERR_NOT_READY;
    if (course->step >= course->length)
        return ERR_SUCCESS;
    
    course->nodes[course->step].func(game, course);
    
    return ERR_SUCCESS;
}

////////////////////////////////////////////////////////////////////////

errcode
sgs_course_find_model_by_name(const char *name, const status_course_lib_item **crs) {
    for (int i = 0; i < csm_lenof(sgc_courses_lib); ++i) {
        if (0 == strcmp(sgc_courses_lib[i].name, name)) {
            *crs = sgc_courses_lib + i;
            return ERR_SUCCESS;
        }
    }
    return ERR_UNKNOWN_COURSE;
}
