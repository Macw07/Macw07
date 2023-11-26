#include <iostream>
#include <stack>
using namespace std;

int n, m;
int arr[1000005], ans[1000005];
stack<int> stk;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for (int j=n; j>=1; j--){
        while(!stk.empty() && arr[stk.top()] <= arr[j]) stk.pop();
        if (stk.empty()) ans[j] = 0;
        else ans[j] = stk.top();
        stk.push(j);
    }
    for (int i=1; i<=n; i++) printf("%d\n", ans[i]);
    return 0;
}