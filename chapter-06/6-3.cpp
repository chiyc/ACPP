#include <vector>
#include <iostream>

using std::cout;
using std::endl;    using std::vector;

int main(){
    vector<int> u(10,100);
    for(vector<int>::size_type i = 0; i != u.size(); ++i){
        cout << u[i] << " ";
    }
    cout << endl;
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());
    // this results in a segmentation fault because v.begin() does not exist
    for(vector<int>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}