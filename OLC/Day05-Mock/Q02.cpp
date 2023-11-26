#include <iostream>
#include <algorithm>
using namespace std;

int a1, a2, a3, a4, l, r, total = 0;

int main(){
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    cin >> a1 >> a2 >> a3 >> a4 >> l >> r;
    for (int i=l; i<=r; i++){
        int tmp = i;
        if (tmp % a1 % a2 % a3 % a4 == tmp){
            total += 1;
        }
    }
    cout << total << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}