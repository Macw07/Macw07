#include <iostream>
using namespace std;

int arr[10000005];
int dxy[] = {-2, -1, 0, 1, 2};

int main(){
    int n, m, cnt=0;
    cin >> n >> m;
    while(m--){
        int t;
        cin >> t;
        for (int j=0; j<5; j++){
            if (t + dxy[j] >= 1 && t + dxy[j] <= n){
                arr[t+dxy[j]]++;
            }
        }
    }
    for (int i=1; i<=n; i++){
        if (arr[i] >= 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}