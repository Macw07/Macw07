#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int q;
int n, k;
char origin[205][205];
char canvas[205][205];
char stamp[205][205];

// 看错题目了，旋转的是印章！
void rotateSituation(){
    char tmp[100][100] = {};
    for (int i=1; i<=k; i++){
        for (int j=1; j<=k; j++){
            tmp[i][j] = stamp[j][k-i+1];
        }
    }
    for (int i=1; i<=k; i++){
        for (int j=1; j<=k; j++){
            stamp[i][j] = tmp[i][j];
        }
    }
    return ;
}

bool check(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (canvas[i][j] != origin[i][j])
                return false;
        }
    }
    return true;
}

bool checkComfirm(int beginX, int beginY){
    for (int i=beginX, x=1; i<=beginX+k; i++, x++){
        for (int j=beginY, y=1; j<=beginY+k; j++, y++){
            if (origin[i][j] == '.' && stamp[x][y] == '*')
                return false;
        }
    }
    for (int i=beginX, x=1; i<=beginX+k; i++, x++){
        for (int j=beginY, y=1; j<=beginY+k; j++, y++){
            if (stamp[x][y] == '*'){
                canvas[i][j] = '*';
            }
        }
    }
    return true;
}

int main(){
    cin >> q;
    while(q--){
        memset(origin, 0, sizeof origin);
        memset(canvas, 0, sizeof canvas);
        memset(stamp, 0, sizeof stamp);
        cin >> n;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                cin >> origin[i][j];
                canvas[i][j] = '.';
            }
        }
        cin >> k;
        for (int i=1; i<=k; i++){
            for (int j=1; j<=k; j++){
                cin >> stamp[i][j];
            }
        }
        for (int rotate=1; rotate<=4; rotate++){
            for(int i=1; i<=n-k+1; i++){
                for (int j=1; j<=n-k+1; j++){
                    checkComfirm(i, j);
                }
            }
            // for (int i=1; i<=n; i++){
            //     for (int j=1; j<=n; j++){
            //         cout << canvas[i][j];
            //     }
            //     cout << endl;
            // }
            rotateSituation();
        }
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}