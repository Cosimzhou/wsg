//
//  skill.cpp
//  wsg
//
//  Created by cosim on 15/6/16.
//  Copyright (c) 2015年 Cosim Studio. All rights reserved.
//
#include "skill.h"
WSG_BEGIN
#define __WSG__DECLARE__SKILL__LIST__H__
#   include "skill-funcitem.h"
#undef __WSG__DECLARE__SKILL__LIST__H__


const skill_entry_t* const wsg_skill_entries[]  = {
#   define WSG_DSKN(n)          DSKE(n),
#   include "skill-list.h"
#   undef WSG_DSKN
};

IMP_FIND_PTR_ARRAY_FUNC(skill_entry_t, wsg_skill_get_info_by_skid, skill_id_t, wsg_skill_entries, sid);


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
    for (vector<Skill*>::iterator iter = _skills.begin(); iter != _skills.end(); ++iter)
        delete *iter;
    _skills.clear();

    for(int i = 0; i < cnt; ++i) {
        if (size() <= i) {
            push_back(new map<fsm_status_t, Skills>());
        } else {
            (*this)[i]->clear();// = new map<fsm_status_t, Skills>();
        }
    }
}

Skill* SkillRegister::install(skill_id_t skid, player_index_t plr) {
    if (plr > this->size() || skid <= 0) {
        return NULL;
    }

    const skill_entry_t *pskill = wsg_skill_entries[skid];
    map<fsm_status_t, Skills> *pfs;
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