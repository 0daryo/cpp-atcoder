#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  ll a, b, n;
  cin >> a >> b >> n;
  ll x = n;
  if (n >= b - 1)
    x = b - 1;
  ll ans = a * x / b - (x % b) / b;
  cout << ans << endl;
  return 0;
}
