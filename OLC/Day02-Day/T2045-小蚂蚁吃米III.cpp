#include <iostream>
using namespace std;

int n, t, x, y;
long long prefix_sum[100005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << prefix_sum[y]  - prefix_sum[x-1] << endl;
    }
    return 0;
}