#include <iostream>
#include <algorithm>
using namespace std;

int n, total;
int t1, t2;  // t1 代表工作数量，t2 代表工作时长
int arr[105];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    sort(arr+1, arr+1+n);
    for (int i=n; i>=1; i--){
        t1 += 1;
        t2 += arr[i];
        // cout << t1 << " " << t2 << endl;
        if (total - t2 < t2){
            cout << t1 << endl;
            break;
        }
    }
    return 0;
}