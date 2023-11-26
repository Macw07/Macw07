#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1){
        cout << "孤独" << endl;
    } else if (n == 2){
        cout << "失望" << endl;
    } else if (n == 3){
        cout << "悲伤" << endl;
    } else if (n == 4){
        cout << "快乐" << endl;
    } else if (n == 5){
        cout << "惊奇" << endl;
    } else if (n == 6){
        cout << "愤怒" << endl;
    } else{
        cout << "焦虑" << endl;
    }
    return 0;
}