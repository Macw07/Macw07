#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, len, ori;
string str;

int main(){
    cin >> str >> n;
    len = ori = str.length();

    while(ori < n){
        ori += len;
    }
    ori -= len;
    n -= ori;
    cout << n << endl;
    cout << str[n-1];
    return 0;
}