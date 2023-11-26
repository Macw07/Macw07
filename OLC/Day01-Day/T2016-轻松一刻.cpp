#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int total;
int h1, m1, s1;
int h2, m2, s2;

int main(){
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    while(!(h1 == h2 && m1 == m2 && s1 == s2)){
        printf("%02d:%02d:%02d\n",h1, m1, s1);
        total += 1;
        s1 += 1;
        if (s1 == 60){
            s1 = 0;
            m1 += 1;
        }
        if (m1 == 60){
            m1 = 0;
            h1 += 1;
        }
        if (h1 == 24){
            h1 = 0;
            printf("next day\n");
        }
    }
    printf("%02d:%02d:%02d\n",h2, m2, s2);
    printf("total=%d\n", total);
    return 0;
}