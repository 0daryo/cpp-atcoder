#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
int main()
{
  int n;
  cin >> n;
  int a[n + 1];
  map<int, int> m;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    ans += m[a[i] - i];
    m[-a[i] - i]++;
  }
  cout << ans << endl;
  return 0;
}
