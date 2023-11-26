#include <iostream>
#include <algorithm>
using namespace std;

int w[] = {1, 2, 3, 5, 10, 20};
int num = 1, cnt = 0;
int arr[10005], memo[10005];

int main(){
    for (int i=0; i<6; i++){
        int t;
        cin >> t;
        for (int j=0; j<t; j++){
            arr[num++] = w[i];
        }
    }
    memo[0] = 1;
    for (int i=1; i<=num; i++){  // 遍历每一个砝码
        for (int j=1005; j>=0; j--){  // 从后往前遍历每个价值
            if (memo[j]) memo[j+arr[i]] = 1;
        }
    }
    for (int i=1; i<=1005; i++){
        if (memo[i]) cnt++;
    }
    printf("Total=%d\n", cnt);
    return 0;
}