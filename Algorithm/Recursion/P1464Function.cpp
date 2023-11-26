#include <iostream>
using namespace std;

long long nodes[30][30][30] = {};

long long w(long long a, long long b, long long c){
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    // 记忆化搜索,搜索是否被查找过
    if (nodes[a][b][c] != 0){  // 查找过
        return nodes[a][b][c];
    }
    else if (a > 20 || b > 20 || c > 20){;
        nodes[a][b][c] = w(20, 20, 20);
    }
    else if (a < b && b < c){
        nodes[a][b][c] = w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
    }
    else{
        nodes[a][b][c] =  w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
    }
    return nodes[a][b][c];
}

int main(){
    int a, b, c;
    while (cin >> a >> b >> c){
        if (a != -1 || b != -1 || c != -1){
            printf("w(%d, %d, %d) = ", a, b, c);
            if (a > 20) a = 21;
            if (b > 20) b = 21;
            if (c > 20) c = 21;
            printf("%lld\n", w(a, b, c));
        } else{
            break;
        }
    } 
    return 0;
}