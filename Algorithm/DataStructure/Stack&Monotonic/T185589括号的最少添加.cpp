#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] == ')' && s.size() != 0 && s.top() == '('){
            s.pop();
        } else{
            s.push(str[i]);
        }
    }
    cout << s.size();
    return 0;
}