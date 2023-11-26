#include <iostream>
using namespace std;

int n, c=0;

void find(int i){
    int k=0;
    while(i){
        k += i % 10;
        if (i % 10 == 7){
            c++;
            return;
        }
        i /= 10;
    }
    if (k == 7) c++;
    return;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        find(i);
    }
    printf("%d", c);
    return 0;
}