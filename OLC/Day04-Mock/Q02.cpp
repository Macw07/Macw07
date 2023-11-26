#include <iostream>
using namespace std;

int n; char c;
int arr[5];

int main(){
    cin >> n;
    while(cin >> c) arr[c-'A'+1]++;
    if (arr[1] > arr[2] && arr[1] > arr[3]) cout << "human" << endl;
    if (arr[2] > arr[1] && arr[2] > arr[3]) cout << "puppy" << endl;
    if (arr[3] > arr[1] && arr[3] > arr[2]) cout << "saiyan" << endl;
    return 0;
}