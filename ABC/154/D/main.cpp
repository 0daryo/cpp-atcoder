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

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> p, sum;
  rep(i, n)
  {
    ll tmp;
    cin >> tmp;
    p.push_back(tmp);
    if (i == 0)
    {
      sum.push_back(tmp);
      continue;
    }
    else
    {
      sum.push_back(sum[i - 1] + tmp);
    }
  }
  ll maxIdx = 0;
  ll mx = 0;
  rep(i, n - k + 1)
  {
    if (i == 0)
    {
      continue;
    }
    ll f = sum[i + k - 1] - sum[i - 1];
    if (f > mx)
    {
      mx = f;
      maxIdx = i;
    }
  }
  double ans = 0;
  ll start = maxIdx;
  ll end = maxIdx + k;
  for (ll i = start; i < end; i++)
  {
    double plus = (1 + p[i]) / 2.0;
    ans += plus;
  }
  printf("%.10f\n", ans);
  return 0;
}