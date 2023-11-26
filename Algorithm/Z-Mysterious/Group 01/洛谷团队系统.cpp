#include <iostream>
using namespace std;

int main(){
    int n, local, luogu;
    cin >> n;
    local = n*5;
    luogu = n*3+11;
    if (local<=luogu){
        printf("Local");
    } else{
        printf("Luogu");
    }
    return 0;
}