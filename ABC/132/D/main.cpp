#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int mod = 1000000007;

struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
mint c[4005][4005];
void init()
{
  c[0][0] = 1;
  for (int i = 0; i <= 4000; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      c[i + 1][j] += c[i][j];
      c[i + 1][j + 1] += c[i][j];
    }
  }
}
mint comb(int n, int k)
{
  return c[n][k];
}
mint f2(int n, int k)
{
  return comb(n + k - 1, k - 1);
}
mint f(int n, int k)
{
  if (n < k)
    return 0;
  if (n == 0 && k == 0)
    return 1;
  if (k < 1)
    return 0;
  return f2(n - k, k);
}

// x1+x2+⋯+xk=n
// xi≥0
// を満たす整数 (x1,x2,…,xk) の組の個数を重複組合せと呼び、n+k−1Ck−1 通り。

// x1+x2+⋯+xk=n
// xi≥1
// を満たす整数 (x1,x2,…,xk) の組の個数は n−1Ck−1 通りになる
int main()
{
  init();
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++)
  {
    mint blue = f(k, i);
    mint red = 0;
    {
      red += f(n - k, i - 1);
      red += f(n - k, i);
      red += f(n - k, i);
      red += f(n - k, i + 1);
    }
    mint ans = blue * red;
    printf("%lld\n", ans.x);
  }
  return 0;
}
