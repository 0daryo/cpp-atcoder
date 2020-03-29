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

int n, M[100][100];
void dijkstra()
{
  int minv;
  int d[MAX], color[MAX];

  rep(i, n)
  {
    d[i] = INFTY;
    color[i] = WHITE;
  }
  d[0] = 0;
  color[0] = GRAY;
  while (1)
  {
    minv = INFTY;
    int u = -1;
    rep(i, n)
    {
      if (minv > d[i] && color[i] != BLACK)
      {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1)
      break;
    color[u] = BLACK;
    for (int v = 0; v < n; v++)
    {
      if (color[v] != BLACK && M[u][v] != INFTY)
      {
        if (d[v] > d[u] + M[u][v])
        {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
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