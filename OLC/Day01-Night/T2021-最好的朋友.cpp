#include <iostream>
#include <map>
using namespace std;

int n, k = 1, max_;
string t, arr[5005], ans;
map<string, int> m;

string min(string a, string b){
    if (a > b) return b;
    return a;
}

int main(){
    cin >> n;
    while(n--){
        cin >> t;
        if (m.count(t)) m[t] += 1;
        else {
            m[t] = 1;
            arr[k] = t;
            k += 1;
        }
    }
    for (int i=1; i<k; i++){
        if (m[arr[i]] > max_){
            max_ = m[arr[i]];
            ans = arr[i];
        } if (m[arr[i]] == max_){
            ans = min(arr[i], ans);
        }
    }
    cout << ans << endl;
    return 0;
}