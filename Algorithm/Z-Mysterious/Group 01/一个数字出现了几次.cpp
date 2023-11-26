#include <iostream>
using namespace std;

int main(){
    int n, m, t, count=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        t = i;
        while (t){
            if (t%10 == m){
                count++;
            }
            t /= 10;
        }
    }
    cout << count;
    return 0;
}