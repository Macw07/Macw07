// #include <iostream>
// using namespace std;

// long long arr[100005];

// int main(){
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     for (int i=0; i<n-2; i++){
//         if (arr[i] < arr[i+1] && arr[i+1] > arr[i+2]){
//             cout << "true" << endl;
//             return 0;
//         }
//     }
//     cout << "false" << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int arr[100005];

// int main(){
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     for (int i=0; i<n; i++){
//         for (int j=i+1; j<n; j++){
//             for (int k=j+1; k<n; k++){
//                 if (arr[i] < arr[j] && arr[j] > arr[k]){
//                     cout << "true" << endl;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << "false" << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int arr[100005];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        int k=0;
        for (int j=i+1; j<n; j++){
            if (arr[j] > arr[i]){
                if (arr[j] > k){
                    k = arr[j];
                } else{
                    cout << "true" << endl;
                    return 0;
                }   
            }
        }
    }
    cout << "false" << endl;
    return 0;
}