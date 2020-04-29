#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  int n;
  cin >> n;
  priority_queue<P, vector<P>, greater<P>> que;
  ll total = 0;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    if (b - a < 0)
    {
      cout << "No" << endl;
      return 0;
    }
    que.push(make_pair(b, a));
  }
  rep(i, n)
  {
    P p = que.top();
    que.pop();
    total += p.second;
    if (p.first < total)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
