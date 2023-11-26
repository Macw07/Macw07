#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
int arr[1000005];
map<int, int> m;
int max_value = 0;
int max_num = 0;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        if (m.count(arr[i])) m[arr[i]] += 1;
        else m[arr[i]] = 1;
    }
    for (int i=1; i<=n; i++){
        int t = m[arr[i]];
        if (t > max_value){
            max_value = t;
            max_num = arr[i];
        }
    }
    if (max_value > n / 2) printf("%d\n", max_num);
    else printf("No\n");
    return 0;
}