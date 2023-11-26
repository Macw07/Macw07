#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10005];

int main(){
    freopen("war.in", "r", stdin);
    freopen("war.out", "w", stdout);
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cout << arr[m] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}