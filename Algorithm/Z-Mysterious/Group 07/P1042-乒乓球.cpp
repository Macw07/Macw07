#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100005];  // 记录每一次对局的成绩
int t1, t2, len;  // 两个人的最终成绩。

void show(int k){
    t1 = 0, t2 = 0;
    for (int i=1; i<=len; i++){
        if (arr[i] == 1){
            t1++;
        } else{
            t2++;
        }
        if ((t1 >= k || t2 >= k) && abs(t1-t2) >= 2){
            printf("%d:%d\n", t1, t2);
            t1 = 0;
            t2 = 0;
        }
    }   
    printf("%d:%d\n", t1, t2);
}
int main(){
    char win;
    for (len=1; cin >> win && win != 'E'; len++){
        if (win == 'W'){
            arr[len] = 1;
        } else{
            arr[len] = 2;
        }
    }
    len -= 1;
    show(11);
    printf("\n");
    show(21);
    return 0;
}