#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > que;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        que.push(t);
    }
    long long sum = 0;
    int a, b;
    for (int i=0; i<n-1; i++){
        a = que.top();
        que.pop();
        b = que.top();
        que.pop();
        sum += a+b;
        que.push(a+b);
    }
    cout << sum;
    return 0;
}