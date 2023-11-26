#include <iostream>
using namespace std;

char arr[6][10000];
int c = 0;

void zero(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void one(){
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void two(){
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void three(){
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void four(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void five(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void six(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void seven(){
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void eight(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
void nine(){
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='.';
    arr[3][c]='X';
    arr[4][c]='.';
    arr[5][c]='X';
    c++;
    arr[1][c]='X';
    arr[2][c]='X';
    arr[3][c]='X';
    arr[4][c]='X';
    arr[5][c]='X';
    c++;
    arr[1][c]='.';
    arr[2][c]='.';
    arr[3][c]='.';
    arr[4][c]='.';
    arr[5][c]='.';
    c++;
}
int main(){
    int n;
    string str;
    cin >> n >> str;
    for (int i=0; i<n; i++){
        if (str[i]=='1') one();
        else if (str[i]=='2') two();
        else if (str[i]=='3') three();
        else if (str[i]=='4') four();
        else if (str[i]=='5') five();
        else if (str[i]=='6') six();
        else if (str[i]=='7') seven();
        else if (str[i]=='8') eight();
        else if (str[i]=='9') nine();
        else if (str[i]=='0') zero();
    }
    for (int i=1; i<=5; i++){
        for (int j=0; j<c-1; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}