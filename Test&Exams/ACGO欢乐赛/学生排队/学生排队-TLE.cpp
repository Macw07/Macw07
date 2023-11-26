#include <iostream>
using namespace std;

int n, t;
int arr[1000005];

int main(){
    // freopen("Data/case010.in", "r", stdin);
    // freopen("Data/case010-2.out", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        int t = 0;
        scanf("%d", &arr[i]);
        for (int j=i-1; j>=1; j--){
            if (arr[j] < arr[i]){
                printf("%d ", arr[j]);
                t = 1;
                break;
            }
        }
        if (t == 0) printf("-1 ");
    }
    return 0;
}