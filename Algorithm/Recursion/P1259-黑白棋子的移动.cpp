#include <iostream>
#include <algorithm>
using namespace std;

int n, space;
char arr[250];

void print(){
    for (int i=0; i<2*n+2; i++) cout << arr[i];
    cout << endl;
    return ;
}

void initial(){
    space = 2*n;
    for (int i=0; i<n; i++) arr[i] = 'o';
    for (int i=n; i<2*n; i++) arr[i] = '*';
    arr[2*n] = arr[2*n+1] = '-';
    print();
    return ;
}

void move(int k){
    k -= 1;
    for (int i=0; i<=1; i++){
        arr[space+i] = arr[k+i];
        arr[k+i] = '-';
    }
    space = k;
    print();
    return ;
}

void recursion(int n){
    if (n == 4) {move(4), move(8), move(2), move(7), move(1);}
    else {move(n); move(2*n-1); recursion(n-1); }
    return ;
}

int main(){
    cin >> n;
    initial();
    recursion(n);
    return 0;
}