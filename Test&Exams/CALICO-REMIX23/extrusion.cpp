#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 3005;
int T, n, m, d;
char map[MAXN][MAXN];
char origin[MAXN][MAXN];

struct vertex{
    int x1, y1;
    int x2, y2;
};

vector<vertex> vertices;

void dfs(int x1, int y1, int x2, int y2){
    if (x1 == x2 && y1 == y2) return ;
    map[x1+1][y1+1] = '\\';
    dfs(x1+1, y1+1, x2, y2);
    return ;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> d;
        vector<vector<char> > base(n);
        cin.ignore();
        // memset(map, 0, sizeof map);
        // memset(origin, 0, sizeof origin);
        for (int i=0; i<n; i++){
            string str;
            getline(cin, str);
            for (int j=0; j<m; j++){
                map[i][j] = str[j];
                origin[i][j] = map[i][j];
                if (map[i][j] == '+'){
                    vertices.push_back((vertex){i, j, i+d, j+d});
                }
            }
        }

        for (int i=0; i<vertices.size(); i++){
            vertex t = vertices[i];
            dfs(t.x1, t.y1, t.x2, t.y2);
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (origin[i][j] == ' ') continue;
                map[i+d+1][j+d+1] = origin[i][j];
            }
        }

        for (int i=0; i<=n+d; i++){
            for (int j=0; j<=m+d; j++){
                if (map[i][j]) cout << map[i][j];
                else cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}