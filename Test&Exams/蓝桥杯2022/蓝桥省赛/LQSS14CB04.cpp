#include <iostream>
#include <algorithm>
using namespace std;

int n, max_h;
int arr[1000005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        max_h = max(max_h, arr[i]);
    }
    int l = n, r = max_h;
    while(l <= r){
        int mid = (l+r) >> 1;
        if (check(mid)){
            l = mid + 1;
            
        }
    }
    return 0;
}