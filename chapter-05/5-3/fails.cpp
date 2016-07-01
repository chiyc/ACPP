// fails.cpp
#include <list>
#include "grade.h"
#include "fails.h"
#include "Student_info.h"

using std::list;
using std::vector;

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

// this is the iterator implementation presented in the chapter

Student_container extract_fails(Student_container students){
    Student_container::iterator iter = students.begin();
    Student_container fail;
    
    while(iter != students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else{
            ++iter;
        }
    }
    return fail;
}