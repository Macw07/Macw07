#include <iostream>
#include <deque>
using namespace std;

int n, m, t, cnt;
struct node{
    int value;
    int position;
};
deque<node> que;

// To construct a monotonically non-increasing deque.
int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &t);
        if (!que.empty()) printf("%d\n", que.front().value);
        else printf("0\n");

        if (que.size() && que.front().position + m == i) que.pop_front();

        while(!que.empty() && que.back().value > t) que.pop_back();
        que.push_back((node){t, i});
    }
    return 0;
}