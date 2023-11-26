#include <iostream>
using namespace std;

// 分块
int n, a, b, cnt;
const int MAXN = 5e5 + 5;
char cows[MAXN];
long long group[MAXN];
long long ans;


int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> cows[i];
        if (cows[i] == cows[i-1]){
            group[cnt] += 1;
        } else{
            cnt += 1;
            group[cnt] += 1;
        }
    }
    
    for (int i=1; i<cnt; i++){
        if (group[i] == 1){
            ans += group[i-1] * group[i+1] + group[i+1] - 1;
        } else ans += group[i] + group[i+1] - 2;
    }

    cout << ans << endl;
    return 0;
}