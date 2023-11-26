#include <iostream>
using namespace std;

int n, m;
int arr[500005];

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
        char status;
        cin >> status;
        if (status == 'A'){
            int m; cin >> m;
            cout << query(m) << endl;
        } else if (status == 'B'){
            int m, p;
            cin >> m >> p;
            add(m, p);
        } else{
            int m, p;
            cin >> m >> p;
            add(m, -p);
        }
    }
    return 0;
}