#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

vector<int> split(const string &s, char delim)
{
  vector<int> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim))
  {
    if (!item.empty())
    {

      elems.push_back(stoi(item));
    }
  }
  return elems;
}

int main()
{
  string s;
  cin >> s;
  vector<int> ss = split(s, ',');
  string ans = "";
  rep(i, ss.size())
  {
    if (i == 0)
    {
      continue;
    }
    if (i % 2 == 1 || ss[i - 1] == ss[i])
    {
      ans += to_string(ss[i]);
      ans += ",";
    }
  }
  string output = "";
  rep(i, ans.size())
  {
    if (i == ans.size() - 1)
    {
      break;
    }
    output += ans[i];
  }
  cout << output << endl;
  return 0;
}
