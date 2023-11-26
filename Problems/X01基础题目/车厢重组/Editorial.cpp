#include <iostream>
using namespace std;

int n, cnt, arr[6005];

int main(){
    // freopen("testcase001.in", "r", stdin);
    // freopen("testcase001.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (arr[i] > arr[j]){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}