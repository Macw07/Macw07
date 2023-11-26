#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> students;
int ans, n, m;
int sink[2][105];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        students.push(t);
    }
    while(students.size()){
        for(int i=1; i<=m; i++){
            if (sink[0][i] == 0){
                if (students.size()){
                    int t = students.front();
                    students.pop();
                    sink[0][i] = t;
                    sink[1][i] += t;
                    ans = max(ans, sink[1][i]);
                } else break;
            }
            sink[0][i] -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}