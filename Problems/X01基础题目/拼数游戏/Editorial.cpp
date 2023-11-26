#include <iostream>
using namespace std;

long long convert(string num){
    long long sum = 0, len = num.size();
    for (int i=0; i<len; i++){
        sum = sum * 10 + num[i] - '0';
    }
    return sum;
}

int main(){
    // freopen("testcase014.in", "r", stdin);
    // freopen("testcase014.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    if (a == "0" && b == "0") {
        cout << 0 << endl;
        return 0;
    }
    if (convert(a + b) > convert(b+a)) cout << (a+b) << endl;
    else cout << (b + a) << endl;
    return 0;
}