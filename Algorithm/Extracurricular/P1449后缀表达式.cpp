#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<int> stk;

// 字符串转数字
int convert(string s){
    int n = 0, len=s.size();
    for (int i=0; i<len; i++){
        n = n*10 + s[i]-'0';
    }
    return n;
}

int main(){
    string s;
    getline(cin, s);
    int len = s.size(), k=0;
    string arr[55];
    for (int i=0; i<len; i++){
        if (s[i] == '@') {
            cout << stk.top() << endl;
            break;
        }
        if (s[i] >= '0' && s[i] <= '9'){
            arr[k] += s[i];
        } else if(s[i] == '.'){
            stk.push(convert(arr[k]));
            // cout << arr[k] << " ";
            k++;
        } else{
            int a, b;
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            if (s[i] == '+'){
                stk.push(b + a);
            } else if (s[i] == '-'){
                stk.push(b - a);
            } else if (s[i] == '*'){
                stk.push(b * a);
            } else if (s[i] == '/'){
                stk.push(b / a);
            } else{
                break;
            }
        }
    }
    return 0;
}