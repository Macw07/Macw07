#include <iostream>
using namespace std;

int cnt[5];
string arr[5];

bool check(int a, int b){
    if (arr[a] == arr[b]) return false;
    if (arr[a] == "Ro" && arr[b] == "Pa") return false;
    if (arr[a] == "Pa" && arr[b] == "Sc") return false;
    if (arr[a] == "Sc" && arr[b] == "Ro") return false;
    return true;
}

int main(){
    cin >> arr[1] >> arr[2] >> arr[3];
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            if (i == j) continue;
            // i是否能赢j。
            bool win = check(i, j);
            if (win) cnt[i]++;
        }   
    }
    for (int i=1; i<=3; i++){
        if (cnt[i] == 2) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "==" << endl;
    return 0;
}