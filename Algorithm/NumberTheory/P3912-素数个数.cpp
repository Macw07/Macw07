#include <iostream>
using namespace std;

int n, cnt;
bool arr[100000005];

int main(){
    scanf("%d", &n);
    for (int i=2; i*i<=n; i++){
        if (arr[i] == 1) continue;
        if (i * i > n) continue;
        for (int j=i*i; j<=n; j+=i){
            arr[j] = 1; 
        }
    }
    arr[1] = 1;
    for (int i=1; i<=n; i++){
        if (arr[i] == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}