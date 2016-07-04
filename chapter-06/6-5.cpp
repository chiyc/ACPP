#include <vector>

using std::vector;

double optimistic_analysis(const vector<Student_info>& students){
    vector<double> grades;
    transform(students.begin(), students.end(), 
              back_inserter(grades), optimistic_median);
    return grades;
}