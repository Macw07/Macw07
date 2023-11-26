#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int number(int a){
    int count1 = 0;
    if (a <= 0){
        count1++;
    }
    while (a){
        count1++;
        a /= 10;
    }
    return count1;
}

int main(){
    int n, a, b;
    cin >> n;
    string temp, sign;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (temp == "a"){
            cin >> a >> b;
            int len = 2 + number(a) + number(b) + number(a+b);
            printf("%d+%d=%d\n", a, b, a+b);
            printf("%d\n", len);
            sign = temp;
        } else if (temp == "b"){
            cin >> a >> b;
            int len = 2 + number(a) + number(b) + number(a-b);
            printf("%d-%d=%d\n", a, b, a-b);
            printf("%d\n", len);
            sign = temp;
        } else if (temp == "c"){
            cin >> a >> b;
            int len = 2 + number(a) + number(b) + number(a*b);
            printf("%d*%d=%d\n", a, b, a*b);
            printf("%d\n", len);
            sign = temp;
        } else{
            // 字符串转数字
            int n=0;
            cin >> b;
            for (int i=0; i<temp.size(); i++){
                n *= 10;
                n += temp[i]-'0';
            }
            a = n;
            if (sign == "a"){
                int len = 2 + number(a) + number(b) + number(a+b);
                printf("%d+%d=%d\n", a, b, a+b);
                printf("%d\n", len);
            } else if (sign == "b"){
                int len = 2 + number(a) + number(b) + number(a-b);       
                printf("%d-%d=%d\n", a, b, a-b);
                printf("%d\n", len);
            } else if (sign == "c"){
                int len = 2 + number(a) + number(b) + number(a*b);
                printf("%d*%d=%d\n", a, b, a*b);
                printf("%d\n", len);
            }    
        }
    }
    return 0;
}