#include <iostream>
#include <string>

using namespace std;

int n;

// 何が帰って来ればいいか、
void dfs(string s, char mx)
{
  if (s.size() == n)
  {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++)
  {
    string t = s;
    t += c;
    // 今使ってる値と今までの最高のどっちか進んでる方
    dfs(t, max(mx, c));
  }
}

int main(void)
{
  cin >> n;
  dfs("", 'a' - 1);
  return 0;
}