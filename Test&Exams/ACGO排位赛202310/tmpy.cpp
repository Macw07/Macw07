#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string str(int n)
{
    string ans = "";
    while (n > 0)
    {
        ans += char(48 + n % 10);
        n = n / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


string change(string s)
{
    string ans = "";
    char now = s[0];
    int cnt = 0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == now){
            cnt++;
        }
        else
        {
            ans = ans + str(cnt) + now;
            cnt = 1;
            now = s[i];
        }
         
    }
    ans = ans + str(cnt) + now;
    return ans;
}

int main()
{
    string s;
    int n;
    cin >> s;
    cin >> n;
    while (n--)
    {
        s = change(s);
        // cout << s << endl;
    }
    cout << s;
    return 0;
}