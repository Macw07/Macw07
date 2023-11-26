#include <iostream>
using namespace std;

int inout[10005] = {};
int inout_head=0;

char stack[10005] = {};
int stack_head=0;

void push(char n){
    stack[stack_head++] = n;
    inout[inout_head++] = 1;
}
void pop(){
    stack_head--;
    inout[inout_head++] = 0;
}
char top(){
    if(stack_head-1>=0){
        return stack[stack_head-1];
    }
}

int main(){
    int n, i=0, j=0;
    string str1, str2;
    cin >> n >> str1 >> str2;
    while(j<n){
        // 如果一样就入栈再出栈
        if (str1[i] == str2[j]){
            push(str1[i]);
            pop();
            i++;
            j++;
        } 
        // 如果不一样判断是否和栈顶相同
        else if(str2[j] == top()){
            // 出栈
            pop();
            // i++; // 长记性：出栈了，i不需要++，否则会出事！
            j++;
            // cout << "出栈了";
        }
        // 如果i<n就可以入栈
        else if(i<n) {
            push(str1[i]);
            i++;
        }
        // 否则火车无法出栈
        else{
            cout << "NO\n";
            cout << "FINISH";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i=0; i<2*n; i++){
        if (inout[i]==1) cout << "in\n";
        else cout << "out\n";
    }
    cout << "FINISH\n";
    return 0;
}