#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
set<int> s;
int arr[200005], k[200005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        s.insert(arr[i]);
    }
    if (s.size() == 1){
        cout << -1 << endl;
        return 0;
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) k[++m] = *it;
    cout << max(k[m-2], k[m] % k[m-1]) << endl;
    return 0;
}