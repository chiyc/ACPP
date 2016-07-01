#ifndef GUARD_fails_h
#define GUARD_fails_h

// fails.h
#include <vector>
#include "Student_info.h"

bool fgrade(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

#endif