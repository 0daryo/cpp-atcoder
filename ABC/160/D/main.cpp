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
#define INFTY 10000001
#define WHITE 0
#define GRAY 1
#define BLACK 2

#define N 100

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;
  vector<ll> ans(n);
  rep(sv, n)
  {
    vector<ll> dist(n, INF);
    queue<int> q;
    auto push = [&](int v, int d) {
      // svからの距離
      if (dist[v] != INF)
        return;
      dist[v] = d;
      q.push(v);
    };
    push(sv, 0);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      int d = dist[v];
      if (v - 1 >= 0)
        push(v - 1, d + 1);
      if (v + 1 < n)
        push(v + 1, d + 1);
      if (v == x)
        push(y, d + 1);
      if (v == y)
        push(x, d + 1);
    }
    // dist[i]は距離 ansは距離ごとの配列なので
    rep(i, n) ans[dist[i]]++;
  }
  rep(i, n) ans[i] /= 2;
  for (int i = 1; i <= n - 1; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}