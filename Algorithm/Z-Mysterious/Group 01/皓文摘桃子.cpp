/* 皓文家的院子里有一棵桃子树，每年树上就会结出10个桃子。桃子成熟的时候，皓文就会跑去摘桃子。
皓文有个30厘米高的板凳，当她不能直接用手摘到桃子的时候，就会踩到板凳上再试试。
现在已知10个桃子到地面的高度，以及皓文把手伸直的时候能够达到的最大高度，请帮皓文算一下她能够摘到的桃子的数目 */

#include <iostream>
using namespace std;

int arr[15] = {};

int main(){
    int height;
    int count = 0;
    for (int i=0; i<10; i++){
        cin >> arr[i];
    }
    cin >> height;
    for (int i=0; i<10; i++){
        if (arr[i] <= height+30){
            count++;
        }
    }
    cout << count;
}