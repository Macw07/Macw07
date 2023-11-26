#include <iostream>
using namespace std;

// 差分思想
int n, m;
int arr[100005];

int lowbit(int k){
    return k & (-k);
}

void add(int pos, int k){
    while(pos <= n){
        arr[pos] += k;
        pos += lowbit(pos);
    }
    return ;
}

int query(int pos){
    int sum = 0;
    while(pos){
        sum += arr[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main(){
    cin >> n >> m;
    while(m--){
        int t, a, b;
        cin >> t;
        if (t == 1){
            cin >> a >> b;
            add(a, 1);
            add(b+1, -1);
        } else{
            cin >> b;
            cout << query(b) % 2 << endl;
        }
    }
    return 0;
}