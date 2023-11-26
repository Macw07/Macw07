#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[1050][1050];

void transformation(int x, int y, int depth, int t){
    if (depth == 0){
        arr[x][y] = t;
        return ;
    }
    int contineous = 1 << (depth-1);
    transformation(x, y, depth-1, t);
    transformation(x, y+contineous, depth-1, t);
    transformation(x+contineous, y, depth-1, t);
    transformation(x+contineous, y+contineous, depth-1, !t);
    return ;    
}

int main(){
    cin >> n;
    arr[1][1] = 1;
    transformation(1, 1, n, 1);
    for (int i=1; i<=pow(2, n); i++){
        for (int j=1; j<=pow(2, n); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}