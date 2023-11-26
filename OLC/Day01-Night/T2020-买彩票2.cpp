#include <iostream>
using namespace std;

int n, total;
int arr[100005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        int t;
        cin >> t;
        if (arr[t] == 0) total += 1;
        arr[t] += 1;
    }
    cout << total << endl;
    for (int i=1; i<=10000; i++){
        if (arr[i]){
            printf("%d#%d ", i, arr[i]);
        }
    }
    return 0;
}