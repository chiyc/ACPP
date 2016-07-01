#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using std::vector;  using std::cin;
using std::string;  using std::cout;    using std::endl;

vector<string> split(const string&);
bool space(char);
bool not_space(char);

int main(){
    string s;
    getline(cin, s);
    vector<string> v = split(s);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }
    return 0;
}

vector<string> split(const string& str){
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while(i != str.end()){
        i = find_if(i, str.end(), not_space);

        iter j = find_if(i, str.end(), space);

        if (i != str.end()){
            ret.push_back(string(i,j));
        }
        i = j;
    }
    return ret;
}

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}