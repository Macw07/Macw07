#include <iostream>
#include <algorithm>
using namespace std;

char arr[10005];
bool vis[10005];
int dxy[] = {-1, 1, -2, 2, -3, 3};
string s1, s2;
int len;
int ans = 0x7f7f7f7f;

bool check(){
    for (int i=0; i<len; i++){
        if (arr[i] != s2[i]) return false;
    }
    return true;
}

void rec(int cond){
    if (check()){
        ans = min(ans, cond);
        return;
    }
    // 重复进行三种类型的行为
    for (int i=0; i<len; i++){
        for (int j=0; j<6; j++){
            int cxy = i + dxy[j];
            if (cxy >= 1 && !vis[cxy] && arr[cxy] == '*') {
                vis[cxy] = 1;
                swap(arr[i], arr[cxy]);
                rec(cond+1); 
                swap(arr[i], arr[cxy]);
                vis[cxy] = 0;
            }
        }
    }
    return;
}

int main(){
    cin >> s1 >> s2;
    len = s1.size();
    for (int i=0; i<len; i++){
        arr[i] = s1[i];
    }
    rec(0);
    cout << ans << endl;
    return 0;
}