#include <iostream>
#include <cmath>
using namespace std;

int p;
long long ans;
string n;

int main(){
    cin >> p >> n;
    int len = n.size();
    for (int i=len-1, j=0; i>=0; i--, j++){
        if (n[i] >= 'A'){
            ans += ((n[i]-'A')+10) * pow(p, j);
        } else{
            ans += (n[i]-'0') * pow(p, j);
        }
    }
    cout << ans << endl;
    return 0;
}