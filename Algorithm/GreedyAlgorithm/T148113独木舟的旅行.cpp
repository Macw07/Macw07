#include <iostream>
#include <algorithm>

int arr[305];

int main(){
    int s, w, n, l, r;
    scanf("%d", &s);
    while(s--){
        int total = 0;
        scanf("%d%d", &w, &n);
        for (int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        std::sort(arr, arr+n);  // 给他们排排队
        l = 1, r = n;
        while(l <= r){
            if (arr[l]+arr[r] > w) {total++; r--;}
            else {total++; l++; r--;}
        }
        printf("%d\n", total);
    }
    return 0;
}