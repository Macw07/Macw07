// 给定一个乱序的栈，从大到小输出
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> temp;

int main(){
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        if (!s.empty() && t<s.top()){
            while(!s.empty() && t<s.top()){
                temp.push(s.top());
                s.pop();
            }
            s.push(t);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        } else{
            s.push(t);
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}