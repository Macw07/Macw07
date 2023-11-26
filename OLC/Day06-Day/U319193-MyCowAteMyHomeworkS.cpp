#include <iostream>
#include <vector>
using namespace std;

int n;
double avg;
long long prefix_sum[100005];
vector<long long> vct;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%lld", &prefix_sum[i]);
        prefix_sum[i] += prefix_sum[i-1];
    }
    // 枚举所有k的情况。
    for (int i=1; i<=n-2; i++){
        double k = (prefix_sum[n] - prefix_sum[i]) / 1.0 / (n-i);
        if (k > avg){
            // cout << k << endl;
            avg = k;
            vct.clear();
            vct.push_back(i);
        } else if (k == avg) vct.push_back(i);
    }
    for (int i=0; i<vct.size(); i++) cout << vct[i] << endl;
    return 0;
}