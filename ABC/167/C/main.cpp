#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define size(x) int(x.size())

#define INF 1000000000000
int main()
{
  ll n, m, x;
  cin >> n >> m >> x;
  ll ans = INF;
  vector<vector<ll>> v(n);
  vector<ll> mon;
  rep(i, n)
  {
    ll ma;
    cin >> ma;
    mon.push_back(ma);
    rep(j, m)
    {
      ll in;
      cin >> in;
      v[i].push_back(in);
    }
  }
  // rep(p, m)
  // {
  //   cout << tot[p] << endl;
  // }
  // cout << 1111111 << endl;
  rep(i, 1 << n)
  {
    vector<ll> tot(m, 0);
    ll money = 0;
    rep(j, n) if (i >> j & 1)
    {
      rep(k, m)
      {
        tot[k] += v[j][k];
      }
      money += mon[j];
    }
    // cout << 1111111 << endl;
    // rep(p, m)
    // {
    //   cout << tot[p] << endl;
    // }
    // cout << 1111111 << endl;
    bool ok = true;
    rep(l, m)
    {
      if (tot[l] < x)
      {
        ok = false;
      }
    }
    if (!ok)
    {
      continue;
    }
    ans = min(ans, money);
  }
  if (ans == INF)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
