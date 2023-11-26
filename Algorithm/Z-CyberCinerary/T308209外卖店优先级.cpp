#include <iostream>
#include <algorithm>
using namespace std;

struct node{int tx, id;};
int n, m, t;
node arr[1000005];
int result[10000005];
bool priority[10000005];

bool cmp(node a, node b){
    if (a.tx != b.tx) return a.tx < b.tx;
    return a.id < b.id;
}
int main(){
    cin >> n >> m >> t;
    for (int i=0; i<m; i++){
        cin >> arr[i].tx >> arr[i].id;
    }
    sort(arr, arr+m, cmp);

    int current = 0;
    for (int i=1; i<=t; i++){
        int vendor = 1;
        bool check = false;
        for (int j=current; j<m; j++){
            if (arr[j].id == vendor) {
                for (int k=0; ; k++){
                    if (arr[j+k].id == vendor && arr[j+k].tx == i) {
                        result[vendor] += 2;
                        if (result[vendor] > 5) priority[vendor] = true;
                        current++;
                        check = true;
                        // printf("%d时刻时 %d号店+2 1\n", i, vendor); 
                    } else {vendor++; break;}
                }
            }
            else if (arr[j].id > vendor && arr[j].tx == i){
                for (int k=vendor; k<arr[j].id; k++) {
                    result[k] = max(0, result[k]-1);
                    if (result[k] <= 3) priority[k] = false;
                    // printf("%d时刻时 %d号店-1\n", i, k);
                    vendor++;
                }
                for (int k=0; ; k++){
                    if (arr[j+k].id == vendor && arr[j+k].tx == i) {
                        result[vendor] += 2;
                        if (result[vendor] > 5) priority[vendor] = true;
                        current++;
                        check = true;
                        // printf("%d时刻时 %d号店+2 2\n", i, vendor); 
                    } else {vendor++; break;}
                }
            }
            if (check == false){
                for (int k=1; k<=n; k++){
                    result[k] = max(0, result[k]-1);
                    if (result[k] <= 3) priority[k] = false;
                    // printf("%d时刻时 %d号店-1 3\n", i, k);
                }
                break;
            }
            if (vendor == n) break;
        }
        // cout << endl;
    }
    int cnt = 0;
    // cout << current << endl;
    for (int i=1; i<=n; i++){
        if (priority[i] == true) cnt++;
        // cout << result[i] << " ";
    }
    // cout << endl;
    cout << cnt << endl;
    return 0;
}