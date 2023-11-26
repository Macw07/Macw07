#include <iostream>
using namespace std;

string arr[505];
int i=0;
bool unique(string str){
    for (int j=0; j<i-1; j++){
        if (str == arr[j]) return false;
    }
    return true;
}

int main(){
    string s;
    while(cin >> arr[i++]){
        if (arr[i-1] == "0") break;
        if (unique(arr[i-1])){
            s += arr[i-1];
        }
    }
    cout << s;
    return 0;
}