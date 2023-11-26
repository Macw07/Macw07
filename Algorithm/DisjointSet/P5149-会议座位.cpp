#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 5;
int n, depth;
int trie[MAXN][65];
int vis[MAXN];
int arr[100005];
int temp[100005] = {};
long long ans;

int change(char c){
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(string str, int order){
    int len = str.size();
    int root = 0;
        int t = change(str[i]);
        if (trie[root][t] == 0){
            trie[root][t] = ++depth;
        }
        root = trie[root][t];
    }
    vis[root] = order;
    return ;
}

int query(string str){
    int len = str.size();
    int root = 0;
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        if (trie[root][t] == 0){
            return 65;
        }
        root = trie[root][t];
    }
    return vis[root];
}

void merge(int l, int mid, int r){
    int len = mid - l + 1;
    int rbegin = mid + 1;
    int lbegin = l;
    int pos = l;
    while(l <= mid && rbegin <= r){
        if (arr[l] > arr[rbegin]){
            temp[pos++] = arr[rbegin++];
            ans = ans + (mid - l + 1);
        } else {
            temp[pos++] = arr[l++];
        }
    }
    while(l <= mid) temp[pos++] = arr[l++];
    while(rbegin <= r) temp[pos++] = arr[rbegin++];
    for (int i=lbegin; i<pos; i++) arr[i] = temp[i];
    return ;
}

void mergeSort(int l, int r){
    if (l < r){
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        string str;
        cin >> str;
        insert(str, i);
    }
    for (int i=1; i<=n; i++){
        string str;
        cin >> str;
        arr[i] = query(str);
    }
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}