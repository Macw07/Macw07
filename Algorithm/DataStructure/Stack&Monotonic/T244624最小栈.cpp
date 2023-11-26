#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> s;
stack<int> m;

int main(){
    int n;
    string str;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str;
        if (str == "top"){
            if (!s.empty()){
                cout << s.top() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (str == "push"){
            int n;
            cin >> n;
            s.push(n);
            if (!m.empty()){
                m.push(min(m.top(), n));
            } else{
                m.push(n);
            }
        } else if (str == "pop"){
            if (!s.empty()){
                s.pop();
                m.pop();
            } else {
                cout << "error" << endl;
            }
        } else if (str == "get_min"){
            if (!m.empty()){
                cout << m.top() << endl;
            } else {
                cout << "error" << endl;
            }
        } else{
            cout << "error" << endl;
        }
    }
    return 0;
}