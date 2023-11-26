// #include <iostream>
// #include <cstring>
// using namespace std;

// int k;
// int total = 0;
// string str;

// int main(){
//     scanf("%d\n", &k);
//     getline(cin, str);
//     int len = str.size();
//     str += "         ";
//     // 字符串匹配
//     string alice="", bob="";
//     bool checkAlice = false, checkBob = false;
//     int count = 0;
//     for (int i=0; i<len; i++){
//         if (str[i] == 'A' && str[i+4] == 'e' 
//         && ((i == 0) || (!(str[i-1] >= 'A' && str[i-1] <= 'Z') && !(str[i-1] >= 'a' && str[i-1] <= 'z')))
//         && !(str[i+5] >= 'A' && str[i+5] <= 'Z') && !(str[i+5] >= 'a' && str[i+5] <= 'z')){
//             // 匹配alice
//             for (int j=0; j<5; j++){
//                 alice += str[i+j];
//             }
//             if (alice == "Alice") {checkAlice = true; i+=4; count=0;}
//             alice = "";
//             if (checkAlice && checkBob) total++; 
//         }
//         if (str[i] == 'B' && str[i+2] == 'b' 
//         && ((i == 0) || (!(str[i-1] >= 'A' && str[i-1] <= 'Z') && !(str[i-1] >= 'a' && str[i-1] <= 'z')))
//         && !(str[i+3] >= 'A' && str[i+3] <= 'Z') && !(str[i+3] >= 'a' && str[i+3] <= 'z')){
//             // 匹配bob
//             for (int j=0; j<3; j++){
//                 bob += str[i+j];
//             }
//             if (bob == "Bob") {checkBob = true; i+=2; count=0;}
//             bob = "";
//             if (checkAlice && checkBob) total++; 
//         }
//         if (count == k+1){
//             // cout << count << endl;
//             checkAlice = false;
//             checkBob= false;
//             count = 0;
//         }
//         count++;
//     }
//     cout << total << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int k, len, ans;
string str;

bool check_is_single(int index, int type_){
    if ((str[index-1] >= 'A' && str[index-1] <= 'Z') 
    || (str[index-1] >= 'a' && str[index-1] <= 'z')) return false;
    if ((str[index+type_] >= 'A' && str[index+type_] <= 'Z') 
    || (str[index+type_] >= 'a' && str[index+type_] <= 'z')) return false;
    return true;
}

int find_alice_in_k(int i){
    int cnt = 0;
    for (int index=i; index<=min(len, i+k); index++){
        if (!check_is_single(index, 5)) continue;
        string pattern = str.substr(index, 5);
        if (pattern == "Alice") cnt += 1;
    }
    return cnt;
}

int find_bob_in_k(int i){
    int cnt = 0;
    for (int index=i; index<=min(len, i+k); index++){
        if (!check_is_single(index, 3)) continue;
        string pattern = str.substr(index, 3);
        if (pattern == "Bob") cnt += 1;
    }
    return cnt;
}

int main(){
    scanf("%d\n", &k);
    getline(cin, str);
    str = " " + str;

    len = str.size();

    for (int i=0; i<str.size(); i++){
        // 通过 Bob 找 Alice
        if (check_is_single(i, 3)){
            string match = str.substr(i, 3);
            if (match == "Bob"){
                int cnt = find_alice_in_k(i+4);
                ans += cnt;
                // cout << i << " " << cnt << endl;
            }
        }

        // 通过 Alice 找 Bob
        if (check_is_single(i, 5)){
            string match = str.substr(i, 5);
            if (match == "Alice"){
                int cnt = find_bob_in_k(i+6);
                ans += cnt;
                // cout << i << ' ' << cnt << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
