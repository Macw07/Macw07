#include <iostream>
using namespace std;

char arr[5][5];
bool xiaoa = false;
bool uim = false;

bool pd(int i, int j){
    // 判断
    if (arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i][j+2]) return true;
    if (arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+2][j]) return true;
    if (arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i+2][j+2]) return true;  
    if (i == 0 && j == 2 && arr[i][j] == arr[i+1][j-1] && arr[i][j] == arr[i+2][j-2]) return true;
    return false;
}


int main(){
    string s;
    int flag = 0;
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (flag == 0) arr[(s[i]-'0'-1)/3][(s[i]-'0'-1)%3] = 'O';
        else  arr[(s[i]-'0'-1)/3][(s[i]-'0'-1)%3] = 'X';
        flag ^= 1;
    }
    // for (int i=0; i<3; i++){
    //     for (int j=0; j<3; j++){
    //         if (arr[i][j]) cout << arr[i][j] << " ";
    //         else cout << "  ";
    //     }
    //     cout << endl;
    // }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (!arr[i][j]) continue;
            if (!xiaoa && arr[i][j] == 'O' && pd(i, j)) xiaoa = true; 
            if (!uim && arr[i][j] == 'X' && pd(i, j)) uim = true;
        }
    }
    // cout << xiaoa << "  " << uim << endl;
    if ((xiaoa && uim) || !(xiaoa || uim)) cout << "drew." << endl;
    else if (xiaoa) cout << "xiaoa wins." << endl;
    else cout << "uim wins." << endl;
    return 0;
}