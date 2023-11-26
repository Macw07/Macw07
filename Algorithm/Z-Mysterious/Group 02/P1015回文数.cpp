#include <iostream>
#include <algorithm>
using namespace std;

int sys, steps=0;
string n;

// ? 无语住了，这道题竟然有字母，让我写的好心累啊。

string hp(string a, string b){
    string ans;
    int c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int la = a.size(), lb = b.size();
    for (int i=0, j=0; i<la || j<lb || c; ){
        if (a[i] >= 'A' && a[i] <= 'Z'){
            if (i<la) c += a[i++]-'A'+10;
        }else if (i<la) c += a[i++]-'0';
        if (b[j] >= 'A' && b[j] <= 'Z'){
            if (j<lb) c += b[j++]-'A'+10;
        }else if (j<lb) c += b[j++]-'0';

        if (c%sys >= 10) ans += char(c%sys+'A'-10);
        else ans += (c%sys)+'0';
        c /= sys;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check(){
    string rn = n;
    reverse(rn.begin(), rn.end());
    return rn == n;
}

int main(){
    cin >> sys >> n;
    while(!check()){
        steps++;
        if (steps > 30) break;
        string rn = n;
        reverse(rn.begin(), rn.end());
        n = hp(n, rn);
    }
    if (steps <= 30) printf("STEP=%d\n", steps);
    else printf("Impossible!\n");
    return 0;
}