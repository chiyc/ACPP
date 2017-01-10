#include <map>
#include <string>
#include <iostream>
#include <vector>

using std::map;     using std::cout;    using std::vector;
using std::string;  using std::cin;     using std::endl;


int main(){
    map<string, int> counters;
    string s;
    while(cin >> s){
        ++counters[s];
    }
    map<int, vector<string> > words; // using std::map to organize words by count
    cout << "WORD \tCOUNT" << endl;
    for(map<string, int>::const_iterator it = counters.begin();
        it != counters.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
        words[it->second].push_back(it->first);  // storing words by count
    }
    cout << endl;
    cout << "COUNT \tWORDS" << endl;
    for(map<int, vector<string> >::const_iterator it = words.begin();
        it != words.end(); ++it){
        cout << it->first << "\t";
        for(vector<string>::const_iterator i = it->second.begin();
            i != --( it->second.end() ); ++i){
            cout << *i << ", ";
        }
        cout << *--it->second.end();
        cout << endl;
    }
    return 0;
}
