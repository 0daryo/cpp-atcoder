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

static const int MAX = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int INFTY = (1 << 21);

struct edge
{
  int to, cost;
};
typedef pair<int, int> P; // 最短距離、頂点番号
// 最短経路
int d[INF];
// start
int s;
vector<edge> G[INF];
int n, M[100][100];
void dijkstra()
{
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + n, INF);
  d[s] = 0;
  que.push(P(0, s));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
    {
      continue;
    }
    for (int i = 0; i < G[v].size(); i++)
    {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost)
      {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  rep(i, n)
  {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

// in
// 5
// 0 3 2 3 3 1 1 2
// 1 2 0 2 3 4
// 2 3 0 3 3 1 4 1
// 3 4 2 1 0 1 1 4 4 3
// 4 2 2 1 3 3
int main()
{
  cin >> n;
  rep(i, n) rep(j, n) M[i][j] = INFTY;
  int k, c, u, v;
  rep(i, n)
  {
    cin >> u >> k;
    for (int j = 0; j < k; j++)
    {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra();
  return 0;
}