#include <iostream>
using namespace std;

int n, m, s1, s2;
struct dimension{ int x; int y;};
dimension arr[1005][1005];

int main(){
    cin >> m >> n >> s1 >> s2;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j].x >> arr[i][j].y;
        }
    }
    
    int nx = s1, ny = s2;
    while (nx && ny){
        cout << nx << ' ' << ny << endl;
        int tx = arr[nx][ny].x;
        int ty = arr[nx][ny].y;
        nx = tx, ny = ty;
    }
    return 0;
}