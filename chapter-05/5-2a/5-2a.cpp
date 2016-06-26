#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "fails.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store student data
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize vector of students
    sort(students.begin(), students.end(), compare);
    vector<Student_info> fail = extract_fails(students);

    cout << "Passing Students" << endl;
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i){
        
        // print student names with corresponding formatting
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    cout << endl;
    cout << "Failing Students" << endl;
    for (vector<Student_info>::size_type i = 0;
         i != fail.size(); ++i){
        
        // print student names with corresponding formatting
        cout << fail[i].name
             << string(maxlen + 1 - fail[i].name.size(), ' ');

        // compute and write grade
        try {
            double final_grade = grade(fail[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}