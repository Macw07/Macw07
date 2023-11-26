#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, p=0, pre=-1, temp=1;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        if (t == pre){
            temp++;
        } else{
            pre = t;
            p = max(p, temp);
            temp = 1;
        }
    }
    cout << p << endl;
    return 0;
}