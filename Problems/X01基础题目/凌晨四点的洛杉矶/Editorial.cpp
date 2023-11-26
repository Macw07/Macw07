#include <iostream>
using namespace std;

int n, startH, terminalH;
int startM, terminalM;
int arr[10005][5], total;

bool check(int h, int m){
    // 先比较小时，再比较分钟。
    if (h < startH) return false;
    if (h > terminalH) return false;
    if (h == startH && m < startM) return false;
    if (h == terminalH && m > terminalM) return false;
    return true;
}

int main(){
    // freopen("testcase010.in", "r", stdin);
    // freopen("testcase010.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        int hour, minute;
        scanf("%d:%d", &hour, &minute);
        arr[i][1] = hour;
        arr[i][2] = minute;
    }
    scanf("%d:%d %d:%d", &startH, &startM, &terminalH, &terminalM);
    for (int i=1; i<=n; i++){
        if (check(arr[i][1], arr[i][2])){
            total += 1;
        }
    }
    cout << total << endl;
    return 0;
}