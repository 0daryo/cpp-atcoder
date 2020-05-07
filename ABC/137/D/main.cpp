#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> jobs(m);
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    if (a > m)
      continue;
    jobs[m - a].push_back(b);
  }
  priority_queue<int> q;
  ll ans = 0;
  for (int i = m - 1; i >= 0; i--)
  {
    for (int b : jobs[i])
    {
      q.push(b);
    }
    if (!q.empty())
    {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
