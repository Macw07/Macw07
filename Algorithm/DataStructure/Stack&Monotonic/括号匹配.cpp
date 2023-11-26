#include <iostream>
using namespace std;

char arr[100] = {};
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
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(str[i]);
        } else{
            char a = top();
            if (a == '(' && str[i] == ')'){
                pop();
                continue;
            } else if (a == '[' && str[i] == ']'){
                pop();
                continue;
            } else if (a == '{' && str[i] == '}'){
                pop();
                continue;
            } else {
                cout << "false";
                return 0;
            }
        }
    }
    if (empty()){
        cout << "true";
    } else{
        cout << "false";
    }
    return 0;
}