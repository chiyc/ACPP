#include <vector>

using std::vector;

double analysis(const vector<Student_info>& students,
                        double analysis(const Student_info&)){
    vector<double> grades;
    transform(students.begin(), students.end(), 
              back_inserter(grades), analysis);
    return grades;
}