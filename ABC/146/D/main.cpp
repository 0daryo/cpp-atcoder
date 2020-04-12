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

struct Edge
{
  ll to, id;
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(ll v, ll c = -1, ll p = -1)
{
  int k = 1;
  rep(i, g[v].size())
  {
    ll u = g[v][i].to;
    ll ei = g[v][i].id;
    // 親以外の辺
    if (u == p)
      continue;
    // 親の数字ならインクリメント
    if (k == c)
      k++;
    ans[ei] = k;
    k++;
    // 自身が親になる
    dfs(u, ans[ei], v);
  }
}

int main()
{
  int n;
  cin >> n;
  g.resize(n);
  ans = vector<int>(n - 1);
  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back((Edge){b, i});
    g[b].push_back((Edge){a, i});
  }
  dfs(0);
  int mx = 0;
  rep(i, n) mx = max(mx, int(g[i].size()));
  cout << mx << endl;
  rep(i, n - 1)
  {
    cout << ans[i] << endl;
  }
  return 0;
}

// int main()
// {
//   ll n;
//   cin >> n;
//   vector<vector<ll>> e(n);
//   map<ll, ll> mp;
//   ll maxColor = 0;
//   rep(i, n - 1)
//   {
//     ll a, b;
//     cin >> a >> b;
//     a--;
//     b--;
//     e[a].push_back(i);
//     e[b].push_back(i);
//   }
//   ll ma = 0;
//   rep(i, n)
//   {
//     ll cannotUse = 0;
//     ll now = 1;
//     for (const auto &e : e[i])
//     {
//       // すでに存在
//       if (mp.count(e) != 0)
//       {
//         cannotUse = e;
//       }
//       else
//       {
//         if (now == cannotUse)
//         {
//           now++;
//         }
//         mp[e] = now;
//         if (ma < now)
//         {
//           ma = now;
//         }
//         now++;
//       }
//     }
//   }
//   cout << ma << "\n";
//   auto begin = mp.begin(), end = mp.end();
//   for (auto iter = begin; iter != end; iter++)
//   {
//     cout << iter->second << "\n";
//   }
//   return 0;
// }