// fails.cpp
#include <vector>
#include "grade.h"
#include "fails.h"
#include "Student_info.h"

using std::vector;

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

// this is the second try that erases the original vector in place 

vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0; // run down the vector
    vector<Student_info>::size_type j = 0; // track passing student size
    vector<Student_info>::size_type sz = students.size();

    while(i != students.size()){
        if(fgrade(students[i])){ // if the student fails
            fail.push_back(students[i]); // add to failing lits
            ++i; // iterate to next item
            --sz; // # of successful students decreases
        }
        else{ // if the student passes
            students[j] = students[i]; // copy student to the beginning of the vector
            ++j; // iterate to next place in original vector
            ++i; // iterate to next item
        }
    }
    students.resize(sz);
    return fail;
}


// this is the 3rd and final implementation presented in the chapter
// using iterators instead of indices
/*
vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info>::iterator iter = students.begin();
    vector<Student_info> fail;
    
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
*/

// this is the first try presented in the chapter
/*
vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info> pass, fail;

    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
        }
        else{
            pass.push_back(students[i]);
        }
    }
    students = pass;
    return fail;
}
*/


