#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1e6 + 5;
struct node{
    int height;
    int energy;
};
int n, h, v, ans;
node arr[N];
int receieve[N];
stack<int> left_; 
stack<int> right_;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d %d", &h, &v);
        arr[i] = (node){h, v};

        while(!left_.empty() && arr[left_.top()].height <= h) left_.pop();
        if (!left_.empty()) receieve[left_.top()] += v;
        left_.push(i);
    }

    for (int i=n; i>=1; i--){
        while(!right_.empty() && arr[right_.top()].height <= arr[i].height) right_.pop();
        if (!right_.empty()) receieve[right_.top()] += arr[i].energy;
        right_.push(i);
    }

    for (int i=1; i<=n; i++) ans = max(ans, receieve[i]);
    cout << ans << endl;
    return 0;
}