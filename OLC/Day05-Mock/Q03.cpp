#include <iostream>
#include <algorithm>
using namespace std;

int w, n;
int arr[30005];
int l, r, total;


int main(){
    freopen("boat.in", "r", stdin);
    freopen("boat.out", "w", stdout);
    cin >> w >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    l = 1, r = n;
    while(l <= r){
        if (arr[r] + arr[l] > w){
            r--; total++;
        } else{
            r--; l++; total++;
        }
    }
    cout << total << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}