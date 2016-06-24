#include <vector>
#include <iostream>

using std::cin;     using std::cout;
using std::vector;  using std::endl;

double average(vector<double>&);

int main(){
    double x;

    vector<double> values;
    values.clear();

    while(cin >> x){
        values.push_back(x);
    }

    cout << average(values) << endl;

    return 0;
}

double average(vector<double>& v){
    vector<double>::size_type length = v.size();
    double sum = 0;

    for(vector<double>::size_type i = 0; i < length; ++i){
        sum += v[i];
    }

    return sum / length;

}