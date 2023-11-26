#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500005];
int num[500005];

int lowbit(int k){
    return k & (-k);
}

void add(int pos, int value){
    while(pos <= n){
        arr[pos] += value;
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
    for (int i=1; i<=n; i++){
        cin >> num[i];
    }
    while(m--){
        int choice, x, y, k;
        cin >> choice;
        if (choice == 1){
            cin >> x >> y >> k;
            // 差分思想
            add(x, k);
            add(y+1, -k);
            for (int i=1; i<=n; i++) cout << arr[i] << " ";
        } else{
            cin >> x;
            cout << query(x) + num[x] << endl;
        }
    }
    return 0;
}