#include <iostream>
#include <vector>
using namespace std;

int n, ans_x, ans_y;
int arr[105][105];
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
long long ans = -0x7f7f7f7f;

struct coordinate{int x; int y;};
vector<coordinate> vec;

long long area(int i, int j){
    long long total = 1;
    for (int k=0; k<8; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        total *= arr[nx][ny];
    }
    total *= arr[i][j];
    return total;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            long long t = area(i, j);
            if (t > ans){
                ans = t;
                vec.clear();
                vec.push_back((coordinate){i, j});
            } else if (t == ans){
                vec.push_back((coordinate){i, j});
            }
        }
    }
    for (int i=0; i<vec.size(); i++){
        cout << vec[i].x << " " << vec[i].y << endl;
    }
    return 0;
}