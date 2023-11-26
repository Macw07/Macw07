#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*
题解链接：https://www.luogu.com.cn/blog/issue-s/solution-p3612
这道题不难，有很多种做的方法，虽然推荐的做法是递归，但是我还是选择了循环。
主要思路：不要通过正序模拟的方法去求，应该要倒着推：去推断这个数是由哪一段变换过来的。
*/

ll n, num, i;
string str;

int main(){
    cin >> str >> n;
    num = str.length();
    while(num < n){
        i = num;
        while(n > i) i *= 2;
        i /= 2;
        n -= (i+1);
        if (n == 0) n = i;
    }
    cout << str[n-1];
    return 0;
}