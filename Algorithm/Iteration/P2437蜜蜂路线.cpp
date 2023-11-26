#include <iostream>
#include <algorithm>
using namespace std;

string arr[3][10000] = {};

string add(string a, string b){
    string s;
    int c=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0, j=0; i<a.size() || j<b.size() || c!=0; ){
        if (i < a.size()) c += a[i++]-'0';
        if (j < b.size()) c += b[j++]-'0';
        s += c%10+'0';
        c /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    int begin, n, m=1, k=1;
    cin >> begin >> n;
    n -= begin-1;
    
    arr[0][0] = "1";
    arr[1][0] = "1"; 
    for (int i=3; i<n+3; i++){
        if (i % 2 == 1){
            arr[0][m] = add(arr[1][m-1], arr[0][m-1]);
            // cout << arr[0][m] << endl;
            m++;
        } else{
            arr[1][k] = add(arr[1][k-1], arr[0][k]);
            k++;
        }
    }
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<=n/2; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (n % 2 == 0){
        cout << arr[1][n/2-1];
    } else{
        cout << arr[0][n/2];
    }
    return 0;
}