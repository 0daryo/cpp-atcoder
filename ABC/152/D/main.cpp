#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef unsigned long long ull;

P f(int x)
{
  int a = x % 10;
  int b = 0;
  while (x)
  {
    b = x;
    x /= 10;
  }
  return P(a, b);
}

int main()
{
  int n;
  cin >> n;
  map<P, int> freq;
  for (int i = 1; i <= n; i++)
  {
    P p = f(i);
    freq[p]++;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    P p = f(i);
    P q(p.second, p.first);
    ans += freq[q];
  }
  cout << ans << endl;
}