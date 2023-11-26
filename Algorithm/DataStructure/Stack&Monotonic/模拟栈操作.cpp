#include <iostream>
using namespace std;

int arr[1005] = {};
int head = 0;
void push(int n){
    arr[head] = n;
    head++;
}
void pop(){
    if (head == 0){
        cout << "pop fail\n";
    } else{
        cout << "pop " << arr[head-1] << endl;
        arr[head] = 0;
        head--;
    }
}
void top(){
    if (head == 0){
        cout << "top fail\n";
    } else{
        cout << "top = " << arr[head-1] << endl;
    }
}
void size(){
    cout << "size = " << head << endl;
}
void empty(){
    if (head==0){
        cout << "yes\n";
    } else{
        cout << "no\n";
    }
}

int main(){
    int n, t;
    string op;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> op;
        if (op == "push"){
            cin >> t;
            push(t);
        } else if (op == "top"){
            top();   
        } else if (op == "pop"){
            pop();
        } else if(op == "size"){
            size();
        } else if(op == "empty"){
            empty();
        }
    }
    return 0;
}