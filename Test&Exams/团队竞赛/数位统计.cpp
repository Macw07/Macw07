#include <iostream>
using namespace std;

string str;
int arr[15];

int main(){
    cin >> str;
    int len = str.size();
    for (int i=0; i<len; i++){
        arr[str[i]-'0']++;
    }
    for (int i=0; i<=9; i++){
        if (arr[i])
        cout << i << " = " << arr[i] << endl;
    }
    return 0;
}