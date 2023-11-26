#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int t;

int main(){
    cin >> t;
    while(t--){
        queue<int> que;
        while (1){
            string str;
            cin >> str;
            if (str == "feed"){
                int a;
                cin >> a;
                que.push(a);
                cout << "OK" << endl;
            }
            if (str == "poop"){
                if (que.size()){
                    cout << que.front() << endl;
                    que.pop();
                }
            }
            if (str == "guess"){
                cin >> str;
                if (str == "queueon") {
                    cout << "CORRECT" << endl;
                    break;
                }
                else {
                    cout << "WRONG_ANSWER" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}