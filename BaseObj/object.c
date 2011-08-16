// object.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:25:27
//
// @Brief  :

#include "object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void print(const void* thiz)
{
    assert(thiz);
    Obj* o = (Obj*) thiz;
    printf("%s value:%d\n",o->name, o->value);
}

static void destruct(void* thiz)
{
    assert(thiz);
    Obj* o = (Obj*)thiz;
    printf("actualy do nothing\n");
    free(o);
}

static int equal(const void* thiz, const void* other)
{
    assert(thiz && other);
    Obj* l = (Obj*)thiz;
    Obj* r = (Obj*)other;
    return l->value == r->value;
}

Obj* Obj_new(int value)
{
    Obj* o = malloc(sizeof(Obj));
    strcpy(o->name,"baseobj");
    o->ref_cnt    = 1;
    o->value      = value;
    o->destructor = &destruct;
    o->print      = &print;
    o->equal      = &equal;
    assert(o);
    return o;
}

void Obj_pick(const void* thiz)
{
    assert(thiz);
    Obj* o = (Obj*)thiz;
    o->ref_cnt++;
}

void Obj_drop(const void* thiz)
{
    Obj* o = (Obj*)thiz;
    if( --o->ref_cnt <= 0){
        if( o->destructor)
            (o->destructor(o));
    }
}




    
