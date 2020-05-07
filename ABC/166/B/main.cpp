#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> snu(n, 0);
  rep(i, k)
  {
    int d;
    cin >> d;
    rep(j, d)
    {
      int a;
      cin >> a;
      a--;
      snu[a] = 1;
    }
  }
  int ans = 0;
  rep(i, snu.size())
  {
    if (snu[i] == 0)
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
