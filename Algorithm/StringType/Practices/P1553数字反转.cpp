#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s, news, temp, sign;
    bool flag = 0, flag2 = 0;
    cin >> s;
    if (s == "0"){
        cout << s;
        return 0;
    }
    if (s == "0%"){
        cout << s;
        return 0;
    }
    for (int i=s.size()-1; i>=0; i--){
        if(s[i] == '%'){
            flag = 1;
            continue;
        }
        if (s[i] == '.' || s[i] == '/'){
            sign = s[i];
            flag2 = 1;
            continue;
        }
        if (flag2){
            temp += s[i];
        }else{
            news += s[i];
        }
        
    }
    // 特殊符号的判断
    if (flag){
        news += '%';
    }
    // 导零
    int count = 0;
    bool flag3 = 1;
    string ans;
    if (!flag2){
        for (int i=0; i<news.size(); i++){
            if (news[i] == '0' && flag3){
                continue;
            } else{
                ans += news[i];
                flag3 = 0;
            }
        }
    } else{
        if (temp != "0"){
            for (int i=0; i<temp.size(); i++){
                if (temp[i] == '0' && flag3){
                    continue;
                } else{
                    ans += temp[i];
                    flag3 = 0;
                }
            }
        } else{
            ans += '0';
        }
        ans += sign;
        string aaa;
        if(news != "0"){
            flag3 = 1;
            for (int i=0; i<news.size(); i++){
                if (news[i] == '0' && flag3){
                    continue;
                } else{
                    aaa += news[i];
                    flag3 = 0;
                }
            }
            flag3 = 1;
            for (int i=aaa.size()-1; i>=0; i--){
                if (aaa[i] == '0'){
                    aaa[i] = ' ';
                } else{
                    break;
                }
            }
            news = aaa;
        }
        ans += news;
    }
    cout << ans;
    return 0;
}