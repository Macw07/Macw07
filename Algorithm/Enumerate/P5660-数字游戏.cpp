#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.size(), cnt = 0;
    for (int i=0; i<len; i++){
        if (str[i] == '1') cnt++;
    }
    cout << cnt << endl;
    return 0;
}