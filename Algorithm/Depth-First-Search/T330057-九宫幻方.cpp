#include <iostream>
#include <algorithm>
using namespace std;

int vis[15];
int arr[5][5];
int ans[5][5];
bool flag = true;

bool check(){
    int sum = arr[1][1] + arr[1][2] + arr[1][3]; 
    for (int i=1; i<=3; i++){
        int temp = 0;
        for (int j=1; j<=3; j++){
            temp += arr[i][j];
        }
        if (temp != sum) return false;
    }
    for (int i=1; i<=3; i++){
        int temp = 0;
        for (int j=1; j<=3; j++){
            temp += arr[j][i];
        }
        if (temp != sum) return false;
    }
    return true;
}

void copy(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            ans[i][j] = arr[i][j];
        }
    }
    return ;
}

void dfs(int x, int y){
    if (y == 4){
        x += 1;
        y = 1;
    }

    if (x == 4){
        if (check()) {
            if (flag){
                flag = false;
                copy();
            } else{
                cout << "Too Many" << endl;
                exit(0);
            }
        }
        return ;
    } 
    if (arr[x][y] != 0) {
        dfs(x, y+1);
        return ;
    }

    for (int i=1; i<=9; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        arr[x][y] = i;
        dfs(x, y+1);
        arr[x][y] = 0;
        vis[i] = 0;
    }
    return ;
}

int main(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            cin >> arr[i][j];
            vis[arr[i][j]] = 1;
        }
    }
    dfs(1, 1);
    if (!flag){
        for (int i=1; i<=3; i++){
            for (int j=1; j<=3; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else cout << "Too Many" << endl;
    return 0;
}