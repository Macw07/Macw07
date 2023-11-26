// 给出一个仅包含小写字母的字符串，长度<=100。请统计其中所有字母的出现次数，并按照字母表顺序输出
#include <iostream>
using namespace std;

int arr[100] = {};
int times[100] = {};

int pointer = 0;
bool add_in(char c, int cc);

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        add_in(str[i], i);
    }
    for (int i=0; i<pointer; i++){
        for (int j=0; j<pointer-1-i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swap(times[j], times[j+1]);
            }
        }
    }
    for (int i=0; i<pointer; i++){
        cout << char(arr[i]) << ":" <<times[i]+1 << endl;;
    }
    return 0;
}

bool add_in(char c, int cc){
    for (int i=0; i<cc; i++){
        if (arr[i] == c){
            times[i] += 1;
            return true;
        }
    }
    arr[pointer] = c;
    pointer++;
    return true;
}