#include <bits/stdc++.h>

using namespace std;
std::ifstream ifs;
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

vector<int> splitInt(const string &s, char delim)
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
  string f;
  getline(cin, f);
  vector<string> subjects = split(f, ',');
  vector<int> scores(subjects.size(), 0);
  int num = 0;
  char s[100];
  string row;
  while (getline(cin, row))
  {
    vector<int> ss = splitInt(row, ',');
    rep(i, ss.size())
    {
      scores[i] += ss[i];
    }
    num++;
  }
  string ans = "";
  rep(i, scores.size())
  {
    scores[i] /= num;
    ans += scores[i];
    ans += ",";
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
  cout << f << endl;
  cout << output << endl;
  return 0;
}
