#include <iostream>
#include <algorithm>
using namespace std;

string a, b;

int convert(string k){
    int ans = 0;
    for (int i=0; i<k.size(); i++){
        ans = ans * 10 + (k[i]-'0');
    }
    return ans;
}

bool isPrime(int k){
    if (k <= 1) return 0;
    if (k == 2) return 1;
    for (int i=2; i*i<=k; i++){
        if (k % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin >> a; b = a;
    reverse(a.begin(), a.end());
    if (a != b){
        cout << "No" << endl;
        return 0;
    }
    if (isPrime(convert(a)))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}