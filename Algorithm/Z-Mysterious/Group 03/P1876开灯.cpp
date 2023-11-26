#include <iostream>
using namespace std;

bool arr[100005];

int main(){
    long long n;
    cin >> n;
    // for (long long i=1; i<=n; i++){
    //     for (long long j=i; j<=n; j+=i){
    //         if (arr[j] == 0){
    //             arr[j] = 1;
    //         } else{
    //             arr[j] = 0;
    //         }
    //     }
    // }
    // for (long long i=1; i<=n; i++){
    //     if (arr[i] == 1){
    //         cout << i << " ";
    //     }
    // }
    for (long long i=1; i*i<=n; i++){
        cout << i*i << " ";
    }
    return 0;
}