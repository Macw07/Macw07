#include <iostream>
#include <algorithm>
using namespace std;

int total, n, m;
int t1[250], t2[250];
int scoreA, scoreB; 

int check(int a, int b){
    if (a == b) return -1;  // 平局
    if (a == 0){
        if (b == 1) return 2;
        if (b == 4) return 2;
        return 1;
    }
    if (a == 1){
        if (b == 2) return 2;
        if (b == 4) return 2;
        return 1;
    }
    if (a == 2){
        if (b == 0) return 2;
        if (b == 3) return 2;
        return 1;
    }
    if (a == 3){
        if (b == 0) return 2;
        if (b == 1) return 2;
        return 1;
    }
    if (a == 4){
        if (b == 2) return 2;
        if (b == 3) return 2;
        return 1;
    }
    return -1;
}

int main(){
    scanf("%d %d %d", &total, &n, &m);
    for (int i=0; i<n; i++){
        scanf("%d", &t1[i]);
    }
    for (int i=0; i<m; i++){
        scanf("%d", &t2[i]);
    }
    for (int i=0; i<total; i++){
        int result = check(t1[i%n], t2[i%m]);
        if (result == 1){
            scoreA += 1;
        } else if (result == 2) scoreB += 1;
    }
    printf("%d %d\n", scoreA, scoreB);
    return 0;
}