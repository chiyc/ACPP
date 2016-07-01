#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;  using std::string;  using std::cin;
using std::cout;    using std::endl;    using std::back_inserter;
using std::copy;    using std::back_insert_iterator;

vector<string> vcat(const vector<string>&, const vector<string>&);

// exploring different ways to vertically concatenate
int main(){
    vector<string> bot, top;
    string s;
    while(getline(cin,s)){
        top.push_back(s);
    }
    bot = top;
    vector<string> v = vcat(top, bot);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }
}

vector<string> vcat(const vector<string>& top, const vector<string>& bot){
    vector<string> ret = top;
//    ret.insert(ret.end(), bot.begin(), bot.end());
//    OR
//    copy(bot.begin(), bot.end(), back_inserter(ret));
//    which can also be expressed as
    vector<string>::const_iterator begin = bot.begin();
    vector<string>::const_iterator end = bot.end();
    back_insert_iterator< vector<string> > out = back_inserter(ret);
    while(begin != end){
        *out++ = *begin++;
    }

    return ret;
}
