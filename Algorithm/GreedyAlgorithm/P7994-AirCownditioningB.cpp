#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e5;
int n;
int origin[MAXN + 5];
int target[MAXN + 5];
int diff[MAXN + 5];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &origin[i]);
    for (int i=1; i<=n; i++){
        scanf("%d", &target[i]);
        diff[i] = origin[i] - target[i];
    }
    int i = 1, j = n;
    long long ans = 0;
    while(i < j){
        while(i <= j && diff[i] == 0) i++;
        while(i <= j && diff[j] == 0) j--;
        if (diff[i] < 0){
            int k = i, min_ = abs(diff[i]);
            while(k <= j && diff[k+1] < 0) {
                k += 1;
                min_ = min(min_, abs(diff[k]));
            }
            for (int l=i; l<=k; l++) diff[l] += min_;
            ans += min_;
        } else if (diff[i] > 0){
            int k = i, min_ = diff[i];
            while(k <= j && diff[k+1] > 0) {
                k += 1;
                min_ = min(min_, diff[k]);
            }
            for (int l=i; l<=k; l++) diff[l] -= min_;
            ans += min_;
        }
    }
    cout << ans << endl;
    return 0;
}