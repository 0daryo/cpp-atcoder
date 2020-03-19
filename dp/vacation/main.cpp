#include <algorithm>     //sort,二分探索,など
#include <bitset>        //固定長bit集合
#include <cmath>         //pow,logなど
#include <complex>       //複素数
#include <deque>         //両端アクセスのキュー
#include <functional>    //sortのgreater
#include <iomanip>       //setprecision(浮動小数点の出力の誤差)
#include <iostream>      //入出力
#include <map>           //map(辞書)
#include <numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include <queue>         //キュー
#include <set>           //集合
#include <stack>         //スタック
#include <string>        //文字列
#include <unordered_map> //イテレータあるけど順序保持しないmap
#include <unordered_set> //イテレータあるけど順序保持しないset
#include <utility>       //pair
#include <vector>        //可変長配列

using namespace std;
typedef long long ll;

//マクロ
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

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

// int N;
// int K;
// long long a[10010];
// long long b[10010];
// long long c[10010];
// long long dp[3][100010];
// int main()
// {
//   cin >> N;
//   for (int i = 0; i < N - 1; i++)
//   {
//     cin >> a[i];
//     cin >> b[i];
//     cin >> c[i];
//   }
//   for (int i = 0; i < 3; i++)
//   {
//     for (int j = 0; j < N; j++)
//     {
//       dp[i][j] = INF;
//     }
//   }
//   dp[0][0] = a[0];
//   dp[1][0] = b[0];
//   dp[2][0] = c[0];
//   for (int i = 1; i < N; i++)
//   {
//     dp[0][i] = max(dp[1][i - 1] + a[i - 1], dp[2][i - 1] + a[i - 1]);
//     dp[1][i] = max(dp[0][i - 1] + b[i - 1], dp[2][i - 1] + b[i - 1]);
//     dp[2][i] = max(dp[0][i - 1] + c[i - 1], dp[1][i - 1] + c[i - 1]);
//   }
//   ll a = dp[0][N - 1];
//   ll b = dp[1][N - 1];
//   ll c = dp[2][N - 1];
//   if (a >= b && a >= c)
//   {
//     cout << a << endl;
//   }
//   else if (a <= b && b >= c)
//   {
//     cout << b << endl;
//   }
//   else
//   {
//     cout << c << endl;
//   }
//   return 0;
// }

// 入力
int N;
long long a[100010][3]; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう

// DP テーブル
long long dp[100010][3];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> a[i][j];

  // 初期化は既に 0 に初期化される
  // 初期条件も既に 0 で OK

  // ループ
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      for (int k = 0; k < 3; ++k)
      {
        if (j == k)
          continue;
        chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  // 答え
  long long res = 0;
  for (int j = 0; j < 3; ++j)
    chmax(res, dp[N][j]);
  cout << res << endl;
}