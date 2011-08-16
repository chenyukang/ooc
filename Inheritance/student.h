// @Author : Yukang Chen (moorekang@gmail.com)
// @date   :  2011-08-14 23:47:53

#if !defined(STUDENT_H)
#define STUDENT_H

#include "people.h"

#define STUDENT_DATA \
    PEOPLE_DATA \
    char school[100];

#define STUDENT_TYPE \
    PEOPLE_TYPE \
    void (*study)(void* thiz);

typedef struct _Student_Type{
    STUDENT_TYPE
}Student_Type;

extern const People_Type People_type;
extern const Student_Type Student_type;

typedef struct _Student{
    const Student_Type* methods;
    STUDENT_DATA
}Student;



Student* newStudent(const char*,int, const char*);

#endif

