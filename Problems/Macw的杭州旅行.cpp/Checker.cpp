#include <algorithm>
#include <iostream>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>

using namespace std;
const int N = 5e5 + 10;
 
int n, m, k, L;
vector<int> a(N), b(N);

void solve()
{
    map<int, int> p, q;
    scanf("%d %d %d %d", &L, &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        q[b[i]]++;
    }

    int res = 0, num = k,l=0;
    for (int i = 1; i < L; i++)
    {
        if (p.count(i))
        {
            num=k;
            l=i;
            if(q.count(i))
                continue;
        }
        if(q.count(i)&&l)
        {
            int t=q[i];
            int x=min(t,(num)/(i-l));
            num-=x*(i-l);
            res+=x;
        }
    }    
    printf("%d\n", res);
}

int main()
{   
    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}
