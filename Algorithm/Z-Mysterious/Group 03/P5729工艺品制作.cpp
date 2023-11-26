#include <iostream>
#include <cstring>
using namespace std;

int x, y, z, n;
int cnt = 0;
int arr[25][25][25];

int main(){
    cin >> x >> y >> z >> n;
    while(n--){
        // Pass
        int a1, b1, c1, a2, b2, c2;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        for (int i=a1; i<=a2; i++){
            for (int j=b1; j<=b2; j++){
                for (int k=c1; k<=c2; k++){
                    if (i > x || j > y || k > z) continue;
                    if (arr[i][j][k] == 0) cnt++;
                    arr[i][j][k] = -1;
                }
            }
        }
    }
    cout << x*y*z - cnt << endl;
    return 0;
}