#include <iostream>
using namespace std;

int main(){
    double n;
    cin >> n;
    if (n >= 35.8 && n <= 37.3){
        cout << "Normal" << endl;
    } else{
        cout << "Abnormal" << endl;
    }
    return 0;
}