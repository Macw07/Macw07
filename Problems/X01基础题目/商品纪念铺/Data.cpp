#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

int main(){
    // freopen("testcase012.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 5500 + 10;
    int k = rand() % 250 + 1;
    cout << n << " " << k << endl;

    for (int i=1; i<=n; i++){
        int t = rand() % 1000;
        cout << t << " ";
    }
    cout << endl;

    while(k--){
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        int t = rand() % (n-1) + 1;
        set<int> s;
        for (int i=1; i<=t; i++){
            int ti = rand() % (n-1) + 1;
            s.insert(ti);
        }
        n -= s.size();
        cout << s.size() << endl;
        for (set<int>::iterator it=s.begin(); it!=s.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}