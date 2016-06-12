#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  double x;
  vector<double> values;
  
  cout<<"Please enter at least 4 numerical values: ";
  
  while(cin>>x){
    values.push_back(x);
  }
  
  typedef vector<double>::size_type vec_sz;
  vec_sz size = values.size();

  if(size < 4){
    cout<<"Error: Not enough data to calculate quartiles. "
        <<"Please enter at least 4 numerical values.";
    return 1;
  }

  sort(values.begin(), values.end());

  vec_sz mid = size/2;

  double median, q1, q3;
  if (size % 2 == 0){
    median = (values[mid] + values[mid-1])/2;
    
    if (mid % 2 == 0){
      q1 = (values[mid/2] + values[mid/2-1])/2;
      q3 = (values[mid+mid/2] + values[mid+mid/2-1])/2;
    }
    else {
      q1 = values[mid/2];
      q3 = values[mid+mid/2];
    }
  
  }
  else {
    median = values[mid];

    if (mid % 2 == 0){
      q1 = (values[mid/2] + values[mid/2-1])/2;
      q3 = (values[mid+mid/2] + values[mid+mid/2+1])/2;
    }
    else {
      q1 = values[mid/2];
      q3 = values[mid+mid/2+1];
    }
  }
  cout << "Q1: " << q1 << endl;
  cout << "Median: " << median << endl;
  cout << "Q3: " << q3 << endl; 

}
