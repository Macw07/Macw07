#include <iostream>
using namespace std;

int dict(int n, int now){
    if (now == n){
        printf("{");
        for (int i=0; i<n; i++){
            printf("}");
        }
        return 0;
    }
    printf("{%d: ", now);
    dict(n, now+1);
    return 0;
}

int main(){
    int n;
    cin >> n;
    dict(n, 1);
    return 0;
}