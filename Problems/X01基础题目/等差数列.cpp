#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    long long current = 0;
    for (int i=1; i<=n; i++){
        cout << current << " ";
        current += k;
    }
    return 0;
}