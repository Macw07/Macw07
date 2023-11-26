#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int t, n, m, len, k;
char c, strT[105];
string str;

void Caesar(int k){
    k = -k;
    if (k >= 0){
        for (int i=0; i<len; i++){
            if (str[i] < 'a' || str[i] > 'z') continue;
            str[i] = char((str[i]+k-97+26)%26+97);
        }
    } else{
        for (int i=0; i<len; i++){
            if (str[i] < 'a' || str[i] > 'z') continue;
            str[i] = char((str[i]-97+26+k%26)%26+97);
        }
    }
    return ;
}

void Atbash(){
    for (int i=0; i<len; i++){
        if (str[i] < 'a' || str[i] > 'z') continue;
        int k = str[i] - 'a' + 1;
        k = 26 - k;
        k += 'a';
        str[i] = k;
    }
    return ;
}

int main(){
    // freopen("read.in", "r", stdin);
    cin >> t;
    k = t;
    while(t-- && k >= 0){
        str = "";
        cin.ignore(1024, '\n');
        getline(cin, str);
        while (str.size() == 0){
            // cin.ignore(1024, '\n');
			getline(cin, str);
			k -= 1;
			if (k <= 0) break;
        }
        len = str.size();
        cin >> n;
        stack<int> s;
        for (int i=1; i<=n; i++){
            cin >> c;
            if (c == 'C') {
                cin >> m;
                s.push(m);
            }
            else if (c == 'A') s.push(-108);
            else s.push(-109);
        }
        while(s.size()){
            t = s.top();
            s.pop();
            if (t == -108) Atbash();
            else if (t == -109) reverse(str.begin(), str.end());
            else Caesar(t);
        }
        cout << str << endl;
    }
    return 0;
}