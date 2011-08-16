// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 22:44:56

#if !defined(PEOPLE_H)
#define PEOPLE_H

#include "object.h"

#define PEOPLE_DATA \
    OBJ_DATA \
    int age;\
    char fullname[100];

#define PEOPLE_TYPE \
    OBJ_TYPE \
    void (*sleep)(void* thiz);


typedef struct _People_Type{
    PEOPLE_TYPE
}People_Type;

extern const Object_Type Object_type;
extern const People_Type People_type;

typedef struct _People{
    const People_Type* methods;
    PEOPLE_DATA
}People;

People* newPeople(const char*,int);
#endif

