#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using std::vector;  using std::cin;     using std::cout;
using std::string;  using std::sort;    using std::endl;
using std::setw;    using std::max;

int main(){
    vector<string> words;
    string x;

    string::size_type max_length = 0;

    while(cin >> x){
        max_length = max(max_length, x.length());
        words.push_back(x);
    }
    cin.clear();

    sort(words.begin(), words.end());

    int unique_words = 0;
    x = "";

    vector<string> uniques;
    vector<int> counts;

    int unique_index = -1;

    for(vector<string>::size_type i = 0; i < words.size(); ++i){
        if(words[i].compare(x) != 0){ // if the current word is new
            ++unique_index;
            ++unique_words;
            uniques.push_back(words[i]);
            counts.push_back(1);
        }
        else{
            ++counts[unique_index];
        }
        x = words[i];
    }



    cout << "Total word count: " << words.size() << endl;
    cout << "Unique word count: " << unique_words << endl;
    cout << "Max word length: " << max_length << endl;

    cout << endl;
    cout << setw(max_length + 5); 
    cout << "Word";
    cout << setw(max_length + 5); 
    cout << "Count" << endl;

    for(vector<string>::size_type i = 0; i < unique_words; ++i){
        cout << setw(max_length + 5); 
        cout << uniques[i];
        cout << setw(max_length + 5); 
        cout << counts[i] << endl;
    }

    return 0;
}