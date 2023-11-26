// 表达式括号匹配
#include <iostream>
using namespace std;

char arr[500] = {};
int head = 0;

void push(char n){
    arr[head] = n;
    head++;
}
char top(){
    return arr[head-1];
}
bool empty(){
    if (head==0){
        return true;
    } else{
        return false;
    }
}
void pop(){
    arr[head] = 0;
    head--;
}

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] == ')' && empty()){
            cout << "NO";
            return 0;
        }
        if (str[i] == '('){
            push(str[i]);
        } else{
            if (str[i] != ')') continue;
            char a = top();
            if (a == '(' && str[i] == ')'){
                pop();
                continue;
            } else {
                cout << "YES";
                return 0;
            }
        }
    }
    if (empty()){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}