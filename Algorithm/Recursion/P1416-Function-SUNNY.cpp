#include <iostream>
using namespace std;

long long w[25][25][25];
long long a, b, c;

int recursion(long long a, long long b, long long c){
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return recursion(20, 20, 20);
    if (w[a][b][c]) return w[a][b][c];

    else if (a < b && b < c){
        w[a][b][c] = recursion(a, b, c-1) + recursion(a, b-1, c-1) - recursion(a, b-1, c);
    }
    else{
        w[a][b][c] = recursion(a-1, b, c) + recursion(a-1, b-1, c) + recursion(a-1, b, c-1) - recursion(a-1, b-1, c-1);
    }
    return w[a][b][c];
}

int main(){
    while (1){
        cin >> a >> b >> c;
        if (a == b && b == c && c == -1) break;
        printf("w(%lld, %lld, %lld) = %d\n" , a, b, c, recursion(a, b, c));
    }
    return 0;
}