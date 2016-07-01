#ifndef GUARD_fails_h
#define GUARD_fails_h

// fails.h
#include <vector>
#include <list>
#include "Student_info.h"

//    typedef list<Student_info> Student_container;
    typedef std::vector<Student_info> Student_container;


bool fgrade(const Student_info&);
Student_container extract_fails(Student_container);

#endif