#include <iostream>
#include <algorithm>
using namespace std;

int n, b;
long long arr[20005];
long long total = 0;

int main(){
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
    cin >> n >> b;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n, greater<int>());
    for (int i=1; i<=n; i++){
        total += arr[i];
        if (total >= b){
            cout << i << endl;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}