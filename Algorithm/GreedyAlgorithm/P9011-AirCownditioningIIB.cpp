#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
struct cow{
    int si;
    int ti;
    int ci;
};
struct aircon{
    int ai;
    int bi;
    int pi;
    int mi;
};
cow cows[1005];
aircon aircons[1005];
int arr[10005];
int ans_cost = 0x7f7f7f7f;

bool check(){
    for (int i=1; i<=100; i++){
        if (arr[i] > 0){
            return false;
        }
    }
    return true;
}

void dfs(int depth, int cost){
    if (cost > ans_cost) return ;
    if (check()){
        ans_cost = min(ans_cost, cost);
        return ;
    }
    if (depth > m) return ;
    {
        for (int i=aircons[depth].ai; i<=aircons[depth].bi; i++) arr[i] -= aircons[depth].pi;
        dfs(depth + 1, cost + aircons[depth].mi);
        for (int i=aircons[depth].ai; i<=aircons[depth].bi; i++) arr[i] += aircons[depth].pi;
    }
    dfs(depth + 1, cost);
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int ti, si, ci;
        cin >> si >> ti >> ci;
        cows[i] = (cow){si, ti, ci};
        for (int j=si; j<=ti; j++){
            arr[j] = ci;
        }
    }
    for (int j=1; j<=m; j++) {
        int ai, bi, pi, mi;
        cin >> ai >> bi >> pi >> mi;
        aircons[j] = (aircon){ai, bi, pi, mi};
    }
    dfs(1, 0);
    cout << ans_cost << endl;
    return 0;
}