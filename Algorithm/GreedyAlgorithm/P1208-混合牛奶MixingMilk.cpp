#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, total, cnt;
struct node{
    int p, a;
} arr[10005];

bool cmp(node a, node b){ return a.p < b.p;}

int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> arr[i].p >> arr[i].a;
    sort(arr, arr+m, cmp);
    for (int i=0; i<m; i++){
        if (cnt + arr[i].a > n){
            int demand = n - cnt;
            total += arr[i].p * demand;
            break;
        } else cnt += arr[i].a, total += arr[i].a * arr[i].p;
    }
    cout << total << endl;
    return 0;
}