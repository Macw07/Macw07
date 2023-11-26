#include <iostream>
using namespace std;

int cnt = 0;

void hanoi(int n, char a, char b, char help){
    // 递归的结束条件：当只有一个圆盘的时候
    if (n == 1){
        printf("%c->%c\n", a, b);
        cnt++;
        return;
    }
    hanoi(n-1, a, help, b);
    printf("%c->%c\n", a, b);
    hanoi(n-1, help, b, a);
    return;
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}