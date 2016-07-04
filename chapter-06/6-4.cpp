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

    // this results in a segmentation fault because v.begin() does not exist
//    copy(u.begin(), u.end(), v.begin());
    
    // first fix involves using the back_inserter
    // this approach is slow due to constant resizing of the vector
//    copy(u.begin(), u.end(), back_inserter(v));

    // second fix involves just assigning to v the contents of u
    v = u;

    for(vector<int>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}