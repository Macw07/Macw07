#include <iostream>

using namespace std;

const int maxn = 100;

int a[maxn], b[maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    b[i] = a[i + 1] - a[i];
    if (i + 1 == n)
      b[i] = a[0] - a[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " \n"[i == (n - 1)];
  }
}
