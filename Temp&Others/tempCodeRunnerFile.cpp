#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 5;
int T, R[MAXN << 1], len;
int vis[MAXN << 1];
char ns[MAXN << 1], str[MAXN];

void process(){
    len = strlen(str);
    ns[1] = '#';
    ns[0] = '%';
    for (int i=0; i<len; i++){
        ns[(i << 1) + 2] = str[i];
        ns[(i << 1) + 3] = '#';
    }
    len = (len << 1) + 2;
    ns[len] = '$';
}

void manacher(){
    int max_right = 0, mid, res = 1;
    for (int i=1; i<=len; i++){
        if (i < max_right){
            R[i] = min(R[(mid << 1) - i], R[max_right - i]);
        } else R[i] = 1;
        while (ns[i + R[i]] == ns[i - R[i]]) R[i]++;
        if (R[i] + i> max_right){
            mid = i;
            max_right = R[i] + i - 1;
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(vis, 0, sizeof vis);
        scanf("%s", str);
        process();
        len -= 1;
        // Find longest palindrome string
        manacher();
        for (int i=len; i>=1; i--){
            // Success
            if (i + R[i] - 1 == len) vis[i] = 1;
            else if (vis[i + R[i] - 2] && i == R[i]) vis[i] = 1;
        }
        for (int i=1; i<=len; i++){
            if (vis[i] && (ns[i] >= 'a' && ns[i] <= 'z')){
                printf("%d ", (i >> 1));
            }
        }
        printf("\n");
    }
    return 0;
}