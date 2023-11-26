#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int s[1000000];
int v[1000000];

int main(){
    int m, n;
    cin >> m >> n;
    for (int i=0; i<m; i++){
        cin >> s[i];
    }
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    // 从低到高排序学校的分数
    sort(s, s+m);
    // 从学生人群中依次选择并判断
    long long total = 0;
    for (int i=0; i<n; i++){
        int l=-1, r=m;
        while(l+1 != r){
            int m = (l+r)/2;
            if (s[m] <= v[i]){
                l = m;
            } else{
                r = m;
            }
        }
        if (l == -1){
            total += abs(s[r]-v[i]);
            continue;
        }
        if (r == m){
            total += abs(s[l]-v[i]);
            continue;
        }
        total += min(abs(s[l]-v[i]), abs(s[r]-v[i]));
    }
    cout << total;
    return 0;
}