#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

int main()
{
  int k;
  string s;
  cin >> k >> s;
  string ans = "";
  rep(i, s.size())
  {
    if (k == ans.size())
    {
      ans += "...";
      break;
    }
    ans += s[i];
  }
  cout << ans << endl;
  return 0;
}
