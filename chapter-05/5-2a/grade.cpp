#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::domain_error; using std::vector;

double grade(double midterm, double final, double homework){
    return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

double grade(double midterm, double final, const vector<double>& hw){
    if (hw.size() == 0){
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}