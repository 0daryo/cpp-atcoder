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
// 0, 1,2
int r, s, p;
ll calcHand(ll opposite, ll you)
{
  if (opposite == 0 && you == 2)
  {
    return p;
  }
  if (opposite == 1 && you == 0)
  {
    return r;
  }
  if (opposite == 2 && you == 1)
  {
    return s;
  }
  return 0;
}
ll getHand(char h)
{
  if (h == "r"[0])
  {
    return 0;
  }
  if (h == "s"[0])
  {
    return 1;
  }
  if (h == "p"[0])
  {
    return 2;
  }
  return 0;
}

int main()
{
  ll n, k;
  string t;
  ll ans = 0;
  cin >> n >> k >> r >> s >> p >> t;
  map<int, vector<int>> modk;
  rep(i, n)
  {
    int c = getHand(t[i]);
    modk[i % k].push_back(c);
  }
  for (pair<int, vector<int>> p : modk)
  {
    ll modKMax;
    ll siz = p.second.size();
    vector<ll> dpR(siz + 1);
    vector<ll> dpS(siz + 1);
    vector<ll> dpP(siz + 1);
    dpR[0] = 0;
    dpS[0] = 0;
    dpP[0] = 0;
    rep(i, siz)
    {
      dpR[i + 1] = max(dpS[i] + calcHand(p.second[i], 0), dpP[i] + calcHand(p.second[i], 0));
      dpS[i + 1] = max(dpR[i] + calcHand(p.second[i], 1), dpP[i] + calcHand(p.second[i], 1));
      dpP[i + 1] = max(dpS[i] + calcHand(p.second[i], 2), dpR[i] + calcHand(p.second[i], 2));
    }
    modKMax = max(dpR[siz], dpS[siz]);
    modKMax = max(modKMax, dpP[siz]);
    ans += modKMax;
  }

  cout << ans << "\n";
  return 0;
}