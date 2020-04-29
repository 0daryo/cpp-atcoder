#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  ll s = 0;
  int j = 0;
  ll ans = 0;
  rep(i, n)
  {
    while (j < n && s + a[j] < k)
    {
      s += a[j];
      j++;
    }
    ans += j - i;
    s -= a[i];
  }
  ans = (ll)n * (n + 1) / 2 - ans;
  cout << ans << endl;
  return 0;
}
