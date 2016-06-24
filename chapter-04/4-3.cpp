#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int main(){
    int max_value = 1000;
    int loop_max = max_value;
    int cols_a = 0;
    do {
        ++cols_a;
        max_value /= 10;
    } while (max_value);

    for(int i = 0; i != loop_max; ++i){
        cout << std::setw(cols_a); // set first column width
        cout << i + 1;
        cout << std::setw(cols_a * 2 + 1); // set width for second output
        cout << (i + 1) * (i + 1);
        cout << endl;
    }
}