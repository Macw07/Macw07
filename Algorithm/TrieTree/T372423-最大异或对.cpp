#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
int n, arr[MAXN];
int ans = 0;
int depth = 0;
int trie[31 * MAXN][2];

void insert(int num){
    int root = 0;
    for (int i=30; i>=0; i--){
        int t = num >> i & 1;
        if(trie[root][t] == 0){
            trie[root][t] = ++depth;
        }
        root = trie[root][t];
    }
    return ;
}

int query(int num){
    int root = 0, ans = 0;
    for (int i=30; i>=0; i--){
        int t = num >> i & 1;
        if (trie[root][!t]){
            root = trie[root][!t];
            ans = ans * 2 + !t;
        } else{
            root = trie[root][t];
            ans = ans * 2 + t;
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        insert(arr[i]);
    }
    for (int i=1; i<=n; i++){
        int t = query(arr[i]);
        ans = max(ans, arr[i] ^ t);
    }
    cout << ans << endl;
    return 0;
}