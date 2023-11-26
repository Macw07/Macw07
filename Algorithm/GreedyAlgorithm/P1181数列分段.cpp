#include <iostream>
using namespace std;

int main(){
    long long n, m, t=0, t1=0, c=0;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t1;
        if (t + t1 > m){
            // cout << t1 << " ";
            t = t1;
            c++;
        } else{
            t += t1;
        }
    }  
    if (t) c++;
    cout << c;
    return 0;
}