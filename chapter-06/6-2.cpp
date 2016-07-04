#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include "find_urls.h"

using std::vector;  using std::cout;
using std::string;  using std::cin;     using std::endl;
/*
vector<string> find_urls(const string&);

string::const_iterator 
url_end(string::const_iterator, string::const_iterator);
string::const_iterator 
url_beg(string::const_iterator, string::const_iterator);

bool not_url_char(char);
*/
int main(){
    string s;
    getline(cin,s);
    vector<string> v = find_urls(s);
    for(vector<string>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << endl;
    }
    return 0;
}
/*
vector<string> find_urls(const string& s){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while (b != e) {        
        // look for one or more letters followed by ://
        b = url_beg(b,e);

        if (b != e) {
            // gets the rest of the url
            iter after = url_end(b, e);
            
            ret.push_back(string(b, after));
            // advances the b iterator
            b = after;
        }
    }
    return ret;
}

string::const_iterator 
url_end(string::const_iterator b, string::const_iterator e){
    return find_if(b, e, not_url_char);
}

bool not_url_char(char c){
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || 
             find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator 
url_beg(string::const_iterator b, string::const_iterator e){
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b; // i is used to mark the beginning of the separator

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // make sure separator isn't at beginning or end
        if (i != b && i + sep.size() != e) {

            // beg marks beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1])){
                --beg;
            }

            if (beg != i && !not_url_char(i[sep.size()])){
                return beg;
            }

        }

        i += sep.size();
    }
    return e;
}
*/