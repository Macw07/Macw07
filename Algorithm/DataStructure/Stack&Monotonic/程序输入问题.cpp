#include <iostream>
#include <cstdio>
using namespace std;

char arr[105] = {};
int head=0;
void push(char n){
    arr[head] = n;
    head++;
}
void pop(){
    head--;
    // arr[head] = 0;
}

int main(){
    string str;
    getline(cin, str);
    for (int i=0; i<str.size(); i++){
        if (str[i] == '@'){
            head=0;
        } else if (head != 0 && str[i] == '#'){
            pop();
        } else if (str[i] != '#' && str[i] != '@') {
            push(str[i]);
        }
    }
    for (int i=0; i<head; i++){
        cout << arr[i];
    }
    return 0;
}