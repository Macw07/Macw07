#include <iostream>
using namespace std;

void hannoi(int n, char A, char B, char C){
    if (n==1){
        // 把圆盘移到C
        printf("%c->%c\n", A, C);
        return;
    }
    // 把上面的圆盘从A通过C移到B
    hannoi(n-1, A, C, B);
    printf("%c->%c\n", A, C);
    // 把上面的圆盘从B通过A移到C
    hannoi(n-1, B, A, C);
}
int main(){
    int n;
    cin >> n;
    hannoi(n, 'A', 'B', 'C');
    return 0;
}