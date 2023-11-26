#include <iostream>
using namespace std;

int arr[] = {0, 1, 2, 8, 18, 48, 75, 144, 196, 320};

// 看错题目了 -_-||
int main(){
    int n, total=0;
    scanf("%d", &n);
    // for (int i=1; i<=n; i++){
    //     for (int j=0; j<=n; j++){
    //         if (j == i) continue;
    //         for (int k=0; k<=n; k++){
    //             if (i == k || j == k) continue;
    //             if ((i*100+j*10+k) % 2 == 1){
    //                 total ++;
    //             }
    //         }
    //     }
    // }
    // printf("%d", total);
    printf("%d", arr[n]);
    return 0;
}