#ifndef GUARD_fails_h
#define GUARD_fails_h

// fails.h
#include <list>
#include "Student_info.h"

bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif