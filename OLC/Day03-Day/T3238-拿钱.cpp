#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cap, total;
int arr[505];

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    sort(arr+1, arr+1+n); cap = n - m + 1;
    for (int i=n; i>=cap; i--) total += arr[i];
    cout << total << endl;
    return 0;
}