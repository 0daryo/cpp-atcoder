#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

vector<string> split(const string &s, char delim)
{
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim))
  {
    if (!item.empty())
    {
      elems.push_back(item);
    }
  }
  return elems;
}

int main()
{
  ll ans = 0;
  string s;
  while (getline(cin, s))
  {
    vector<string> ss = split(s, ' ');
    rep(i, ss.size())
    {
      if (isupper(ss[i][0]) || isdigit(ss[i][0]))
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
