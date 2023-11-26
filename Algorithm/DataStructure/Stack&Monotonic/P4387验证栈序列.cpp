#include <iostream>
#include <stack>
using namespace std;

// 验证栈序列，这道题就是火车进出站的本质，稍微修改一下就可以完成答案了。
// 做完题目了，虽然这道题是一次就AC了，但是写题目的过程中还是参考了之前写的代码。说明自己练习的不够熟练，需要再掌握掌握。
int n;

void stk(){
    int t;
    cin >> t;
    int in[100005], out[100005];
    stack<int> s;
    for (int i=0; i<t; i++) cin >> in[i];
    for (int i=0; i<t; i++) cin >> out[i];
    // 设定双指针，分三种情况讨论
    int p1=0, p2=0;
    while(p2 < t){  // 如果第二个没有到头
        // 当in[p1] == out[p2] 进去直接出来
        if (in[p1] == out[p2]) {p1++; p2++; continue;}
        if (!s.empty() && out[p2] == s.top()) {p2++; s.pop(); continue;}
        if (p1 < t) {s.push(in[p1]); p1++; continue;}
        cout << "No" << endl;
        return;
    }
    cout <<  "Yes" << endl;
    return;
}

int main(){
    cin >> n;
    while(n--){
        stk();
    }
    return 0;
}