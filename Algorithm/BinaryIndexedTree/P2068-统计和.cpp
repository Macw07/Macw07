#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long arr[100000];

int lowbit(int k){
    return k & (-k);
}

long long query(int pos){
    long long sum = 0;
    while(pos){
        sum += arr[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

void add(int pos, int k){
    while(pos <= n){
        arr[pos] += k;
        pos += lowbit(pos);
    }
    return ;
}

int main(){
    cin >> n >> m;
    while(m--){
        char k;
        int a, b;
        cin >> k >> a >> b;
        if (k == 'x'){
            add(a, b);
        } else{
            cout << query(b) - query(a-1) << endl;
        }
    }
    return 0;
}