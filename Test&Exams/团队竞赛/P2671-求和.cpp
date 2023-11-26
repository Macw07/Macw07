#include <iostream>
using namespace std;

int n, m;
int arr[100005];
int color[100005];

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for (int i=1; i<=m; i++) scanf("%d", &color[i]);
    return 0;
}