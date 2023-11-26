// 给你一个整数n，输出n∗n的蛇皮矩阵。

#include <iostream>
using namespace std;

int main(){
    int n, count=0;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=1; j<=n; j++){
            if (i%2==1){
                cout << n*(i+1)+1-j << " ";
            } else{
                cout << j+i*n << " ";
            }    
        }
        cout << endl;
    }
}