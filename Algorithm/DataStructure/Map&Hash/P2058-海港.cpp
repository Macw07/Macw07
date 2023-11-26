#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n, total;
map<int, int> roll;

struct memo{
    int time;
    int number;
};
queue<memo> que;

int main(){
    cin >> n;
    while(n--){
        int t, k;
        cin >> t >> k;
        while(k--){
            int m;
            cin >> m;
            que.push((memo){t, m});
            if (roll[m] == 0) {
                roll[m] = 1;
                total += 1;
            }
            else roll[m] += 1;
        }
        while(!que.empty()){
            memo tmp = que.front();
            if (t - tmp.time >= 86400){
                que.pop();
                roll[tmp.number] -= 1;
                if (roll[tmp.number] == 0) total -= 1;
            } else break;
        }
        cout << total << endl;
    }
    return 0;
}