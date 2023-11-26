#include <iostream>
using namespace std;

string a, b;
long long t1=1, t2=1;

int main(){
    cin >> a >> b;
    for (int i=0; i<a.length(); i++){
        t1 *= (a[i]-'@');
    }
    for (int i=0; i<b.length(); i++){
        t2 *= (b[i]-'@');
    }
    t1 %= 47;
    t2 %= 47;
    if (t1==t2) cout << "GO";
    else cout << "STAY";
    return 0;
}