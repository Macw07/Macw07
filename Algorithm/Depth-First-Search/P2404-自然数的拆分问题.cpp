#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000] = {1};

void dfs(int remain, int index){
    if (remain == 0){
        for (int i=1; i<index-1; i++) cout << arr[i] << '+';
        cout << arr[index-1] << endl;
        return ;
    }

    for (int i=arr[index-1]; i<=remain; i++){
        if (i < n){
            arr[index] = i;
            dfs(remain-i, index+1);
            arr[index] = 0;
        }
    }
    return ;
}

int main(){
    cin >> n;
    dfs(n, 1);
    return 0;
}