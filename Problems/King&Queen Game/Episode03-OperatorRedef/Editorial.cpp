#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;

string str;
stack<ll> num;
stack<char> operators; 

inline ll operation(ll a, ll b){
    ll ans = abs(a*a - b*b);
    return ans;
}

inline ll calculate(){
    if (num.size() < 2) return -1;
    ll a = num.top(); num.pop();
    ll b = num.top(); num.pop();
    return operation(a, b);
}

inline bool isDigit(char t){
    if (t >= '0' && t <= '9'){
        return true;
    }
    return false;
}

inline ll oLevel(char opt){
    if (opt == '&') return 1;
    return -1;
}

signed main(){
    // freopen("Data/testcase005.in", "r", stdin);
    // freopen("Data/testcase005.out", "w", stdout);
    cin >> str;
    ll len = str.size();
    ll i = 0;
    while(true){
        if (isDigit(str[i])){
            num.push(str[i] - '0');
            i += 1;
        } else{
            if (i >= len && operators.empty()){
                cout << num.top() << endl;
                break;
            } 
            if (operators.empty()){
                operators.push(str[i]);
                i += 1;
            }
            else if (str[i] == '(' || oLevel(operators.top()) < oLevel(str[i])){
                operators.push(str[i]);
                i += 1;
            } else if (operators.size() && str[i] == ')' && operators.top() == '('){
                operators.pop();
                i += 1;
            }  else if (oLevel(operators.top()) >= oLevel(str[i])){
                operators.pop();
                ll k = calculate();
                num.push(k);
            }
        }
    }
    return 0;
}