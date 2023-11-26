#include <iostream>
using namespace std;

int w[] = {1, 2, 3, 5, 10, 20};
int arr[1005];
int head = 1, cnt = 0;
int memo[1005];

int dfs(int index, int sum){
    if (sum != 0 && memo[sum] == 0){
        memo[sum] = 1;
        cnt++;
    }
    if (index >= head) return 0;
    for (int i=index; i<head; i++){
        dfs(i+1, sum+arr[i]);
    }
    return 0;
}

int main(){
    for (int i=0; i<6; i++){
        int t;
        cin >> t;
        for (int j=0; j<t; j++){
            arr[head++] = w[i];
        }
    }
    dfs(0, 0);
    printf("Total=%d\n", cnt);
    return 0;
}