#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define size(x) int(x.size())

int main()
{
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k <= a)
  {
    cout << k << endl;
    return 0;
  }
  if (k <= a + b)
  {
    cout << a << endl;
    return 0;
  }
  cout << a - (k - (a + b)) << endl;
  return 0;
}
