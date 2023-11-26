#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

int main(){
    /* double Sunny[5] = {15, 4.54, 7.07, 1.28, 7.03};
    cout << Sunny[0] << endl;
    cout << Sunny[1] << endl;
    cout << Sunny[2] << endl;
    cout << Sunny[3] << endl;
    cout << Sunny[4] << endl; */
    int n[10];

    // 初始化数组元素
    for (int i=0; i < 10; i++){
        n[i] = i + 100;
    }
    cout << "Element" << setw(13) << "Value" << endl;

    // 遍历
    for (int j=0; j < 10; j++){
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    return 0;
}