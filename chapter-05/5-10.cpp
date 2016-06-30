#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;  using std::string;  using std::max;
using std::cin;     using std::cout;    using std::endl;

bool ispalindrome(const string&);

// finding palindromes
int main(){
    vector<string> palindromes;
    string s;
    string::size_type maxlen = 0;
    vector<string>::size_type pals = -1;
    vector<string>::size_type longpal = -1;
    while(getline(cin, s)){
        if(ispalindrome(s)){
            palindromes.push_back(s);
            ++pals;
            if(s.size() > maxlen){
                maxlen = s.size();
                longpal = pals;
            }
        }

    }
    cout << endl;
    cout << "List of palindromes:" << endl;
    for(vector<string>::size_type i = 0; i != palindromes.size(); ++i){
        cout << palindromes[i] << endl;
    }
    cout << endl;
    cout << "The longest palindrome is " << palindromes[longpal] << endl;
}

bool ispalindrome(const string& s){
    string::const_iterator iter = s.begin();
    string::const_iterator riter = s.end();
    --riter;
    for(string::size_type i = 0; i != s.size(); ++i){
        if(*iter != *riter){
            return false;
        }
        ++iter;
        --riter;
    }
    return true;
}