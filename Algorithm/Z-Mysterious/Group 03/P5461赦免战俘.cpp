#include <iostream>
#include <cmath>
using namespace std;

int arr[1050][1050];
int n;

void absolve(int begin, int end, int id){
    if (id == 2){
        arr[begin][end] = 0;
        return;
    }
    for (int i=begin; i<=begin+id/2-1; i++){
        for (int j=end; j<=end+id/2-1; j++){
            arr[i][j] = 0;
        }
    }
    absolve(begin+id/2, end, id/2);
    absolve(begin+id/2, end+id/2, id/2);
    absolve(begin, end+id/2, id/2);
    return;
}

int main(){
    cin >> n;
    n = pow(2, n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j] = 1;
        }
    }
    absolve(0, 0, n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
