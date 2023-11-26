#include <iostream>
using namespace std;

int n, m, t = 1;
int prefix[1000005];
int number[1000005];
int prime[1000005];

bool find_prime(int k){
    for (int i=2; i*i<=k; i++){
        if (k % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin >> n >> m;
    prefix[2] = 1;

    for (int i=3; i<=m; i++){
        prefix[i] = prefix[i-1] + find_prime(i);
    }

    while(n--){
        int l, r;
        cin >> l >> r;
        if (l >= 1 && r <= m){
            cout << prefix[r] - prefix[l-1] << endl;
        } else{
            cout << "Crossing the line" << endl;
        }
    }
    return 0;
}