#include <iostream>
using namespace std;

int arr[1005] = {};
int head=0;

void push(int n){
    arr[head] = n;
    head++;
}
void pop(){
    arr[head] = 0;
    head--;
}

int main(){
    int n, t;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        push(t);
    }
    for (int i=n; i>0; i--){
        pop();
        cout << arr[head] << " ";
    }
    return 0;
}