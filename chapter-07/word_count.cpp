#include <map>
#include <string>
#include <iostream>

using std::map;     using std::cout;
using std::string;  using std::cin;     using std::endl;

int main(){
    map<string, int> counters;
    string s;
    while(cin >> s){
        ++counters[s];
    }

    for(map<string, int>::const_iterator it = counters.begin();
        it != counters.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
    }
    return 0;
}