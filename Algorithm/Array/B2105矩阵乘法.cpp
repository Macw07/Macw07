#include <iostream>
using namespace std;

int a[105][105];
int b[105][105];
int c[105][105];
int n, m, k;

void setc(int i, int j){
    for (int mm=0; mm<m; mm++){
        c[i][j] += a[i][mm] * b[mm][j];
    }
}

int main(){
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<k; j++){
            cin >> b[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            setc(i, j);
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}