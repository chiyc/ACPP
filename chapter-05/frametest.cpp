#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;  using std::max;     using std::cin;
using std::vector;  using std::cout;    using std::endl;

string::size_type width(const string&);
vector<string> frame(const vector<string>&);

int main(){
    string s;
    vector<string> v;
    while(getline(cin, s)){
        v.push_back(s);
    }
    v = frame(v);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }
    return 0;
}

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    ret.push_back(border);
    return ret;
}
