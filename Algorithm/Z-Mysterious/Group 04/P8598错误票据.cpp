#include <iostream>
#include <algorithm>
using namespace std;

int arr[100050];
int minimum = 0x7f7f7f7f;
int maximum = 0;
int ans1, ans2;

int main(){
    int n;
    cin >> n;
    int t;
    while(cin>>t){
        arr[t]++;
        maximum = max(maximum, t);
        minimum = min(minimum, t);
    }
    for (int i=minimum; i<=maximum; i++){
        if (ans1 && ans2) break;
        if (arr[i] == 0) ans1 = i;
        else if (arr[i] > 1) ans2 = i;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}