#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans = -1;
string str;

int find(int k){
    int total = 0;
    char c1 = str[k+1];
    for(int i=k+1; ; i++){
        if (str[i] == c1 || str[i] == 'w'){
            total += 1;
        } else break;
    }
    char c2 = str[k];
    for (int i=k; ; i--){
        if (str[i] == c2 || str[i] == 'w'){
            total += 1;
        } else break;
    }
    return total;
}

int main(){
    cin >> n >> str;
    str = str + str + str;
    for (int i=n; i<2*n; i++){
        if (str[i] == str[i+1]) continue;
        if (str[i] == 'w'){
            str[i] = 'r';
            ans = max(ans, find(i));
            str[i] = 'b';
            ans = max(ans, find(i));
            str[i] = 'w';
        } else ans = max(ans, find(i));
    }
    ans = min(ans, n);
    if (ans == -1) cout << n << endl;
    else cout << ans << endl;
    return 0;
}