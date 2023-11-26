#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int k = 1, max_;
int t, arr[100005], ans;
map<int, int> m;

int main(){
    while(cin >> t){
        if (m.count(t)) m[t] += 1;
        else {
            m[t] = 1;
            arr[k] = t;
            k += 1;
        }
    }
    sort(arr+1, arr+k);
    for (int i=1; i<k; i++){
        cout << arr[i] << ":" << m[arr[i]] << endl;
    }
    return 0;
}