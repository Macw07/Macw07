#include <iostream>
#include <algorithm>
using namespace std;

string str;
int total = 0;
int numberss[] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1};

int main(){
    cin >> str;
    int len = str.size();
    for (int i=0; i<len; i++) total += numberss[str[i]-'0'];
    cout << total << endl;
    return 0;
}