#include <iostream>
using namespace std;

const int MAXN = 1e7 + 5;
int n, m, t, a, b;
int arr[MAXN];

inline int lowbit(int k){
    return k & (-k);
}

void add(int x, int t){
    while(x <= n){
        arr[x] += t;
        x += lowbit(x);
    }
    return ;
}

int query(int point){
    int sum = 0;
    while (point){
        sum += arr[point];
        point -= lowbit(point);
    }
    return sum;
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d", &t);
        if (t == 0){
            scanf("%d %d", &a, &b);
            add(a, 1);
            add(b+1, -1);
        } else{
            scanf("%d", &a);
            printf("%d\n", query(a));
        }
    }
    return 0;
}