#include <iostream>
#include <queue>
using namespace std;

// 真不容易，一道题用了两种写法，改了n次才过。凶。

int n;
struct segment{
    int type;
    // [start, end]
    int start;
    int end;
};
int arr[200005];
int vis[200005];
queue<segment> que;
queue<segment> tmp;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    int color = 0; arr[n+1] = -1;
    for (int i=1, s=1; i<=n; i++){
        if (arr[i] != arr[i+1]){
            que.push((segment){arr[i], s, i});
            s = i+1;
        }
    }
    while(que.size()){
        while(que.size()){
            segment t = que.front();
            que.pop();
            while (vis[t.start] && t.start <= t.end) t.start++;
            if (t.start > t.end) continue;
            vis[t.start] = 1;
            printf("%d ", t.start);
            if (t.start == t.end) continue;
            t.start ++;
            tmp.push(t);
        }
        printf("\n");
        while(tmp.size()){
            segment t = tmp.front();
            tmp.pop();
            while(tmp.size()){
                segment k = tmp.front();
                if (t.type == k.type){
                    t.end = k.end;
                    tmp.pop();
                } else break;
            }
            que.push(t);
        }
    }
    return 0;
}