#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  ll left = 4 * a * b;
  ll right = (c - a - b) * (c - a - b);
  if (a + b > c)
  {
    cout << "No" << endl;
    return 0;
  }
  if (left < right)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
