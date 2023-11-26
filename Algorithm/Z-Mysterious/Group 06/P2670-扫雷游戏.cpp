#include <iostream>
#include <algorithm>
using namespace std;

char arr[105][105];
int n, m;
int dx[] = {1,0,-1,0,-1,1,1,-1};
int dy[] = {0,1,0,-1,-1,-1,1,1};

int count(int n, int m){
    int total = 0;
    for (int i=0; i<8; i++){
        int cx = n + dx[i];
        int cy = m + dy[i];
        if (arr[cx][cy] == '*'){
            total += 1;
        }
    }
    return total;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] == '*'){
                cout << '*';
            } else cout << count(i, j);
        }
        cout << endl;
    }
    return 0;
}