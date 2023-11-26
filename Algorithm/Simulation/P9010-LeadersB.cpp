#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int cnt1, cnt2;
int arr[MAXN + 5];
char breed[MAXN + 5];
int holstein[MAXN + 5];
int guernsey[MAXN + 5];
int leaderH[MAXN + 5];
int leaderG[MAXN + 5];
// 满足两个的话就是一对
long long ans = 0;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> breed[i];
        if (breed[i] == 'H') {
            holstein[i] += 1;
            cnt1 += 1;
        } else{
            guernsey[i] += 1;
            cnt2 += 1;
        }
        holstein[i] += holstein[i-1];
        guernsey[i] += guernsey[i-1];
    }
    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=n; i>=1; i--){
        if (breed[i] == 'H'){
            // 查看是否全都是H。
            int countH = holstein[arr[i]] - holstein[i-1];
            bool flag = false;
            if (countH == cnt1){
                // 证明这一头奶牛是领导者。
                flag = true;
                leaderH[i] += 1;
            }
            leaderG[i] += leaderG[i+1];
            leaderH[i] += leaderH[i+1];
            // 查看是否有其他品种的领导者，如果有即可构成一对。
            int countL = leaderG[i] - leaderG[arr[i]+1];
            if (countL) {
                leaderH[i] += 1;
                flag = true;
            }
            ans += flag * leaderG[i];
        } else {
            int countG = guernsey[arr[i]] - guernsey[i-1];
            bool flag = false;
            if (countG == cnt2){
                leaderG[i] += 1;
                flag = true;
            }
            leaderG[i] += leaderG[i+1];
            leaderH[i] += leaderH[i+1];
            int countL = leaderH[i] - leaderH[arr[i]+1];
            if (countL) {
                leaderG[i] += 1;
                flag = true;
            }
            ans += flag * leaderH[i];
        }
    }
    cout << ans << endl;
    return 0;
}