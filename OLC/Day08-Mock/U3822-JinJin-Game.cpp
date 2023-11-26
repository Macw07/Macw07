#include <iostream>
#include <algorithm>
using namespace std;

string str, s2; 
int k, ki, m;

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> str >> k;
    while(k--){
        cin >> ki;
        if (ki == 1){
            reverse(str.begin(), str.end());
            continue;
        }
        if (ki == 2){
            cin >> s2;
            reverse(s2.begin(), s2.end());
            str += s2;
            continue;
        }
        if (ki == 3){
            str += "yyds";
            continue;
        }
        if (ki == 4){
            for (int i=0; i<str.size(); i++){
                if (str[i] == 'a') str[i] = 'x';
                else if (str[i] == 'b') str[i] = 'y';
                else if (str[i] == 'c') str[i] = 'z';
                else str[i] -= 3;
            }
            continue;
        }
    }
    cin >> m;
    cout << str[m-1] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}