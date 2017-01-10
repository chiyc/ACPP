#include <string>
#include <iostream>

using std::cout;    using std::cin;
using std::string;  using std::endl;

bool is_palindrome(const string&);

int main(){
    string s;
    getline(cin, s);
    cout << is_palindrome(s) << endl;
    return 0;
}

bool is_palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}