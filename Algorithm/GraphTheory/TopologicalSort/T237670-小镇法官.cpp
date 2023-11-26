#include <iostream>
#include <algorithm>
using namespace std;

int n, e;
int inDegree[1005], outDegree[1005];

int main(){
    cin >> n >> e;
    for (int i=1; i<=e; i++){
        int a, b;
        cin >> a >> b;
        inDegree[b] += 1;
        outDegree[a] += 1;
    }
    for (int i=1; i<=n; i++){
        if (inDegree[i] == n-1 && outDegree[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}