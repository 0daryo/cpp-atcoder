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

int N;
long long h[100010];
long long dp[100010];

// iまでの最小の行き方を返す
long long rec(int i)
{
  if (dp[i] < INF)
  {
    return dp[i];
  }
  if (i == 0)
  {
    return 0;
  }
  long long res = INF;
  if (i == 1)
  {
    res = rec(i - 1) + abs(h[i] - h[i - 1]);
  }
  else
  {
    res = min(rec(i - 1) + abs(h[i] - h[i - 1]), rec(i - 2) + abs(h[i] - h[i - 2]));
  }
  dp[i] = res;
  return res;
}

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> h[i];
  for (int i = 0; i < 100010; ++i)
    dp[i] = INF;
  cout << rec(N - 1) << endl;
  return 0;
}