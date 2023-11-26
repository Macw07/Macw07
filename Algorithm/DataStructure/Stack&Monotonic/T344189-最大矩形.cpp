#include <iostream>
#include <stack>
using namespace std;

long long n, t, ans;
struct node{
    long long value;
    long long position;
};
stack<node> stk;

// 无语了，搞半天忘记更新答案了。
// to maintain a monotonically increasing stack.
int main(){
    scanf("%lld", &n);
    stk.push((node){0, 0});
    for (int i=1; i<=n; i++){
        scanf("%lld", &t);
        while(stk.size()>1 && stk.top().value >= t) {
            node tmp = stk.top();
            stk.pop();
            long long new_ans = tmp.value * (i - stk.top().position - 1);
            ans = max(ans, new_ans);
        }
        stk.push((node){t, i});
    }
    while(stk.size() > 1){
        node tmp = stk.top();
        stk.pop();
        long long new_ans = tmp.value * (n-stk.top().position);
        ans = max(ans, new_ans);
    }

    cout << ans << endl;
    return 0;
}