#include <iostream>
#include <algorithm>
using namespace std;

long long n, x, total;
long long arr[100005];

int main(){
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n-1; i++){
        if (arr[i] + arr[i+1] > x) {
            long long dd = (arr[i+1] + arr[i]) - x;
            arr[i+1] -= dd;
            total += dd;
        } 
    }
    cout << total << endl;
    return 0;
}