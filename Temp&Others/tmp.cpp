#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define re register 
const int maxn = 1000005;
char st[maxn * 2];
int len[maxn * 2], cnt;
int vis[maxn * 2];
int T;
int mx, po;

inline void input ()
{
	char ch = getchar ();
	st[0] = '~', st[cnt = 1] = '#';
	while (ch < 'a' or ch > 'z') ch = getchar ();
	while (ch >= 'a' and ch <= 'z') st[++cnt] = ch, st[++cnt] = '#', ch = getchar (); 
    st[cnt + 1] = '%';
}

int main ()
{
	scanf ("%d", &T);
	while (T--)
	{
		cnt = mx = po = 0;
		memset (vis, 0, sizeof vis);
		memset (len, 0, sizeof len);
		input ();
        cout << cnt << endl;
        
		for (re int i (1); i <= cnt; ++i)//Manacher 模板 
		{
			if (i <= mx) len[i] = min (mx - i, len[po * 2 - i]);
			while (st[i + len[i]] == st[i - len[i]]) len[i]++;
			if (i + len[i] > mx) mx = i + len[i] - 1, po = i;
		}
        cout << cnt << endl;
        for (int i=1; i<=cnt; i++){
            cout << len[i] << " ";
        }cout << endl;
		for (re int i (cnt); i >= 1; --i)
		{
			if (i + len[i] - 1 == cnt) vis[i] = 1;//如果能一次翻转成 
			else if (vis[i + len[i] - 2] and i == len[i]) vis[i] = 1;//如果它能翻转成某个最长翻转子串，如 qwqwq 的 qwqw 的 qw ，且不会越界 
		}
		for (re int i (1); i <= cnt; ++i) if (st[i] >= 'a' and st[i] <= 'z' and vis[i]) printf ("%d ", i / 2);
			//Manacher 处理后的字符串转化成原字符串，长度直接除以 2 就可以得到原字符串的长度 
		printf ("\n");
	}
	return 0;
}