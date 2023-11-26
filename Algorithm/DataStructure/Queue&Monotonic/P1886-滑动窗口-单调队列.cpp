#include <iostream>
#include <queue>
using namespace std;

int n, k;
int arr[2000005];
int que[2000005];
int id[2000005];
int head = 1, tail = 0;

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }   
    for (int i=1; i<=n; i++){
        // 判断队列的单调性
        while (head <= tail && arr[i] < que[tail]) tail -= 1;
        que[++tail] = arr[i];
        id[tail] = i;
        if (i - k == id[head]) {
            // 把单调队列中不属于这个区间的值删除 
            head += 1;
        }
        if (i >= k) cout << que[head] << " ";
    }
    cout << endl;
    head = 1, tail = 0;
    for (int i=1; i<=n; i++){
        // 单调递减
        while(head <= tail && arr[i] > que[tail]) tail -= 1;
        que[++tail] = arr[i];
        id[tail] = i;
        if (i - k == id[head]) head += 1;
        if (i >= k) cout << que[head] << " ";
    }
    cout << endl;
    return 0;
}