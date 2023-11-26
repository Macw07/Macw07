#include <iostream>
#include <queue>
using namespace std;

string str;
long long total = 0, len;
queue<long long> que;

// 字符串转数字
int convert(int i){
    long long sum = 0, j;
    for (j=i; j<len; j++){
        if (str[j] >= '0' && str[j] <= '9'){
            sum = sum*10 + str[j]-'0';
        } else break;
    }
    que.push(sum);
    total++;
    return j;
};

int main(){
    getline(cin, str);
    len = str.size();
    for (int i=0; i<len; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            i = convert(i);
        };
    }
    cout << total << endl;
    while(!que.empty()){cout << que.front() << endl; que.pop();}
    return 0;
}