#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;  using std::cin;     using std::endl;
using std::string;  using std::cout;    using std::max;

vector<string> frame(const vector<string>&);
string::size_type width(const vector<string>&);
vector<string> hcat(const vector<string>&, const vector<string>&);

int main(){
    string s;
    vector<string> v;
    while(getline(cin, s)){
        v.push_back(s);
    }
    v = hcat(v,frame(v));
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }

    return 0;
}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    ret.push_back(border);
    for(vector<string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter){
        string s = "* " + *iter + string(maxlen - (*iter).size(), ' ') + " *";
        ret.push_back(s);
    }
    ret.push_back(border);
    return ret;
}

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}


vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    vector<string>::const_iterator lit = left.begin();
    vector<string>::const_iterator rit = right.begin();
    string::size_type widthl = width(left) + 1;
    

    while(lit != left.end() || rit != right.end()){
        string s;
        if(lit != left.end()){
            s += *lit;
            ++lit;
        }
        s += string(widthl - s.size(), ' ');

        if(rit != right.end()){
            s += *rit;
            ++rit;
        }
        ret.push_back(s);
    }


    return ret;
}