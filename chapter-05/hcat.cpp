#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "frame.h"

using std::vector;  using std::max; using std::endl;
using std::string;  using std::cin; using std::cout;

vector<string> hcat(const vector<string>&, const vector<string>&);


int main(){
    string s;
    vector<string> p;
    while(getline(cin,s)){
        p.push_back(s);
    }
    vector<string> newp = hcat(p,frame(p));

    for(vector<string>::size_type i = 0; i != newp.size(); ++i){
        cout << newp[i] << endl;
    }

    return 0;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    string::size_type width1 = width(left) + 1;
    vector<string>::size_type i = 0;
    vector<string>::size_type j = 0;
    
    while(i != left.size() || j != right.size()){
        string s;
        if(i != left.size()){
            s = left[i++];
        }
        s += string(width1 - s.size(), ' ');
        if(j != right.size()){
            s += right[j++];
        }
        ret.push_back(s);
    }
    return ret;
}  
