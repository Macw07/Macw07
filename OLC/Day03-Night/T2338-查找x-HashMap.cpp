#include <iostream>
#include <map>
using namespace std;

int n, arr[105], k;
map<int, int> m;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        m[arr[i]] = i;
    }
    scanf("%d", &k);
    if (m.count(k)) cout << m[k] << endl;
    else cout << -1 << endl;
    return 0;
}