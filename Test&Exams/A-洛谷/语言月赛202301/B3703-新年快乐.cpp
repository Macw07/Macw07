#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string s;
int n, sbegin, send;

string previous(string stripped){
    int cnt = 0;
    string copy = stripped;
    reverse(stripped.begin(), stripped.end());
    int len = stripped.size();
    for (int i=0; i<len; i++){
        if (stripped[i] - 1 >= 'a'){
            stripped[i] -= 1;
            break;
        } else {
            cnt += 1;
            stripped[i] = 'z';
        }
    }
    if (cnt == len) return copy;
    reverse(stripped.begin(), stripped.end());
    return stripped;
}

int main(){
    cin >> s >> n;
    while(n--){
        cin >> sbegin >> send;
        string stripped = s.substr(sbegin-1, send-sbegin+1);
        string pre = previous(stripped);
        if (stripped == pre) {
            cout << "NULL" << endl;
            cout << "Happy Chinese New Year!" << endl;
            continue;
        }
        else cout << pre << endl;
        int index = s.find(pre);
        // cout << s.find(pre) << endl;
        if (index >= 0 && index < s.size()) cout << "Happy New Year!" << endl;
        else cout << "Happy Chinese New Year!" << endl;
    }
    return 0;
}