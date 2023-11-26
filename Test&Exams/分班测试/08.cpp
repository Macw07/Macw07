#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
string m;

int convert_to_ten(int base, string number){
    int ans = 0, t = 0;
    for (int i=number.size()-1; i>=0; i--){
        if (number[i] >= 'A'){
            ans += (number[i]-'A'+10) * pow(base, t);
        } else ans += (number[i]-'0') * pow(base, t);
        t += 1;
    }
    return ans;
}

string convert_to_k(int base, int number){
    string ans;
    while(number){
        int y = number % base;
        if (y >= 10){
            ans += (y-10) + 'A';
        } else ans += y + '0';
        y /= base;
        number /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cin >> n >> m >> k;
    int s = convert_to_ten(n, m);
    string ans = convert_to_k(k, s);
    cout << ans << endl;
    return 0;
}