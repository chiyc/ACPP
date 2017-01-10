#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using std::string;  using std::cin;     using std::cout;
using std::vector;  using std::endl;

int main(){
    vector<string> v;
    string s;
    while(getline(cin,s)){
        v.push_back(s);
    }
    string out = accumulate(v.begin(), v.end(), s);
    cout << out << endl;
    return 0;
}