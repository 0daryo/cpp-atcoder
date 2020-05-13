#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;

// ====================================================================

int main()
{
  string s;
  cin >> s;
  vector<vector<ll>> dp(s.size(), vector<ll>(13, 0));

  // 1行目を初期化する
  if (s[0] == '?')
    for (int i = 0; i < 10; i++)
      dp[0][i] = 1;
  else
    dp[0][s[0] - '0'] = 1;

  // 配るDPをしていく
  for (int k = 0; k < s.size() - 1; k++)
  {
    if (s[k + 1] == '?')
    { // 次の文字が自由に決められる
      for (int i = 0; i < 13; i++)
      {
        for (int j = 0; j < 10; j++)
        { // 全ての文字を試す
          dp[k + 1][(i * 10 % 13 + j) % 13] += dp[k][i];
          dp[k + 1][(i * 10 % 13 + j) % 13] %= MOD;
        }
      }
    }
    else
    { // 次の文字が指定されている
      for (int i = 0; i < 13; i++)
      {
        dp[k + 1][(i * 10 % 13 + (s[k + 1] - '0')) % 13] += dp[k][i];
        dp[k + 1][(i * 10 % 13 + (s[k + 1] - '0')) % 13] %= MOD;
      }
    }
  }
  cout << dp[s.size() - 1][5] << endl;
}