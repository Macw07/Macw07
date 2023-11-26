#include <iostream>
using namespace std;

int main(){
    int begin, end, n=0, c=0;
    int arr[1000];
    cin >> begin >> end;
    for (int i=begin; i<=end; i++){
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
            arr[n++] = i;
            c++;
        }
    }
    cout << c << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}