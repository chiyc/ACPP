#include <iostream>
#include <vector>
#include <string>

using std::vector;  using std::string;  using std::cout;
using std::cin;     using std::endl;

vector<string> vcat(const vector<string>&, const vector<string>&);

int main(){
    string s;
    vector<string> v;
    while(getline(cin, s)){
        v.push_back(s);
    }
    vector<string> twinv = vcat(v, v);
    for(vector<string>::size_type i = 0; i != twinv.size(); ++i){
        cout << twinv[i] << endl;
    }
    return 0;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
    vector<string> ret = top;

 //    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    for(vector<string>::const_iterator iter = bottom.begin();
        iter != bottom.end(); ++iter){
        ret.push_back(*iter);    
    }

    return ret;
}