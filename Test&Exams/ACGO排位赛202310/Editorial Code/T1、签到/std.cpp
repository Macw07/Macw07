#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
    fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dis = abs(a - c) + abs(b - d);
    if (dis >= 6)
        cout << "Arisu";
    else
        cout << "Midori";
    return 0;
}