#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

string inx[] = {'.-','-...','-.-.','-..','.','..-.','--.','....','..','.---','-.-','.-..','--','-.','---','.--.','--.-','.-.','...','-','..-','...-','.--','-..-','-.--','--..'};
string a, b;

int main(){
    cin >> a >> b;
    if (a == "decode"){
        pass
    } else{
        int len = b.size();
        for (int i=0; i<len; i++){
            cout << inx[b[i] -= 'a'] << " ";
        }
    }
    return 0;
}