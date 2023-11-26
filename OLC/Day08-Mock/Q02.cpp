#include <iostream>
using namespace std;

int n, arr[10005];
int k, cnt = 0;

int main(){
    freopen("xiaoheizi.in", "r", stdin);
    freopen("xiaoheizi.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> k;
    for (int i=1; i<=n; i++){
        if (arr[i] == k) continue;
        cout << arr[i] << " ";
        cnt++;
    }
    if (cnt == 0) cout << "I love kunkun" << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}