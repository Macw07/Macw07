#include <iostream>
#include <algorithm>
using namespace std;

int n, p, cnt;
int arr[10005];

int main(){
    // freopen("Data/testcase10.in", "r", stdin);
    // freopen("Data/testcase10.out", "w", stdout);
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    for (int i=1; i<=n; i++){
        for (int j=i+2; j<=n; j++){
            if (arr[j] - arr[i] == p){
                cnt += j - i - 1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}