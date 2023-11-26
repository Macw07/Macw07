#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, int> map;

int main(){
    cin >> n;
    while(n--){
        string t;
        cin >> t;
        if (!map.count(t)){
            cout << "OK" << endl;
            map[t] += 1;
        } else{
            // 不断尝试。
            cout << t << map[t] << endl;
            map[t] += 1;
        }
    }
    return 0;
}