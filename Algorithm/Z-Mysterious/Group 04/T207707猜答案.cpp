#include <iostream>
using namespace std;

int arr[30];

bool prime(long long n){
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i=2; i*i<=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    int la = s.size();
    for (int i=0; i<la; i++){
        arr[s[i]-'a']++;
    }
    int max=0, min=30;
    for (int i=0; i<26; i++){
        if (arr[i] == 0) continue;
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }
    if (prime(max-min)){
        cout << "Lucky Word" << endl;
        cout << max - min << endl;
    } else{
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}