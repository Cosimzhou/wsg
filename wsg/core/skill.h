//
//  skill.h
//  wsg
//
//  Created by cosim on 15/6/16.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//
#include "wsg.h"

#ifndef __WSG__SKILL__H__
#define __WSG__SKILL__H__

WSG_BEGIN

typedef enum {
#   define WSG_DSKN(n)          JN_##n,
#   include "skill-list.h"
#   undef WSG_DSKN
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
    JNT_SIB,
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
typedef list<Skill*> Skills;

class SkillRegister
    : public vector<map<fsm_status_t, Skills>* >
{
public:
    SkillRegister(Game *game);
    ~SkillRegister();

    void assignPlayers(int cnt);

    Skill* install(skill_id_t, player_index_t plr);
//    void uninstall();
private:
    Game *_game;
    vector<Skill*> _skills;
};

















#define SKILL_IS_LOCKED(sk)             (sk->type & JNL_LOCKED)














DEF_FIND_ARRAY_FUNC(skill_entry_t, wsg_skill_get_info_by_skid, skill_id_t);

WSG_END
#endif /* defined(__WSG__SKILL__H__) */