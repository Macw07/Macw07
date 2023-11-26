#include <iostream>
using namespace std;

int n;

void hanoi(int remain, char a, char b, char help){
    if (remain == 1){
        printf("%c --%d--> %c\n", a, remain, b);
        return ;
    }
    hanoi(remain-1, a, help, b);
    printf("%c --%d--> %c\n", a, remain, b);
    hanoi(remain-1, help, b, a);
    return ;
}

int main(){
    cin >> n;
    // 从A盘子移到C盘子，经过B盘子。
    hanoi(n, 'A', 'C', 'B');
    return 0;
}