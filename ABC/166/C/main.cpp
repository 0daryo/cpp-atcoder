#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> h;
  vector<vector<ll>> paths(n);
  rep(i, n)
  {
    ll th;
    cin >> th;
    h.push_back(th);
  }
  // rep(i, n)
  // {
  //   cout << 111111111 << endl;
  //   cout << h[i] << endl;
  //   cout << 111111111 << endl;
  // }
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    // if (a == 0 || b == 0)
    // {
    //   cout << "" << endl;
    //   cout << a << endl;
    //   cout << b << endl;
    // }
    paths[a].push_back(h[b]);
    paths[b].push_back(h[a]);
  }
  // rep(i, paths[0].size())
  // {
  //   cout << paths[0][i] << endl;
  // }
  ll ans = 0;
  rep(i, n)
  {
    bool best = true;
    // if (i == 0)
    // {
    //   rep(j, paths[i].size())
    //   {
    //     cout << h[i] << endl;
    //     cout << paths[i][j] << endl;
    //   }
    // }
    rep(j, paths[i].size())
    {
      if (h[i] <= paths[i][j])
      {
        best = false;
      }
    }
    if (best)
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
