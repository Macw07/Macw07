#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    int candies;
};

queue<stu> q;

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        stu s = {i, t};
        q.push(s);
    }
    int total=0;
    stu cur;
    while(!q.empty()){
        cur = q.front();
        if (cur.candies>0){
            total += k;
            q.pop();
            if(cur.candies>k){
                cur.candies -= k;
                q.push(cur);
            }
        }
    }
    cout << cur.id << " " << total << endl;
    return 0;
}