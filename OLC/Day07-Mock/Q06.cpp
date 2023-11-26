#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int t, m;
string n, q;
int primes[10005], vis[10005];
bool flag = false;
int path[10005];

struct node{
    string num;
    int steps;
};

void isPrime(int k){
    vis[0] = vis[1] = 1;
    for (int i=2; i<=k; i++){
        if (!vis[i]) primes[++m] = i;
        for (int j=1; j<=m&&primes[j]*i<=k; j++){
            vis[primes[j]*i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    return ;
}   

int convert(string k){
    int sum = 0, len = k.size();
    for (int i=0; i<len; i++){
        sum = sum * 10 + (k[i] - '0');
    }
    return sum;
}

void bfs(){
    queue<node> que;
    que.push((node){n, 0});
    path[convert(n)] = 1;

    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (t.num == q){
            cout << t.steps << endl;
            flag = true;
            return ;
        }
        // 对每个数位尝试，将t.num[i]尝试变成j。
        for (int i=0; i<4; i++){
            for (int j=0; j<=9; j++){
                if (i == 0 && j == 0) continue;
                string n_str = t.num;
                n_str[i] = (j + '0');
                int num = convert(n_str);
                if (path[num]) continue;
                if (vis[num]) continue; 
                path[num] = 1;
                que.push((node){n_str, t.steps + 1});
            }
        }
    }
    return ;
}

int main(){
    freopen("duan.in", "r", stdin);
    freopen("duan.out", "w", stdout);
    cin >> t;
    isPrime(10000);
    while(t--){
        cin >> n >> q;
        flag = false;
        memset(path, 0, sizeof path);
        if (vis[convert(n)] || vis[convert(q)]){
            cout << 0 << endl;
            continue;
        }
        bfs();
        if (!flag) cout << 0 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}