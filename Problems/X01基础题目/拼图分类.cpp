#include <iostream>
using namespace std;

int main(){
    int difficulty;
    cin >> difficulty;
    if (difficulty <= 3){
        cout << "简单" << endl;
    } else if (difficulty <= 7){
        cout << "中等" << endl;
    } else {
        cout << "困难" << endl;
    }
    return 0;
}