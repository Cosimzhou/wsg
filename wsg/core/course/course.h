//
//  course.h
//  sgs
//
//  Created by 周志超 on 15/6/15.
//  Copyright (c) 2015年 老虎宝典. All rights reserved.
//

#ifndef __sgs__course__
#define __sgs__course__

#include "engine.h"
#include "game.h"

typedef struct _status_course{
    int step;
    bool skipover;
    size_t length;
    struct _course_node *nodes;
    struct _status_course *pre_course;
} status_course;

typedef errcode (*sgs_course_func)(game*, status_course*);

typedef struct _course_node{
    sgs_course_func func;
} course_node;

typedef struct {
    const char *name;
    const char *comment;
    sgs_course_func nodes[32];
} status_course_lib_item;

extern const status_course_lib_item sgc_courses_lib[];

extern errcode
sgs_course_create_by_name(game*, status_course*, const char*);

extern errcode
sgs_course_destroy(status_course*);


extern errcode
sgs_course_perform(game*, status_course*);

extern errcode
sgs_course_perform_runnode(game*, status_course*);

#endif /* defined(__sgs__course__) */
