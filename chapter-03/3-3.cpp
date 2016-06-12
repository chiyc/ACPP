#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  string x;
  vector<string> words;

  cout << "Please enter a list of words: ";

  while (cin >> x){
    words.push_back(x);
  }
  sort(words.begin(), words.end());
  typedef vector<string>::size_type vec_sz;
  vec_sz size = words.size();
  int count = 0;

  for(int i = 0; i < size; ++i){
    if(i == 0){
      cout << words[i]<<": ";
      count = 1;
    }
    else {
      
      if(words[i].compare(words[i-1]) == 0){
        ++count;
      }
      else {
        cout << count << endl;
        cout << words[i] << ": ";
        count = 1;
      }

      if(i == size-1){
        cout << count;
      }
    }
  }

}
