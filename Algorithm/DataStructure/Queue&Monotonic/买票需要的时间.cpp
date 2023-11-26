#include <iostream>
using namespace std;

int arr[100005] = {};
int head=0, tail=0;
void push(int n){
    arr[tail] = n;
    tail++;
}
void pop(){
    arr[head] = 0;
    head++;
}

int main(){
    int n, k, t, count=0;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> t;
        if (i==k){
            push(-t);
        } else{
            push(t);
        }
    }
    for (int i=head; i<=tail; i++){
        if (arr[head]>0){
            count++;
            arr[head]--;
            push(arr[head]);
            pop();
        }
        if (arr[head]==0){
            pop();
        }
        if (arr[head]<-1){
            count++;
            arr[head]++;
            push(arr[head]);
            pop();
        }
        if (arr[head]==-1){
            count++;
            cout << count;
            return 0;
        }
    }
    return 0;
}