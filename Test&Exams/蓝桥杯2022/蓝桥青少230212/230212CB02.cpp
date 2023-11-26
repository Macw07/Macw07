#include <iostream>
using namespace std;

int cnt = 0;
int n, m;

bool check(int k){
    while(k){
        if (k % 10 % 2 == 0) return false;
        k /= 10;
    }
    return true;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=n; i<=m; i++){
        if (check(i)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}