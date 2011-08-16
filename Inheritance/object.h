// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:13:23
// @desc   :  the base define of OBJ, every other object define will base on this
//         :  mainly the name,ref_cnt for memory management

#if !defined(OBJECT_H)
#define OBJECT_H
#define MAXLEN 100

#include <assert.h>
#include <stddef.h>

#define OBJ_DATA \
    int ref_cnt;

#define OBJ_TYPE \
    char typename[MAXLEN];\
    const void* father;\
    void (*destructor)(void* thiz);\
    void (*print)(const void* thiz);\
    int  (*equal)(const void* thiz,const void* other);

typedef struct _Object_Type {
    OBJ_TYPE
}Object_Type;

extern const Object_Type Object_type;

typedef struct _Object {
    const Object_Type* methods;
    OBJ_DATA
}Object;

void Obj_pick(const void* obj);
void Obj_drop(const void* obj);

int IsInstanceOf(const void* obj, const void* type);

#endif

