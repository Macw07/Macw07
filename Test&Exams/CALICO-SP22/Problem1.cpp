#include <iostream>
using namespace std;

int t, n, m;
char arr[105][105];

void init(){
    for (int i=1; i<=100; i+=2){
        for (int j=1; j<=100; j+=2){
            arr[i][j] = 'B';
            arr[i][j+1] = 'G';
            arr[i+1][j] = 'G';
            arr[i+1][j+1] = 'R';
        }
    }
    return ;
}

int main(){
    scanf("%d", &t);
    init();
    while(t--){
        scanf("%dx%d", &n, &m);
        for(int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}