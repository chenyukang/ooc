// people.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 22:51:10
//
// @Brief  :

#include "people.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static void PrintPeople(const void* thiz)
{
    assert(thiz);
    People* o = (People*)thiz;
    printf("this is a people named: %s\n",o->fullname);
}

static void DestructPeople(void* thiz)
{
    assert(thiz);
    printf("Destruct people\n");
}

static int EqualPeople(const void* thiz, const void* other)
{
    assert(thiz && other);
    People* l = (People*)thiz;
    People* r = (People*)other;
    if(r == l)
        return 1;
    if(strcmp(r->fullname,l->fullname)==0)
        return 1;
    return 0;
}

static void Sleep(void* thiz)
{
    assert( thiz );
    People* p = (People*)thiz;
    printf("sleep now: %s\n", p->fullname);
}

const People_Type People_type = {
    "peopletype",
    &Object_type,
    DestructPeople,
    PrintPeople,
    EqualPeople,
    Sleep
};

People* newPeople(const char* fullname,int age){
    People* p = (People*)malloc(sizeof(People));
    strcpy(p->fullname,fullname);
    p->ref_cnt = 1;
    p->age = age;
    p->methods = &People_type;
    return p;
};

