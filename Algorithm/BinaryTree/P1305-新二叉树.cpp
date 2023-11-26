#include <iostream>
#include <algorithm>
using namespace std;

int n;
string str;
char arr[100005];

void build(string s, int k){
    if (arr[k] == s[0]){
        arr[2*k] = s[1];
        arr[2*k+1] = s[2];
        return ;
    }
    if (arr[2*k]) build(s, 2*k);
    if (arr[2*k+1]) build(s, 2*k+1);
    return ;
}

void print_tree(int k){
    cout << arr[k];
    if (arr[2*k] && arr[2*k] != '*') print_tree(2*k);
    if (arr[2*k+1] && arr[2*k+1] != '*') print_tree(2*k+1);
    return ;
}

int main(){
    cin >> n >> str;
    arr[1] = str[0];
    build(str, 1);
    for (int i=1; i<n; i++) {
        cin >> str;
        build(str, 1);
    }
    print_tree(1);
    return 0;
}