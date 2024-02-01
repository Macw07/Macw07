#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000005;
int T, R[MAXN << 1], len;
int vis[MAXN << 1];
char ns[MAXN << 1];

void process(){
    int cnt = 0;
    char ch = getchar ();
	ns[0] = '~', ns[cnt = 1] = '#';
	while (ch < 'a' or ch > 'z') ch = getchar ();
	while (ch >= 'a' and ch <= 'z') ns[++cnt] = ch, ns[++cnt] = '#', ch = getchar (); 
    ns[cnt + 1] = '%';
    len = cnt;
}

void manacher(){
    int max_right = 0, mid;
    for (int i=1; i<=len; i++){
        if (i <= max_right){
            R[i] = min(R[(mid << 1) - i], max_right - i);
        } else R[i] = 1;
        while (ns[i + R[i]] == ns[i - R[i]]) R[i]++;
        if (R[i] + i > max_right){
            mid = i;
            max_right = R[i] + i - 1;
        }
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(vis, 0, sizeof vis);
        process();
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