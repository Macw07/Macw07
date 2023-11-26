#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    int h=0, m=0, s=0;
    // printf("%d:%d:%d\n", h, m, s);
    while (true){
        if (s==60){
            s = 0;
            m++;
        }
        if (m==60){
            m=0;
            h++;
        }
        printf("%d:%d:%d\n", h, m, s);
        if (h==a && m==b && s==c) {break;}
        s++;
    }
    return 0;
}