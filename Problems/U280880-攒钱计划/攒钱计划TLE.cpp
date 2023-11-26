#include <iostream>
using namespace std;

long long n, k;
long long cnt = 0;

int main(){
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &k);
        cnt = 0;
        for (int i=1; i<=k; i++){
            cnt += i;
            if (cnt >= k){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}