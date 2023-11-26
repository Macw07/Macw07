#include <iostream>
#include <cmath>
using namespace std;

int sys, n, ans=0;

int convert(int a){
    int sum = 0;
    while(a){
        sum = sum*10 + a%sys;
        a /= sys;
    }
    return sum;
}

int convert_back(int a){
    int i=0;
    int sum=0;
    while(a){
        sum += (a%10)*pow(sys, i);
        i++;
        a /= 10;
    }
    return sum;
}

// 将数字转换为10进制相加并转换会sys进制
int add(int a, int b){
    int c = convert_back(a), d = convert_back(b);
    return convert(c+d); 
}   


// 反转数字
int check(int n){
    // 将数字反过来
    int t = n, sum=0;
    while(t){
        sum = sum*10 + t%10;
        t /= 10;
    }
    return sum;
}

int main(){
    cin >> sys >> n;
    int temp = n;
    while(check(temp) != temp){
        temp = add(temp, check(temp));
        ans++;
        if (ans > 30) break;
    }
    if (ans <= 30){
        printf("STEP=%d\n", ans);
    } else{
        printf("IMPOSSIBLE\n");
    }
    return 0;
}