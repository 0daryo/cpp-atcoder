#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  ll n;
  cin >> n;
  // rep(i, n)
  // {
  //   if (i == 0)
  //   {
  //     continue;
  //   }
  //   ll x = i;
  //   for (ll a = -100; a < 100; a++)
  //   {
  //     for (ll b = -100; b < 100; b++)
  //     {
  //       if (a * a * a * a * a - b * b * b * b * b == x)
  //       {
  //         cout << 111111 << endl;
  //         cout << "x: " << x << "  a:" << a << "  b:" << b << endl;
  //         cout << 11111111 << endl;
  //       }
  //     }
  //   }
  // }
  rep(a, 1000)
  {
    for (ll b = -a; b <= a; b++)
    {
      if (a * a * a * a * a - b * b * b * b * b == n)
      {
        cout << a << " " << b << endl;
      }
    }
  }
  return 0;
}
