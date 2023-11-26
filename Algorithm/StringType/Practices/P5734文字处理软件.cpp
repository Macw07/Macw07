#include <iostream>
#include <cstring>
// #include <string.h>
using namespace std;

int main(){
    int operate, t, t1, t2;
    string str, temp, temp2;
    cin >> operate >> str;
    for (int i=0; i<operate; i++){
        cin >> t;
        if (t == 1){
            cin >> temp;
            str = str + temp;
            cout << str << endl;
        }
        if (t == 2){
            cin >> t1 >> t2;
            temp = "";
            for (int j=t1; j<t1+t2; j++){
                temp += str[j];
            }
            str = temp;
            cout << str << endl;
        }
        if (t == 3){
            cin >> t1 >> temp2;
            temp = "";
            for (int j=0; j<t1; j++){
                temp += str[j];
            }
            temp += temp2;
            for (int j=t1; j<str.size(); j++){
                temp += str[j];
            }
            str = temp;
            cout << str << endl;
        }
        if (t == 4){
            cin >> temp2;
            temp = "";
            bool flag = true;
            for (int j=0; j<=str.size()-temp2.size(); j++){
                temp = "";
                for (int k=j; k<j+temp2.size(); k++){
                    temp += str[k];
                }
                // cout << temp << endl;
                if (temp2 == temp){
                    flag = false;
                    cout << j << endl;
                    break;
                }
            }
            if (flag){
                cout << -1 << endl;
            }
        }
    }
    return 0;
}