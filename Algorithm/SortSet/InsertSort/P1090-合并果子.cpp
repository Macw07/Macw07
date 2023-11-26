#include <iostream>
#include <algorithm>
using namespace std;

int head = 0;
int tail = 0;
int n, arr[100005];
long long sum;

void insert(int k){ 
    int i;
    for (i=tail-1; i>=head; i--){
        if (arr[i] > k){
            arr[i+1] = arr[i];
        } else break;
    }
    arr[++i] = k;
    tail++;
    return ;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int t;
        scanf("%d", &t);
        insert(t);  
    }
    while(tail - head - 1){
        int first = arr[head++];
        int second = arr[head++];
        sum += (first + second);
        insert(first + second);
    }
    cout << sum << endl;
    return 0;
}