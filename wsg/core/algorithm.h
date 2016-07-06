//
//  algorithm.h
//  wsg
//
//  Created by cosim on 16/7/5.
//  Copyright © 2016年 老虎宝典. All rights reserved.
//

#ifndef __WSG__ALGORITHM__H__
#define __WSG__ALGORITHM__H__



#define DEF_FIND_ARRAY_FUNC(T,FN,TI)                                            \
extern const T* FN(TI id);

#define IMP_FIND_ARRAY_FUNC(T,FN,TI,TA,ID)                                      \
const T* FN(TI id) {                                                            \
;   int num = __lenof__(TA), m = num>>1;                                        \
;   for (int l = 0, h = num; l >= 0 && l < h; ) {                               \
;        if (TA[m].ID == id) { return TA+m;                                     \
;        } else if (TA[m].ID > id) { h = m-1;                                   \
;        } else l = m+1;                                                        \
;        m = (l + h) / 2;                                                       \
;   }                                                                           \
;   return (TA[m].ID == id)? TA+m: NULL;                                        \
}


#define IMP_FIND_PTR_ARRAY_FUNC(T,FN,TI,TA,ID)                                  \
const T* FN(TI id) {                                                            \
;   int num = __lenof__(TA), m = num>>1;                                        \
;   for (int l = 0, h = num; l >= 0 && l < h; ) {                               \
;        if (TA[m]->ID == id) { return TA[m];                                   \
;        } else if (TA[m]->ID > id) { h = m-1;                                  \
;        } else l = m+1;                                                        \
;        m = (l + h) / 2;                                                       \
;   }                                                                           \
;   return (TA[m]->ID == id)? TA[m]: NULL;                                      \
}


#define DEF_FIND_ARRAY_STRING_FUNC(T,FN)                                        \
extern const T* FN(const char *id);

#define IMP_FIND_ARRAY_STRING_FUNC(T,FN,TA,ID)                                  \
const T* FN(const char *name) {                                                 \
;   for (int i = 0, len = __lenof__(TA); i < len; ++i) {                        \
;       if (strcmp(TA[i].ID, name) == 0) {                                      \
;           return TA+i;                                                        \
;       }                                                                       \
;   }                                                                           \
;   return NULL;                                                                \
}

//const T* FN(TI id) {                                                            \
//;   int num = __lenof__(TA), m = num>>1;                                        \
//;   for (int l = 0, h = num; l >= 0 && l < h; ) {                               \
//;        if (TA[m].ID == id) { return TA+m;                                     \
//;        } else if (TA[m].ID > id) { h = m-1;                                   \
//;        } else l = m+1;                                                        \
//;        m = (l + h) / 2;                                                       \
//;   }                                                                           \
//;   return (TA[m].ID == id)? TA+m: NULL;                                        \
//}





#endif /* defined(__WSG__ALGORITHM__H__) */