#include <iostream>
#include <algorithm>
using namespace std;

int n, p, cnt;
int arr[10005];

int main(){
    // freopen("Data/testcase15.in", "r", stdin);
    // freopen("Data/testcase15.out", "w", stdout);
    cin >> n >> p;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    for (int i=1; i<=n; i++){
        for (int k=i+1; k<=n; k++){
            for (int j=k+1; j<=n; j++){
                if (arr[j] - arr[i] == p){
                    cnt += 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}