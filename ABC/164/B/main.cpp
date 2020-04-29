#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (1)
  {
    c -= b;
    if (c <= 0)
    {
      cout << "Yes" << endl;
      break;
    }
    a -= d;
    if (a <= 0)
    {
      cout << "No" << endl;
      break;
    }
  }
  return 0;
}
