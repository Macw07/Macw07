#include <iostream>
#include <algorithm>
using namespace std;

int n, male[5005], female[5005];
int mx, fx;

int main(){
    // freopen("testcase001.in", "r", stdin);
    // freopen("testcase001.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        int g, h;
        cin >> g >> h;
        if (g == 1) male[++mx] = h;
        else female[++fx] = h;
    }
    sort(male+1, male+mx+1);
    sort(female+1, female+fx+1, greater<int>());
    for (int i=1; i<=mx; i++) cout << male[i] << " ";
    for (int j=1; j<=fx; j++) cout << female[j] << " ";
    return 0;
}