#include <string>
#include <iostream>
#include <vector>
#include "median.h"

using std::string;  using std::cin;     using std::istream;
using std::cout;    using std::vector;  using std::endl;

struct Student_info {
    string name;
    double grade;
};

istream& read(istream&, Student_info&);

int main(){
    vector<Student_info> students;
    Student_info record;

    while( read(cin, record) ){
        students.push_back(record);
    }

    for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
        cout << students[i].name << " " << students[i].grade << endl;
    }

    return 0;
}

istream& read(istream& in, Student_info& s){
    double midterm, final;
    vector<double> homework;

    in >> s.name >> midterm >> final;
    if(in){
        homework.clear();
        double x;
        while(in >> x){
            homework.push_back(x);
        }
        in.clear();
    }
    
    if(in){
        s.grade = midterm*0.2 + final*0.4;
    }

    return in;
}