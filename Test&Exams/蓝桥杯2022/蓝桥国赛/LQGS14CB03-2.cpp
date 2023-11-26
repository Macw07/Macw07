#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// 四则运算的优先级：括号，乘除，加减

stack<long> s;
stack<long> temp;

long convert(string str){
    long number = 0, len = str.size();
    for (long i=0; i<len; i++) number = number * 10 + (str[i]-'0');
    return number;
}

inline long multiply(long a, long b){ return a * b; }
inline long divide(long a, long b){ return b / a; }
inline long add(long a, long b){ return a + b; }
inline long subtract(long a, long b){ return b - a; }

void md(){
    while(!s.empty()){
        if (s.top() == '*'){
            s.pop();
            long t_result = multiply(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        } else if (s.top() == '/'){
            s.pop();
            long t_result = divide(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        }
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

void as(){
    while(!s.empty()){
        if (s.top() == '+'){
            s.pop();
            long t_result = add(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        } else if (s.top() == '-'){
            s.pop();
            long t_result = subtract(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        }
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

int main(){
    string str;
    getline(cin, str);
    long len = str.size();
    string t = "";
    for (long i=len-1; i>=0; i--){
        if (str[i] == ' ') continue;
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            reverse(t.begin(), t.end());
            long k = convert(t);
            s.push(k);
            s.push(str[i]);
            t = "";
        } else  t += str[i];
    }
    reverse(t.begin(), t.end());
    s.push(convert(t)); 
    md(); as();
    cout << s.top();
    return 0;
}