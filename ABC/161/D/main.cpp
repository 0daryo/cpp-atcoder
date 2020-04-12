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
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main()
{
  ll k;
  vector<ll> lunlun;
  map<int, vector<ll>> lunvec;
  cin >> k;
  k--;
  rep(i, 10)
  {
    if (i == 0)
      continue;
    lunlun.push_back(i);
    lunvec[1].push_back(i);
  }
  ll ans = 0;
  int keta = 1;
  while (1)
  {
    if (k < lunlun.size())
    {
      ans = lunlun[k];
      break;
    }
    if (keta == 1)
    {
      keta++;
      continue;
    }
    vector<ll> old = lunvec[keta - 1];
    rep(i, old.size())
    {
      ll target = old[i];
      int matsubi = target % 10;
      for (int i = -1; i <= 1; i++)
      {
        if (matsubi + i < 0 || 9 < matsubi + i)
          continue;
        lunvec[keta].push_back(10 * target + matsubi + i);
        lunlun.push_back(10 * target + matsubi + i);
      }
    }
    keta++;
  }
  cout << ans << "\n";
  return 0;
}
