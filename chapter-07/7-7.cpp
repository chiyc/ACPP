#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <map>

using std::vector;  using std::istream; using std::cin;
using std::string;  using std::map;     using std::cout;    using std::endl;

vector<string> split(const string&);
map<string, vector<int> >
xref(istream&, vector<string> find_words(const string&) = split);


int main(){


    map<string, vector<int> > ret = xref(cin);

    for(map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); ++it){
        cout << it->first << " occurs on ";

        if(it->second.size() == 1){ // this conditional fulfills the exercise prompt
            cout << "line: ";
        }
        else{
            cout << "lines: ";
        }
        
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;
        while(line_it != it->second.end()){
            cout << ", " << *line_it;
            ++line_it;
        }

        cout << endl;
    }
    return 0;
}

map<string, vector<int> >
xref(istream& in, vector<string> find_words(const string&)){
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while(getline(in, line)){
        ++line_number;

        vector<string> words = find_words(line);

        for(vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it){
            ret[*it].push_back(line_number);
        }

    }
    return ret;
}


vector<string> split(const string& s){
    vector<string> ret;
    string::size_type i = 0;
    while(i != s.size()){
        while(i != s.size() && isspace(s[i])){
            ++i;
        }
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