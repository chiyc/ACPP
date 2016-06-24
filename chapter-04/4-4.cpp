#include <iostream>
#include <iomanip>
#include <ios>

using std::cout;    using std::streamsize;
using std::endl;    using std::setprecision;

int main(){
    int max_value = 100;
    int loop_max = max_value;
    int cols_a = 0;
    do {
        ++cols_a;
        max_value /= 10;
    } while (max_value);

    streamsize prec = cout.precision();
    int desired_precision = 10;
    
    for(int i = 0; i != loop_max; ++i){
        double current_value = i + 1.33;
        cout << std::setw(desired_precision + 2); // set first column width
        cout << setprecision(desired_precision);
        cout << current_value;
        cout << std::setw(desired_precision + 2); // set width for second output
        cout << current_value * current_value;
        cout << endl;
    }
    cout << setprecision(prec);

    return 0;
}