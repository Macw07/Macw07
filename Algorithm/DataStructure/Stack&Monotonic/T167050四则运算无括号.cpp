#include <iostream>
#include <stack>
using namespace std;

// 四则运算的优先级：括号，乘除，加减

stack<string> s;
stack<string> temp;

string multiply(string a, string b){
    int sum1 = 0, sum2 = 0;
    for (int i=0; i<a.size(); i++){
        sum1 = sum1*10 + a[i]-'0';
    }
    for (int i=0; i<b.size(); i++){
        sum2 = sum2*10 + b[i]-'0';
    }
    return to_string(sum1*sum2);
}

string divide(string a, string b){
    int sum1 = 0, sum2 = 0;
    for (int i=0; i<a.size(); i++){
        sum1 = sum1*10 + a[i]-'0';
    }
    for (int i=0; i<b.size(); i++){
        sum2 = sum2*10 + b[i]-'0';
    }
    return to_string(sum2/sum1);
}

string add(string a, string b){
    int sum1 = 0, sum2 = 0;
    for (int i=0; i<a.size(); i++){
        sum1 = sum1*10 + a[i]-'0';
    }
    for (int i=0; i<b.size(); i++){
        sum2 = sum2*10 + b[i]-'0';
    }
    return to_string(sum1+sum2);
}

string subtract(string a, string b){
    int sum1 = 0, sum2 = 0;
    for (int i=0; i<a.size(); i++){
        sum1 = sum1*10 + a[i]-'0';
    }
    for (int i=0; i<b.size(); i++){
        sum2 = sum2*10 + b[i]-'0';
    }
    return to_string(sum2-sum1);
}

void md(){
    while(!s.empty()){
        if (s.top() == "42"){
            s.pop();
            string t_result = multiply(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        } else if (s.top() == "47"){
            s.pop();
            string t_result = divide(s.top(), temp.top());
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
        if (s.top() == "43"){
            s.pop();
            string t_result = add(s.top(), temp.top());
            s.pop();
            temp.pop();
            s.push(t_result);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
        } else if (s.top() == "45"){
            s.pop();
            string t_result = subtract(s.top(), temp.top());
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
    // 先解决正常的加减乘除问题，再解决括号的问题

    // 将所有元素加入到栈中
    string t = "";
    for (int i=str.size()-1; i>=0; i--){
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            reverse(t.begin(), t.end());
            s.push(t);
            s.push(to_string(str[i]));
            t = "";
        } else {
            t += str[i];
        }
    }
    s.push(t);
    md();  // 遍历一边进行乘除运算
    as();  // 遍历一边进行加减运算
    cout << s.top();
    return 0;
}