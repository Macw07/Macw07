#include <iostream>
#include <algorithm>
using namespace std;

string ans = "DCBAD";
int total = 0;

int main(){
    string user;
    cin >> user;
    for (int i=0; i<5; i++) if (user[i] == ans[i]) total += 30;
    cout << total << endl;
    return 0;
}