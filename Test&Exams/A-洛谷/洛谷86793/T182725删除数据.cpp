#include <iostream>
using namespace std;

int main(){
    int n, k, t;
    bool f = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> t;
        if (t == k && !f){
            f = 1;
            continue;
        }
        printf("%d ", t);
    }
    return 0;
}