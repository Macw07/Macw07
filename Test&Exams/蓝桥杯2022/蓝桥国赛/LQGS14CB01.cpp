#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 31622
int n;
string str;

long long convert(long long number){
    long long nums = 0;
    str = "";
    while(number){
        str += ((number % 8) + '0');
        nums = nums * 10 + (number % 8);
        number /= 8;
    }
    string temp = str;
    reverse(str.begin(), str.end());
    if (str != temp) return -1;
    return nums;
}

int main(){
    scanf("%d", &n);
    for (int i=1; i * i<=n; i += 1){
        if (ceil(sqrt(i*i)) != floor(sqrt(i*i))) continue;
        long long k = convert(i*i);
        if (k == -1) continue;
        
        printf("%d ", i*i);
    }
    return 0;
}