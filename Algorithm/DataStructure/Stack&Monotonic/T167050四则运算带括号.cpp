#include <iostream>
#include <stack>
using namespace std;

stack<double> nums;  // double 可以计算小数
stack<char> opt;  // 负责人记录符号（包括括号）

// 1/2+3*9-9*8+6-0*1/8+9-8+(8-2)*6

// 计算符号的优先级：先乘除 再加减
// true代表放入栈中，false代表直接进行运算
bool priority(char now){
    if (!opt.empty() && opt.top() == '(') {
        return true;
    }
    if (now == '+' || now == '-'){  // 加减的优先级是最低的
        if (opt.empty()) return true;
        else return false;
    }
    if (now == '*' || now == '/'){
        if (opt.empty()) return true;
        if (opt.top() == '+' || opt.top() == '-' || opt.top() == '(') return true;
        else return false;
    }
    return false;
}

double calculate(){
    double a = nums.top();
    nums.pop();
    double b = nums.top();
    nums.pop();
    char o = opt.top();
    opt.pop();
    switch(o){
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            nums.push(s[i]-'0');
        } else if(s[i] != '(' && s[i] != ')'){
            bool check = priority(s[i]);
            if (check){
                opt.push(s[i]);
            } else if(!opt.empty() && nums.size()>=2){
                // 直接进行计算
                while(!priority(s[i])) nums.push(calculate());
                opt.push(s[i]);
            }
        } else if (s[i] == '('){
            opt.push(s[i]);
        } else if (s[i] == ')'){
            while(!opt.empty() && opt.top()!='('){
                nums.push(calculate());
            }
            opt.pop();
        }
    }
    while(!opt.empty()){
        nums.push(calculate());
    }
    if (!nums.empty()) printf("%.2f", nums.top());
    return 0;
}