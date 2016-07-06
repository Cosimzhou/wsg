//
//  status.cpp
//  wsg
//
//  Created by cosim on 16/4/27.
//  Copyright © 2016年 Cosim Studio. All rights reserved.
//

#include "status.hpp"
WSG_BEGIN

////////////////////////////////////////////////////
//
//          FSM implementations
//
////////////////////////////////////////////////////

FSM::FSM(Game *game): _obj(-1), _game(game) {
    queue<const fsm_status_t>::queue();
    
    for (const fsm_status_t *ps = fsm_game_courses; *ps != NULL_PHASE; ++ps)
        this->push(*ps);
}

FSM::FSM(const fsm_status_t *fsm_course, Game *game): _obj(-1), _game(game) {
    queue<const fsm_status_t>::queue();
    
    for (const fsm_status_t *ps = fsm_course; *ps != NULL_PHASE; ++ps)
        this->push(*ps);
}

bool FSM::operator++() {
    if (!this->empty()) {
        const fsm_status_t st = this->front();
        
        // TODO: is any skill could trigger
        this->triggerSkill(st);

        if (st(this))
            return false;
        this->pop();
    }
    
    return !this->empty();
}


void FSM::triggerSkill(const fsm_status_t st) {
    if (_obj < 0 || _obj >= _game->players.size())
        return;
    map<fsm_status_t, Skills> *mp = _game->sr[_obj];
    map<fsm_status_t, Skills>::iterator pss = mp->find(st);
    if (pss == mp->end()) return;

    Skills *sks = &(pss->second);
    if (sks->empty()) return;

    const skill_entry_t *psk;
    for (Skills::iterator iter=sks->begin(); iter!=sks->end(); ++iter) {
        psk = (*iter)->entry;
        if (psk->judge_run(*_game, st)) {
            if (SKILL_IS_LOCKED(psk) || _game->hintTriggerSkill(_obj, psk)) //hint
                psk->run(*_game);
        }
    }
}



WSG_END