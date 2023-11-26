#include <iostream>
#include <algorithm>
using namespace std;

// 异或差分
const int MAXN = 1e5 + 5;
int n, m, t, a, b;
int arr[MAXN];

inline int lowbit(int k){
    return k & (-k);
}

void add(int x, int t){
    while(x <= n){
        arr[x] ^= t;
        x += lowbit(x);
    }
    return ;
}

int query(int x){
    int sum = 0;
    while(x){
       sum ^= arr[x];
       x -= lowbit(x);
    }
    return sum;
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d", &a, &b);
            add(a, 1);
            add(b+1, 1);
        } else {
            scanf("%d", &a);
            int p = query(a);
            printf("%d\n", p);
        }
    }
    return 0;
}