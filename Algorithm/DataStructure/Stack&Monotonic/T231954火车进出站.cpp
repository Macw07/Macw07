#include <iostream>
using namespace std;

int stack[1005] = {};
int head=0;
int arr[1000][1000];

void push(int n){
    stack[head++] = n;
    return;
}
void pop(){
    if (head-1>=0) head--;
    return;
}
int top(){
    if (head-1>=0){
        return stack[head-1];
    } else{
        return 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<=m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for (int k=1; k<=m; k++){
        int i=0, j=0, flag=1;
        while(j<n){
            if (arr[0][i] == arr[k][j]){
                push(arr[0][i]);
                pop();
                i++;
                j++;
            } else if(arr[k][j] == top()){
                pop();
                j++;
            } else if(i<n){
                push(arr[0][i]);
                i++;
            } else{
                flag = 0;
                break;
            }
        } 
        head = 0;
        if (flag == 0){
            cout << "No\n";
        } else{
            cout << "Yes\n";
        }
    }
    return 0;
}