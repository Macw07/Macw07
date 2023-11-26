#include <iostream>
using namespace std;

long long stack[100005], head;

void push(long long n){
    stack[head++] = n;
}
void pop(){
    if (head-1>=0){
        stack[head--];
    } else{
        cout << 0 << endl;
    }
}
int top(){
    return head;
}
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, t;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        if (t == 0){
            // cout << "入库\n";
            cin >> t;
            push(t);
        } else if (t == 1){
            // cout << "出库\n";
            pop();
        } else if (t == 2){
            // cout << "查询\n";
            int max=0;
            for (int i=0; i<head; i++){
                if (stack[i] > max){
                    max = stack[i];
                }
            }
            cout << max << "\n";
        }
    }
    return 0;
}