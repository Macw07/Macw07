#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("kunkun.in", "r", stdin);
    freopen("kunkun.out", "w", stdout);
    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << str << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}