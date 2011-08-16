// student.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-16 00:17:18
//
// @Brief  :

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int EqualStu(const void* thiz, const void* other)
{
    assert(thiz && other);
    Student* r = (Student*)thiz;
    Student* l = (Student*)other;
    if(r == l)
        return 1;
    if(strcmp(r->fullname,l->fullname)==0&&
       strcmp(r->school,l->school)==0)
        return 1;
    return 0;
}

static void DestructStudent(void* thiz)
{
    assert(thiz);
    printf("Destruct Student\n");
}


static void PrintStudent(const void* thiz)
{
    assert(thiz);
    Student* s = (Student*)thiz;
    printf("name:%s, school:%s, name:%d\n",
           s->fullname,s->school,s->age);
}

static void Sleep(void* thiz)
{
    assert(thiz);
    Student* s = (Student*)thiz;
    printf("student sleep:%s\n",s->fullname);
}

static void Study(void* thiz)
{
    assert(thiz);
    Student* s = (Student*)thiz;
    printf("Study now: %s\n",s->fullname);
}

const Student_Type Student_type = {
    "student_type",
    &People_type,
    DestructStudent,
    PrintStudent,
    EqualStu,
    Sleep,
    Study
};

Student* newStudent(const char* fullname,int age,
                    const char* school){
    Student* s = (Student*)malloc(sizeof(Student));
    strcpy(s->fullname,fullname);
    strcpy(s->school,school);
    s->ref_cnt = 1;
    s->age = age;
    s->methods = &Student_type;
    return s;
}

    
            
        
