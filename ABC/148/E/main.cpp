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

// 10で何回割れるかは、min(2で何回割れるか, 5で何回割れるか)
ll f(ll n)
{
  if (n < 2)
  {
    return 1;
  }
  return n * f(n - 2);
}

ll g1(ll n, int p)
{
  if (n == 0)
    return 0;
  return n / p + g1(n / p, p);
}

ll g2(ll n, int p)
{
  if (n % 2 == 1)
  {
    return g1(n, p) - g2(n - 1, p);
  }
  ll res = g1(n / 2, p);
  if (p == 2)
  {
    res += n / 2;
  }
  return res;
}

int main()
{
  ll n;
  cin >> n;
  ll ans = min(g2(n, 2), g2(n, 5));
  cout
      << ans << "\n";
  return 0;
}