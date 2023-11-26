#include <iostream>
#include <cmath>
using namespace std;

int n, m, p;

int check(int mid, int t){
    int product=0, i = 0;
    while(t){
        if (t % 10 >= mid) return 0;
        product += (t%10) * pow(mid, i);
        i++;
        t /= 10;
    }
    return product;
}

int main(){
    cin >> n >> m >> p;
    for (int i=2; i<=40; i++){
        int pp = check(i, p);
        if (pp && check(i, n)*check(i, m) == pp){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}