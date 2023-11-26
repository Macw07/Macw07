#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[100005];
int vis[100005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    int x = 1;
    int abc = 100;
    while(abc--){
        while(x <= n){
            if (arr[x] >= 2){
                arr[x] -= 1;
                x += 1;
                cout << 'R';
            } else break;
        }

        while (true){
            if (x <= n && (arr[x] > 1 || vis[x+1])) vis[x] = 1;
            if (x >= 0 && (!vis[x] || arr[x-1] > 1)){
                x -= 1;
                arr[x] -= 1;
                cout << 'L';
            }
            else break;
        }

        if (x == 1 && !vis[1]) break;
    }
    return 0;
}