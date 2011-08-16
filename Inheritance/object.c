// object.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:25:27
//
// @Brief  :

#include "object.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static int Object_equal(const void* thiz, const void* other)
{
    assert(thiz && other);
    return (thiz == other);
}

const Object_Type Object_type = {
    "baseobj",// typename
    NULL,     // father
    NULL,     // desctructor
    NULL,     // print
    Object_equal
};

void Obj_pick(const void* thiz)
{
    assert(thiz);
    Object* o = (Object*)thiz;
    o->ref_cnt++;
}

void Obj_drop(const void* thiz)
{
    Object* o = (Object*)thiz;
    const Object_Type* p;
    if( --o->ref_cnt <= 0){
        for( p = o->methods; p; p=p->father){
            if(p->destructor)
            {
                p->destructor(o);
            }
        }
    }
    free(o);
}
