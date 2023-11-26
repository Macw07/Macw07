#include <iostream>
#include <algorithm>
using namespace std;

int ans, n;
string str;

int main(){
    cin >> n;
    cin >> str;
    for (int i=0; i<str.size()-1; i++){
        if (str[i] == 'V' && str[i+1] == 'K'){
            ans += 1;
            str[i] = '/';
            str[i+1] = '/';
        }
    }
    for (int i=0; i<str.size(); i++){
        if (str[i] != '/' && str[i] == str[i+1]) {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}