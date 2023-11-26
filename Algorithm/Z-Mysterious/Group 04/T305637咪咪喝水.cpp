#include <iostream>
using namespace std;

int arr[205];

int main(){
    int n, t, cnt=0;
    cin >> n >> t;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (arr[i] <= t) cnt++;
    }
    printf("%d", cnt);
    return 0;
}