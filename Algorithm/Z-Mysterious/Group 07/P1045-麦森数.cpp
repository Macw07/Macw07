#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int p;
int res[1050], f[1050], sav[1050];

void operation1(){
    memset(sav, 0, sizeof sav);
    for (int i=1; i<=500; i++){
        for (int j=1; j<=500; j++){
            sav[i+j-1] += res[i] * f[j];
        }
    }
    for (int i=1; i<=500; i++){
        sav[i+1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(res, sav, sizeof res);
    return ;
}

void operation2(){
    memset(sav, 0, sizeof sav);
    for (int i=1; i<=500; i++){
        for (int j=1; j<=500; j++){
            sav[i+j-1] += f[i] * f[j];
        }
    }
    for (int i=1; i<=500; i++){
        sav[i+1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(f, sav, sizeof f);
    return ;
}

int main(){
    cin >> p;
    printf("%d\n", int(log10(2)*p+1));
    res[1] = 1;
    f[1] = 2;
    // 快速幂模版
    while(p != 0){
        if (p & 1) operation1();
        p >>= 1;
        operation2();
    }
    res[1] -= 1;
    int p = 500;
    for (int i=1; i<=10; i++){
        for (int j=1; j<=50; j++){
            printf("%d", res[p--]);
        }
        printf("\n");
    }
    return 0;
}