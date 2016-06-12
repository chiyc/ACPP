#include <iostream>
#include <string>

using namespace std;

int main(){
  
  string str;
  
  unsigned int longest = 0;
  unsigned int shortest = str.max_size();
  
  string longstr;
  string shortstr;

  cout << "Please enter a list of strings: ";

  while(cin>>str){
    if(str.length() > longest){
      longest = str.length();
      longstr = str;
    }
    if(str.length() < shortest){
      shortest = str.length();
      shortstr = str;
    }
  }

  cout << "The longest string \"" << longstr << "\" is " << longest << " character(s)." << endl;
  cout << "The shortest string \"" << shortstr << "\" is " << shortest << " character(s)."<< endl;

}
