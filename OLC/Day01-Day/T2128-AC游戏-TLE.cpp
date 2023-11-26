#include <iostream>
#include <algorithm>
using namespace std;

bool nflag = 0;
long long t, q;

void dfs(long long number, int round, long long init){
    if (nflag) return ;
    bool flag = 0;
    for (int i=2; i<number; i++){
        if (number % i == 0){
            flag = 1;
            dfs(i, round ^= 1, init);
        }
    }
    if (flag == 0 && round == 0) nflag = 1;
    return ;
}

int main(){
    cin >> t;
    while(t--){
        cin >> q;
        bool pflag = 0;
        for (long long i=2; i<q; i++){
            if (q % i == 0){
                dfs(i, 1, i);
                pflag = 1;
                if (nflag){
                    cout << 1 << endl << i << endl;
                    break;
                }
            }   
        }
        if (!pflag) cout << 0 << endl;
        else if (!nflag) cout << 2 << endl;
        nflag = 0;
    }
    return 0;
}