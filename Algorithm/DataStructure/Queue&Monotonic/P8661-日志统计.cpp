#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int n, d, k;
int max_id;
struct node{
    int ts;
    int id;
} arr[MAXN];
deque<int> que[MAXN];
bool check[MAXN];

bool cmp(node a, node b){
    if (a.ts != b.ts) return a.ts < b.ts;
    return a.id < b.id;
}

int main(){
    scanf("%d %d %d", &n, &d, &k);
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &arr[i].ts, &arr[i].id);
        max_id = max(max_id, arr[i].id);
    }
    sort(arr+1, arr+1+n, cmp);

    for (int i=1; i<=n; i++){
        que[arr[i].id].push_back(arr[i].ts);
        while (!que[arr[i].id].empty() && arr[i].ts - que[arr[i].id].front() >= d) que[arr[i].id].pop_front();
        if (que[arr[i].id].size() >= k) check[arr[i].id] = 1;
    }
    for (int i=0; i<=max_id; i++) if (check[i]) cout << i << endl;

    return 0;
}