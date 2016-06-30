#include <vector>
#include <cctype>
#include <string>
#include <iostream>

using std::isspace; using std::string;  using std::endl; 
using std::vector;  using std::cin;     using std::cout;

vector<string> split(const string&);

int main(){
    string s;
    while(getline(cin,s)){
        vector<string> v = split(s);

        for(vector<string>::size_type i = 0; i != v.size(); ++i){
            cout << v[i] << endl;
        }
    }
    return 0;
}

vector<string> split(const string& s){
    vector<string> ret;
    string::size_type i = 0;
    while(i != s.size()){ // main while loop
        while(i != s.size() && isspace(s[i])){
            ++i;
        } // skip past any leading whitespace
        string::size_type j = i;
        while(j != s.size() && !isspace(s[j])){
            ++j;
        }
        if(i != j){
            ret.push_back(s.substr(i, j - i));
            i = j;
        }

    }
    return ret;
}

/* this is a comparison program that achieves the same output
int main(){
    string s;
    while(cin >> s){
        cout << s << endl;
    }
    return 0;
}
*/