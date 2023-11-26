#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s, check = "hello";
    int pointer = 0;
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (pointer <= 5 && s[i] == check[pointer]){
            pointer++;
        }
    }
    if (pointer == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}