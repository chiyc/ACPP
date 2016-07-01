#include <vector>
#include <iostream>
#include <string>
#include "frame.h"

using std::vector;  using std::string;
using std::cout;    using std::cin;     using std::endl;


vector<string> center(const vector<string>&);

int main(){
    string s;
    vector<string> v;
    while(getline(cin, s)){
        v.push_back(s);
    }
    v = center(v);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }    

    return 0;
}

vector<string> center(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        string s;
        string::size_type pad = maxlen - v[i].size();
        string::size_type lpad = pad/2;
        string::size_type rpad = pad-lpad;
        s += string(lpad, ' ');
        s += v[i];
        s += string(rpad, ' ');
        ret.push_back(s);
    }
    return ret;
}