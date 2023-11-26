#include <iostream>
using namespace std;

int n, m, ans;
int x, y, t;
int prefix[5050][5050];

int main(){
    cin >> n >> m;
    while(n--){
        cin >> x >> y >> t;;
        prefix[x+1][y+1] = t;
    }
    for (int i=1; i<=5005; i++){
        for (int j=1; j<=5005; j++){
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];   
        }
    }
    // 枚举坐标
    for (int i=m; i<=5005; i++){
        for (int j=m; j<=5005; j++){
            int sum = prefix[i][j] - prefix[i-m][j] - prefix[i][j-m] + prefix[i-m][j-m];
            ans = max(sum, ans);
        }
    }
    cout << ans << endl;
    return 0;
}