#include <iostream>
#include <algorithm>
using namespace std;

long long arr[35] = {0, 1}, last = 1;

void calculate(int t){
    for(int i=last+1; i<=t+1; i++, last++){
        arr[i] = (arr[i-1]+1)*2;
    }
    cout << arr[t+1] << endl;
    return ;    
}

int main(){
    int n, t;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        if (arr[t]) cout << arr[t] << endl;
        else calculate(t);
    }
    return 0;
}
