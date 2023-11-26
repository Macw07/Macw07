/*
小码最近迷上了一种彩票，这种彩票有三位，
每一位都是 0~9 当中的一个。
但是选彩票对小码来说是一件头疼的事情，所以他总是让机器随机给他排一组号码。
为了增加中奖的概率，他每次买彩票的时候，都会买很多组。
不可避免的，小码总是会遇到相同的号码。
现在他只想知道自己买的号码有多少种，分别是什么。请设计一个程序帮助他。
*/

#include <iostream>
#include <set>
using namespace std;

struct node{
    string str;
    bool friend operator < (node a, node b){
        int lena = a.str.size();
        int lenb = b.str.size();
        if (lena != lenb){
            return lena < lenb;
        }
        for (int i=0; i<lena; i++){
            if (a.str[i] != b.str[i]){
                return a.str[i] < b.str[i];
            }
        }
        return false;
    }
};
set<node> s;

int main(){
    int n;
    cin >> n;
    while(n--){
        string t;
        cin >> t;
        s.insert((node){t});
    }
    cout << s.size() << endl;
    set<node>::iterator ita;
    for(ita = s.begin(); ita != s.end(); ita++){
        cout << ita->str << " ";
    }
    cout << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << it->str << " ";
    }
    return 0;
}