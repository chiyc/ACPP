#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

using std::vector;  using std::map;     using std::cout;    using std::domain_error;
using std::string;  using std::istream; using std::cin;     using std::endl;
using std::logic_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream&);
vector<string> split(const string&);
vector<string> gen_sentence(const Grammar&);
bool bracketed(const string&);
void gen_aux(const Grammar&, const string&, vector<string>&);
int nrand(int);

int main(){
    // generate the setence
    vector<string> sentence = gen_sentence(read_grammar(cin));

    vector<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()){
        cout << *it;
        ++it;
    }

    while(it != sentence.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    return 0;
}

int nrand(int n){
    if(n <= 0 || n > RAND_MAX){
        throw domain_error("Argument to nrand is out of range");
    }

    const int bucket_size = RAND_MAX/n;
    int r;

    do r = rand() / bucket_size;
    while(r >= n);

    return r;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret){
    if(!bracketed(word)){
        ret.push_back(word);
    }
    else {
        Grammar::const_iterator it = g.find(word);
        if(it == g.end()){
            throw logic_error("empty rule");
        }
        // select category
        const Rule_collection& c = it->second;
        // select rule
        const Rule& r = c[nrand(c.size())];

        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i){
            gen_aux(g, *i, ret);
        }
    }
}

vector<string> gen_sentence(const Grammar& g){
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

Grammar read_grammar(istream& in){
    Grammar ret;
    string line;

    while(getline(in, line)){
        vector<string> entry = split(line);
        if(!entry.empty()){
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }

    }
    return ret;
}


vector<string> split(const string& s){
    vector<string> ret;
    string::const_iterator i = s.begin();
    while(i != s.end()){
        while(isspace(*i) && i != s.end()){
            ++i;
        }
        string::const_iterator j = i;
        while(j != s.end() && !isspace(*j)){
            ++j;
        }

        if(i != j){
            ret.push_back(string(i,j));
            i = j;
        }
    }
    return ret;
}