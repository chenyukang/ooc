// main.c -
//
// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 12:39:01
//
// @Brief  :


#include "object.h"

int main()
{
    Obj* first = Obj_new(1);
    Obj* other = Obj_new(2);

    first->print(first);
    other->print(other);
    assert(!first->equal(first,other));
    Obj_pick(first);
    Obj_drop(first);
    Obj_drop(first);
    Obj_drop(other);
    return 0;
}

