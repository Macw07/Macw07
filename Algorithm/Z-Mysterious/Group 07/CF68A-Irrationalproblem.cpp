#include <iostream>
using namespace std;

int cnt = 0;
int p1, p2, p3, p4, n, m;

int main(){
    cin >> p1 >> p2 >> p3 >> p4 >> n >> m;
    for (int i=n; i<=m; i++){
        if (i%p1==i && i%p2==i && i%p3==i && i%p4==i) cnt++;
    }
    cout << cnt << endl;
    return 0;
}