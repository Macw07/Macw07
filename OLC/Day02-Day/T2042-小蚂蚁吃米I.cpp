#include <iostream>
using namespace std;

int n, x;
long long prefix_sum[100005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    cin >> x;
    cout << prefix_sum[x] << endl;
    return 0;
}