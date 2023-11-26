#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500005];

int lowbit(int x){
    return x & (-x);
}

void add(int x, int t){
    while(x <= n){
        arr[x] += t;
        x += lowbit(x);
    }
    return ;
}

int query(int x){
    int sum = 0;
    while(x){
        sum += arr[x];
        x -= lowbit(x);
    }
    return sum;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        add(i, t);
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1){
            add(b, c);
        } else{
            cout << query(c) - query(b-1) << endl;
        }
    }
    return 0;
}