#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {cin >> arr[i];}

    sort(arr.begin(), arr.end());
    int m = arr[n-1]-arr[0];
    int d = m;

    for (int i=0; i<n-1; i++) {d = gcd(d, arr[i+1]-arr[i]);}

    if (d == 0) {cout << n << endl;}
    else {cout << (m/d) + 1 << endl;}
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int gcd(int a, int b) {
//     return b ? gcd(b, a % b) : a;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> list(n);
//     for (int i = 0; i < n; i++)
//         cin >> list[i];

//     sort(list.begin(), list.end());

//     int md = list[n - 1] - list[0];
//     int d = md;
//     for (int i = 0; i < n - 1; i++)
//         d = gcd(d, list[i + 1] - list[i]);

//     if (d == 0) cout << n << endl;
//     else cout << md / d + 1 << endl;

//     return 0;
// }