#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

long long n, sum, avg, t;
long long arr[200005], ans;
struct perEdge{
    long long to;
    long long next;
} edges[200005 << 1];
long long f[200005];
long long vertex[200005], ei;

void add(long long v1, long long v2){
    ei += 1;
    edges[ei].to = v2;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(long long node, long long father){
    long long index = vertex[node];
    long long tmp = 0;
    while(index){
        long long to = edges[index].to;
        if ((tmp = to) != father){
            dfs(tmp, node);
        }
        index = edges[index].next;
    }
    f[node] = arr[node] - avg;
    arr[father] += f[node];
    ans += (bool)f[node];
    return ;
}

void solve(long long node, long long father){
    long long index = vertex[node];
    long long tmp = 0;
    while(index){
        long long to = edges[index].to;
        if (!((tmp = to) == father || f[tmp] < 0)){
            solve(tmp, node);
        }
        index = edges[index].next;
    }
    index = vertex[node];
    tmp = 0;
    while(index){
        long long to = edges[index].to;
        if (!((tmp = to) == father || f[tmp] >= 0)){
            cout << node << " " << tmp << " " << -f[tmp] << endl;
            solve(tmp, node);
        }
        index = edges[index].next;
    }
    if (f[node] > 0){
        cout << node << " " << father << " " << f[node] << endl;
    }
    return ;
}

signed main(){
    cin >> n;
    for (long long i=1; i<=n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    avg = sum / n;
    for (long long i=1; i<n; i++){
        long long u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    cout << ans << endl;
    solve(1, 0);
    return 0;
}