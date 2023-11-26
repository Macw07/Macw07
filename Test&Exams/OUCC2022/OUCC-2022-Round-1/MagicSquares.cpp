#include <iostream>
#include <algorithm>
using namespace std;

int arr[5][5];
int sum = 0;

int main(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            cin >> arr[i][j];
        }
    }
    sum = arr[1][1] + arr[1][2] + arr[1][3];

    if (arr[2][1] + arr[2][2] + arr[2][3] != sum){
        cout << "muggle" << endl;
        return 0;
    }
    if (arr[3][1] + arr[3][2] + arr[3][3] != sum){
        cout << "muggle" << endl;
        return 0;
    }

    if (arr[1][1] + arr[2][1] + arr[3][1] != sum){
        cout << "muggle" << endl;
        return 0;
    }
    if (arr[1][2] + arr[2][2] + arr[3][2] != sum){
        cout << "muggle" << endl;
        return 0;
    }
    if (arr[3][1] + arr[3][2] + arr[3][3] != sum){
        cout << "muggle" << endl;
        return 0;
    }

    if (arr[1][1] + arr[2][2] + arr[3][3] != sum){
        cout << "muggle" << endl;
        return 0;
    }

    if (arr[1][3] + arr[2][2] + arr[3][1] != sum){
        cout << "muggle" << endl;
        return 0;
    }
    cout << "magic" << endl;
    return 0;
}