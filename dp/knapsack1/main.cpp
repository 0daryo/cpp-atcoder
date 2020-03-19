#include <iostream>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
const long long INF = 1LL << 60;

int N;
long long W, weight[110], value[110];

long long dp[110][100100] = {0};

int main()
{
  cin >> N >> W;
  for (int i = 0; i < N; i++)
  {
    cin >> weight[i] >> value[i];
  }
  for (int i = 0; i < N; i++)
  {
    for (int sum_w = 0; sum_w <= W; sum_w++)
    {
      if (sum_w - weight[i] < 0)
      {
        chmax(dp[i + 1][sum_w], dp[i][sum_w]);
        continue;
      }
      chmax(dp[i + 1][sum_w], dp[i][sum_w]);
      chmax(dp[i + 1][sum_w], dp[i][sum_w - weight[i]] + value[i]);
    }
  }
  cout << dp[N][W];
}