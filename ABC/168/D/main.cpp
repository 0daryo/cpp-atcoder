#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())
#define INF 1000000000000

vector<vector<ll>> to;
vector<ll> ans;
queue<ll> q;
int n, m;

int main()
{
  cin >> n >> m;
  to.resize(n);
  rep(i, n)
  {
    ans.push_back(-1);
  }
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  q.push(0);
  ans[0] = 0;
  ll now = 0;
  while (q.size())
  {
    now = q.front();
    q.pop();
    vector<ll> tos = to[now];
    rep(i, tos.size())
    {
      ll t = tos[i];
      if (ans[t] == -1)
      {
        ans[t] = now;
        q.push(t);
      }
    }
  }
  vector<ll> output;
  rep(i, ans.size())
  {
    if (ans[i] == -1)
    {
      cout << "No" << endl;
      return 0;
    }
    output.push_back(ans[i]);
  }
  cout << "Yes" << endl;
  rep(i, n)
  {
    if (i == 0)
      continue;
    cout << output[i] + 1 << endl;
  }
  return 0;
}
