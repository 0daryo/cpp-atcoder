#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

cons ll MX = 1e18;

int main()
{
  int n;
  cin >> n;
  ll ans = 1;
  rep(i, n)
  {
    ll a;
    cin >> a;
    if (a == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}
