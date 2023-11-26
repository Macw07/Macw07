#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e6 + 5;

int n, k;
int arr[MAXN];
int que[2 * MAXN];
int id[2 * MAXN];
int head = 1, tail = 0;

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<=n; i++){
        // 单调递减
        while(head <= tail && arr[i] > que[tail]) tail -= 1;
        que[++tail] = arr[i];
        id[tail] = i;
        if (i - k == id[head]) head += 1;
        if (i >= k) cout << que[head] << endl;
    }
    return 0;
}