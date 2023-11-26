#include <iostream>
using namespace std;

int arr[10005] = {};
int head=0, tail=0;

void push(int n){
    arr[tail] = n;
    tail++;
}

void pop(){
    head++;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if (i==m){
            if (temp==0){
                cout << n;
                return 0;
            }
            push(-temp);
        } else{
            push(temp);
        }
    }
    int times=0;
    for (int i=head; i<tail; i++){
        bool flag = 1;
        for (int j=head; j<tail; j++){
            if (abs(arr[j])>abs(arr[i])){
                flag = 0;
                break;
            }
        }
        if (flag){
            times++;
            // cout << arr[head] << " ";
            if (arr[head] < 0){
                cout << times;
                return 0;
            }
            pop();
        } else{
            push(arr[i]);
            pop();
        }
        
    }
    return 0;
}