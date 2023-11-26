#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_ = 1e7+5;

int ans = 0;
int n, m;
int vis[MAX_], arr[MAX_], ptr;

void Euler(){
    vis[1] = vis[0] = 1;
    for (int i=2; i<=MAX_; i++){
        if (!vis[i]) {
            if (i > m) return ;  
            arr[ptr++] = i;
        }
        for (int j=0; j<ptr&&arr[j]*i<=MAX_; j++){
            vis[arr[j]*i] = 1;
            if (arr[j]*i > m) break;  
            if (i % arr[j] == 0) break;  
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    m = min(1000000, m);
    Euler();
    for (int i=n; i<=m; i++){
        int temp = 0, cnt = 2;
        int number = i;
        while(number != 1){
            if (number % cnt == 0 && vis[cnt] == 0){
                number /= cnt;
                temp += 1;
            } else cnt += 1;
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}