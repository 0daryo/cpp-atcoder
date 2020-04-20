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
const int mod = 1e+9 + 7;

//マクロ
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  ll ans = 0;
  // 桁を全部試す
  // AiとAjのk桁目を試す
  // ２進数で表した時の桁ごとの総和
  // 1から60桁目までのk桁目までについて、0の個数*1の個数*2^k
  rep(i, 60)
  {
    // i桁目が1である個数をx
    ll x = 0;
    rep(j, n) if (a[j] >> i & 1) x++;
    ll y = n - x;
    ll now = x * y % mod;
    // x*y*2^k
    rep(j, i) now = now * 2 % mod;
    ans += now;
    ans %= mod;
  }
  cout << ans << endl;
}