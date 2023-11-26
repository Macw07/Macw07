#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int vis[30][3];
char arr1[5][5];
char arr2[5][5];

int main(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            cin >> arr2[i][j];
        }
    }
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            if (arr1[i][j] == arr2[i][j]) a += 1;
            else {
                vis[arr2[i][j] - 'A' + 1][2] += 1;
                vis[arr1[i][j] - 'A' + 1][1] += 1;
            }
        }
    }
    for (int i=1; i<=26; i++) b += min(vis[i][1], vis[i][2]);
    cout << a << endl << b << endl;
    return 0;
}