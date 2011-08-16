// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:13:23
// @desc   :  the base define of OBJ, every other object define will base on this
//         :  mainly the name,ref_cnt for memory management

#if !defined(OBJECT_H)
#define OBJECT_H
#define MAXLEN 100

#include <assert.h>

typedef struct _obj{
    char name[MAXLEN];
    int ref_cnt;
    int value;
    void (*destructor) (void* thiz);
    void (*print) (const void* thiz);
    int  (*equal) (const void* thiz, const void* other);
}Obj;


Obj* Obj_new();
void Obj_pick(const void* obj);
void Obj_drop(const void* obj);


#endif

