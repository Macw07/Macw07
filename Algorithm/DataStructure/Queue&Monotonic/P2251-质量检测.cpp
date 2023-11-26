#include <iostream>
#include <deque>
using namespace std;

int n, m, t;
struct node{
    int value;
    int position;
};
// to maintain a monotonically non-increasing deque.
deque<node> que;

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%d", &t);
        
        if (!que.empty() && que.front().position + m == i) que.pop_front();
        while(!que.empty() && que.back().value > t) que.pop_back();
        que.push_back((node){t, i});
        if (i >= m) printf("%d\n", que.front().value);
    }
    return 0;
}