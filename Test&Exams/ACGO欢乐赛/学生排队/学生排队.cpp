#include <iostream>
#include <stack>
using namespace std;

int n, t;
stack<int> stk;

int main(){
    // freopen("Data/case007.in", "r", stdin);
    // freopen("Data/case007.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        while(!stk.empty() && stk.top() >= t) stk.pop();
        if (stk.empty()) cout << -1 << " ";
        else cout << stk.top() << " ";
        stk.push(t);
    }
    return 0;
}