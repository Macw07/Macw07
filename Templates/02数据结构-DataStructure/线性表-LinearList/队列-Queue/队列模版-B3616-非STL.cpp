#include <iostream>
using namespace std;

int arr[10005] = {};
int head=0, tail=0;

void push(int n){
    arr[tail] = n;
    tail++; 
}
void pop(){
    if (head-tail==0){
        printf("ERR_CANNOT_POP\n");
        return;
    }
    arr[head] = 0;
    head++;
}
void query(){
    if (head-tail==0){
        printf("ERR_CANNOT_QUERY\n");
        return;
    }
    printf("%d\n", arr[head]);
}

void size(){
    printf("%d\n", tail-head);
}
int main(){
    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        int t;
        cin >> t;
        if (t==1){
            int temp;
            cin >> temp;
            push(temp);
        } else if(t==2)  pop();
        else if(t==3) query();
        else size();
    }
    return 0;
}