/* 杨辉三角 */
#include <iostream>
using namespace std;


int sub(int arr[], int length, int times){
    for (int i=0; i<times-1; i++){
            // cout << "length: " << length << endl;
            length += 1;
            int new_arr[length];
            new_arr[0] = 0;
            for (int i=1; i<length-1; i++){
                new_arr[i] = arr[i-1] + arr[i]; 
                cout << new_arr[i] << "  ";
            }
            new_arr[length-1] = 0;
            for (int i=0; i<length; i++){
                arr[i] = new_arr[i];
            }
            cout << endl;
        }
    return 0;
}

int main(){
    int times;
    cin >> times;
    bool count = 1;
    int length = 3;
    if (times>0){
        cout << 1 << endl;
    }
    int arr[length];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 0;

    sub(arr, length, times);
    return 0;

}
