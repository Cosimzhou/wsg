//
//  main.cpp
//  wsg
//
//  Created by 周志超 on 16/4/27.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <set>
#include <map>

#include <stdlib.h>

#include "wsg.h"

int main(int argc, const char * argv[]) {
//    std::vector<int> vec;
//    vec.push_back(0);
//    vec.push_back(3);
//    
//    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
//        std::cout<<*iter;
//    std::cout<<std::endl;
//
//    vector<string> *pvec = Hero::getHeroNamesByPackageID((package_mark_t)0x7f);
//    vector<vector<string> > psh;
//    set<int> sdidx;
//
//    int idx;
//    for(int i = 0; i < 8; ++i) {
//        vector<string> ppna;
//        for (int j = 0; j < 5; ++j) {
//            idx = rand() % pvec->size();
//            while(sdidx.find(idx) != sdidx.end())
//                idx = rand() % pvec->size();
//            ppna.push_back((*pvec)[idx]);
//        }
//        psh.push_back(ppna);
//    }
//
//
////    ostringstream oss;
//
//    for(auto iter = pvec->begin(); iter != pvec->end(); ++iter)
//        std::cout<<*iter;
//    std::cout<<std::endl;
//    delete pvec;
//
//    
//    std::cout<<std::string(" 0")<<std::endl;
//
//    map<int, string> mm;
//    mm[5] = string("asdf");
//    
//    string k = mm[7];
//    cout<<k<<endl;
//
//    return 0;

/*****************************************/
//    add JNL_LOCKED to skill_entries
//    is_runnable func return true
//    implement run func

    Game game = Game();
    for(int i = 0; i < 8; ++i)
        game.players.push_back(new Player());

    game.sr.assignPlayers(8);
    game.sr.install(JN_FEIYING, 0);
    game.sr.install(JN_MASHU, 3);
    
    game.play();


    return 0;
}
