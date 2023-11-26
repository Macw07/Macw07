#include <iostream>
#include <map>
using namespace std;

const int MAXN = 2e4;
int n, m, k;
map<string, string> parent;

string find(string x){
    if (parent[x] == x) return x;
    string t = find(parent[x]);
    return parent[x] = parent[t];
}

void unionSet(string a, string b){
    string aS = find(a);
    string bS = find(b);
    parent[aS] = bS;
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string str;
        cin >> str;
        parent[str] = str;
    }
    for (int i=1; i<=m; i++){
        string s1, s2;
        cin >> s1 >> s2;
        unionSet(s1, s2);
    }
    cin >> k;
    while(k--){
        string s1, s2;
        cin >> s1 >> s2;
        string a = find(s1);
        string b = find(s2);
        if (a == b) cout << "Yes." << endl;
        else cout << "No." << endl;
    }
    return 0;
}