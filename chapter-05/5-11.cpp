#include <vector>
#include <string>
#include <iostream>

using std::vector;  using std::string;
using std::cin;     using std::cout;    using std::endl;

bool hasneither(const string&);

int main(){
    string s;
    vector<string> v;
    string::size_type maxlen = 0;
    vector<string>::size_type imaxlen;    
    while(getline(cin,s)){
        if(hasneither(s)){
            v.push_back(s);
            if(s.size() > maxlen){
                maxlen = s.size();
                imaxlen = v.size() - 1;
            }
        }
    }
    cout << "List of words without ascenders nor descenders: " << endl;
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
       cout << v[i] << endl;
    }
    cout << "The long word in that list is: " << v[imaxlen] << endl;
}

bool hasneither(const string& s){
    string::const_iterator iter = s.begin();
    for(string::const_iterator iter = s.begin(); iter != s.end(); ++iter){
        if(*iter == 'b' || *iter == 'd' || *iter == 'f' || *iter == 'h' ||
           *iter == 'k' || *iter == 'l' || *iter == 't' || *iter == 'g' ||
           *iter == 'j' || *iter == 'p' || *iter == 'q' || *iter == 'y'){
            return false;
        }
    }
    return true;
}