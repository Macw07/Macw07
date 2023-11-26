#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void before(string in, string after){
    if (in.size()){
        char lst = after[after.size()-1];  // 找到根节点
        cout << lst;
        int k = in.find(lst);
        before(in.substr(0, k), after.substr(0, k));
        before(in.substr(k+1), after.substr(k, in.size()-1-k));
    }
    return ;
}

int main(){
    string inord, aftord;
    cin >> inord >> aftord;
    before(inord, aftord);
    return 0;
}