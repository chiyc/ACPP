#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int main(){
    for(int i = 0; i != 100; ++i){
        cout << std::setw(3); // set first column width
        cout << i + 1;
        cout << std::setw(7); // set width for second output
        cout << (i + 1) * (i + 1);
        cout << endl;
    }
}