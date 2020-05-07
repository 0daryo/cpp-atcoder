#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  ll x;
  cin >> x;
  ll money = 100;
  ll ans = 0;
  while (1)
  {
    ans++;
    money += money * 0.01;
    if (x <= money)
    {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
