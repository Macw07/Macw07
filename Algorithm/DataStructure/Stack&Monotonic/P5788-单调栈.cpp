#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[3000005], ans[3000005];
stack<int> stk;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for (int i=n; i>=1; i--){
        while(!stk.empty() && arr[stk.top()] <= arr[i]) stk.pop();
        if (stk.empty()) ans[i] = 0;
        else ans[i] = stk.top();
        stk.push(i);
    }
    for (int i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}