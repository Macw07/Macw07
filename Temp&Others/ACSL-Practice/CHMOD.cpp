#include <iostream>
#include <algorithm>
using namespace std;

string str;
int arr[5];
string converted[5];
string permission = "rwx";

string convert(int k){
    string ans = "";
    while(k){
        ans += (k % 2) + '0';
        k /= 2;
    }
    while(ans.size() != 3) ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int t = 5;
    while(t--){
        scanf("%d,%d,%d,%d", &arr[0], &arr[1], &arr[2], &arr[3]);
        for (int i=1; i<=3; i++){
            converted[i] = convert(arr[i]);
            cout << converted[i] << " ";
        }
        cout << "and ";
        for (int i=1; i<=3; i++){
            string ans = "";
            for (int j=0; j<3; j++){
                if (converted[i][j] == '1') ans += permission[j];
                else ans += '-';
            }
            if (arr[0] == 1 && converted[i][2] == '1' && i == 1) ans[2] = 's';
            else if (arr[0] == 2 && converted[i][2] == '1' && i == 2) ans[2] = 's';
            else if (arr[0] == 4 && converted[i][2] == '1' && i == 3) ans[2] = 't';
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}