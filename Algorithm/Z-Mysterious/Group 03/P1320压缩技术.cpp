#include <iostream>
using namespace std;

bool shift = 0;
int cnt = 0;

int main(){
    string s;
    cin >> s;
    cout << s.size() << " ";
    for (int i=0; i<s.size(); i++){
        if (shift == 0 && s[i] == '1'){
            shift = 1;
            cout << cnt << " ";
            cnt = 0;
        } else if(shift == 1 && s[i] == '0'){
            shift = 0;
            cout << cnt << " ";
            cnt = 0;
        }
        cnt ++;
    }
    while(cin >> s){
        for (int i=0; i<s.size(); i++){
            if (shift == 0 && s[i] == '1'){
                shift = 1;
                cout << cnt << " ";
                cnt = 0;
            } else if(shift == 1 && s[i] == '0'){
                shift = 0;
                cout << cnt << " ";
                cnt = 0;
            }
            cnt ++;
        }
    }
    if (cnt >= 1){
        cout << cnt << " ";
    }
    return 0;
}