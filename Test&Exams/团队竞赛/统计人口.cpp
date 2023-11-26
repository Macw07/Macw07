#include <iostream>
using namespace std;

int n, t;
int arr[1005];

int main(){
    cin >> n;
    while(n--){
        cin >> t;
        arr[t] += 1;
    }
    // 计数排序。
    for (int i=1; i<=1000; i++){
        if (arr[i]){
            cout << i << " ";
        }
    }
    return 0;
}