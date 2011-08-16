// main.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:39:01
//
// @Brief  :


#include "people.h"
#include "student.h"
#include <stdio.h>

int main()
{
    People* p = newPeople("kang",24);
    assert(p);
    p->methods->print(p);
    p->methods->sleep(p);
    printf("type_name: %s\n",p->methods->typename);
    
    Object_Type* obj_type = (Object_Type*)p->methods->father;
    printf("father type: %s\n", obj_type->typename);

    Student* s = newStudent("kang",24,"qingshuihe");
    obj_type = (Object_Type*)s->methods->father;
    printf("father type: %s\n", obj_type->typename);
    s->methods->print(s);
    s->methods->sleep(s);
    s->methods->study(s);

    Obj_drop(p);
    Obj_drop(s);
    
    return 0;
}

