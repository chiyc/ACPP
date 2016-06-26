// fails.cpp
#include <list>
#include "grade.h"
#include "fails.h"
#include "Student_info.h"

using std::list;

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

// this is the iterator implementation presented in the chapter

list<Student_info> extract_fails(list<Student_info>& students){
    list<Student_info>::iterator iter = students.begin();
    list<Student_info> fail;
    
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