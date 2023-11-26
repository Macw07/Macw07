#include <iostream>
#include <algorithm>
using namespace std;

int n;
string ans;

struct node{
    int left, right;
} arr[10005];

// 高精度乘法
string HighPreciseMulti(string a, string b){
    string ans;
    bool flag = true;
    int sum[10005] = {};
    int lena = a.size(), lenb = b.size();
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
    for (int i=0; i<lena; i++){
        for (int j=0; j<lenb; j++){
            sum[i+j] += (a[i]-'0')*(b[j]-'0');
        }
    }
    for (int i=0; i<=lena+lenb; i++){
        sum[i+1] += sum[i] / 10;
        sum[i] %= 10;
    }
    for (int i=lena+lenb-1; i>=0; i--){
        if (flag && sum[i]==0) continue;
        else flag = false;
        ans += sum[i]+'0';
    }
    return ans;
}

// 高精度除法
string HighPreciseDivison(string a, int b){
    int ptr = 0, c = 0;
    long long sum = 0;
    int temp[10005] = {}, flag = 1;
    string ans;
    for (int i=0; i<a.size(); i++){
        sum = sum * 10 + (a[i]-'0');
        temp[ptr++] = sum / b;
        sum %= b;
    }
    for (int i=0; i<a.size(); i++){
        if (flag && temp[i] == 0) continue;
        else flag = 0;
        ans += temp[i]+'0';
    }
    return ans;
}

// 数字转字符串
string convert(int n){
    string ans;
    while(n){
        ans += n%10 + '0';
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


// 按照乘积从小到大排列
bool cmp(node a, node b){
    int p1 = a.left * a.right;
    int p2 = b.left * b.right;
    return p1 < p2;
}

bool compare(string a, string b){
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i=0; i<a.size(); i++){
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return false;
}

int main(){
    cin >> n;
    for (int i=0; i<=n; i++) cin >> arr[i].left >> arr[i].right;
    // 看似这是一道贪心的题目，但实际上妥妥的是一个高精度题目，真的很累，写高精度乘法和高精度除法。
    sort(arr+1, arr+1+n, cmp);
    // 模拟过程 -> 贪心
    string sum = "1";  // 初始化
    for (int i=0; i<=n; i++){
        string current = HighPreciseDivison(sum, arr[i].right);
        sum = HighPreciseMulti(sum, convert(arr[i].left));
        if (compare(current, ans)) ans = current;
    }
    cout << ans << endl;
    return 0;
}