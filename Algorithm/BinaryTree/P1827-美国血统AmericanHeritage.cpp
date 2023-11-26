#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void after(string in, string before){
    if (in.size()){
        int ch = before[0];  // 找到第一个
        int k = in.find(ch);
        after(in.substr(0, k), before.substr(1, before.size()+k-1));
        after(in.substr(k+1), before.substr(k+1));
        cout << char(ch);
    }
    return ;
}

int main(){
    string in, before;
    cin >> in >> before;
    after(in, before);
    return 0;
}