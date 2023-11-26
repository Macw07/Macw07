#include <iostream>
#include <algorithm>
using namespace std;

char arr1[15][15] = {};
char arr2[15][15] = {};
char arr3[15][15] = {};

bool equal(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr1[i][j] != arr2[i][j]) {
                // cout << i << " " << j << endl;
                // cout << arr1[i][j] << " " << arr2[i][j] << endl;
                return false;
            }
        }
    }
    return true;
}

void revalue(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr1[i][j] = arr3[i][j];
        }
    }
}

void rotate90(int n){
    int c=0, k=0;
    for (int i=0; i<n; i++){
        for (int j=n-1; j>=0; j--){
            arr3[c][k] = arr1[j][i];
            k++;
        }
        k = 0;
        c++;
    }
    revalue(n);
}

void reflect(int n){
    int c=0, k=0;
    for (int i=0; i<n; i++){
        for (int j=n-1; j>=0; j--){
            arr3[c][k] = arr1[i][j];
            k++;
        }
        c++;
        k=0;
    }
    revalue(n);
}

int main(){
    int n;
    string s;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr1[i][j] = s[j];
        }
    }
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<n; j++){
            arr2[i][j] = s[j];
        }
    }
    for (int i=0; i<4; i++){
        rotate90(n);
        if (equal(n)){
            cout << i+1 << endl;
            return 0;
        }
    }
    if (equal(n)){
        cout << 6 << endl;
        return 0;
    }
    reflect(n);
    if (equal(n)){
        cout << 4 << endl;
        return 0;
    }
    for (int i=0; i<4; i++){
        rotate90(n);
        if (equal(n)){
            cout << 5 << endl;
            return 0;
        }
    }
    cout << 7 << endl;
    return 0;
}