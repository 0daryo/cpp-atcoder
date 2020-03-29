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
typedef pair<int, int> P;

//マクロ
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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

int g[15][15];
int main()
{
  int n;
  cin >> n;
  rep(i, n) rep(j, n) g[i][j] = -1;
  rep(i, n)
  {
    int m;
    cin >> m;
    rep(j, m)
    {
      int a, x;
      cin >> a >> x;
      a--;
      g[i][a] = x;
    }
  }
  int ans = 0;
  // 二乗
  rep(i, 1 << n)
  {
    vector<int> d(n);
    rep(j, n) if (i >> j & 1)
    {
      d[j] = 1;
    }
    bool ok = true;
    rep(j, n)
    {
      if (d[j])
      {
        rep(k, n)
        {
          if (g[j][k] == -1)
            continue;
          if (g[j][k] != d[k])
            ok = false;
        }
      }
    }
    if (ok)
      ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << "\n";
  return 0;
}