#include <iostream>
#include <algorithm>
using namespace std;

double arr[] = {1.05, 1.20, 2.04, 2.19, 3.05, 3.20, 4.04, 4.19, 5.05, 5.20, 6.05, 6.21, 7.06, 7.22, 8.07, 8.22, 9.07, 9.22, 10.08, 10.23, 11.07, 11.22, 12.07, 12.21};
string festivals[] = {"XH", "DH", "LC", "YS", "JZ", "CF", "QM", "GY",
                        "LX", "XM", "MZ", "XZ", "XS", "DS", 
                        "LQ", "CS", "BL", "QF", "HL", "SJ",
                        "LD", "XX", "DX", "DZ"};

int main(){
    int month, day, flag = 0;
    cin >> month >> day;
    double formated = month + day/100.0;
    for (int i=0; i<24; i++){
        if (arr[i] >= formated){
            cout << festivals[i] << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "XH" << endl;
    return 0;
}