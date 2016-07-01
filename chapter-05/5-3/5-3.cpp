#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "fails.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::list;



int main(){

    Student_container students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store student data
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize list of students
//    students.sort(compare);
    Student_container fail = extract_fails(students);

    cout << "Passing Students" << endl;
    for (Student_container::iterator i = students.begin();
         i != students.end(); ++i){
        
        // print student names with corresponding formatting
        cout << (*i).name
             << string(maxlen + 1 - (*i).name.size(), ' ');

        // compute and write grade
        try {
            double final_grade = grade(*i);
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
    for (Student_container::iterator i = fail.begin();
         i != fail.end(); ++i){
        
        // print student names with corresponding formatting
        cout << i->name
             << string(maxlen + 1 - i->name.size(), ' ');

        // compute and write grade
        try {
            double final_grade = grade(*i);
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