#include <iostream>
#include <algorithm>
using namespace std;

int h, s;
string command;

int main(){
    cin >> h >> s >> command;
    for (int i=0; i<command.size(); i++){
        if (command[i] == 'u' && s > 0){
            s -= 1;
        } else if (command[i] == 'd' && s < h){
            s += 1;
        }
    }
    cout << s << endl;
    return 0;
}