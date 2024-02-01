#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 6e7;
char str[MAXN], new_str[(MAXN + 5) << 1];
int R[MAXN], len, ans;
int max_right, mid;

void pre_process(){
    new_str[0] = new_str[1] = '#';
    for (int i=0; i<len; i++){
        new_str[i*2+2] = str[i];
        new_str[i*2+3] = '#';
    }
    len = len * 2 + 2;
}

int main(){
    scanf("%s", str);
    len = strlen(str);
    pre_process();
    
    for (int i=1; i<len; i++){
        if (i < max_right){
            R[i] = min(R[(mid << 1)-i], R[mid]+mid-i);
        } else R[i] = 1;
        while(new_str[i+R[i]] == new_str[i-R[i]]) R[i]++;
        if (R[i] + i > max_right){
            max_right = R[i] + i;
            mid = i;
        }
        ans = max(ans, R[i]);
    }

    printf("%d", ans - 1);
    return 0;
}