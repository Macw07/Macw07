#include <iostream>
#include <cstring>
using namespace std;

string str;
int arr[30], heighest;

int main(){
    for (int i=1; i<=4; i++){
        getline(cin, str);
        for (int j=0; j<str.size(); j++){
            if (str[j] < 'A' || str[j] > 'Z') continue;
            arr[str[j]-'@'] += 1;
            heighest = max(heighest, arr[str[j]-'@']);
        }
    } 
    for (int j=heighest; j>=1; j--){
        for (int i=1; i<=26; i++){
            if (arr[i] >= j) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
    for (int i=1; i<=26; i++){
        cout << char('@'+i) << " ";
    }
    return 0;
}