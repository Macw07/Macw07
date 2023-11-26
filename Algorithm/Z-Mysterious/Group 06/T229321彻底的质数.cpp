#include <iostream>
using namespace std;

bool prime(long long n){
    if(n==2) return true;
    if(n<=1) return false;
    
    for (int i=2; i*i<=n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long n, t;
    bool flag;
    cin >> n;
    for (int i=0; i<n; i++){
        flag = 1;
        cin >> t;
        if (prime(t)){
            while(t){
                // cout << t%10;
                if (prime(t%10)){
                    // cout << t%10;
                    
                } else{
                    flag = 0;
                    // break;
                }
                t /= 10;
            }
        } else{
            flag = 0;
        }

        if (flag == 1){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}