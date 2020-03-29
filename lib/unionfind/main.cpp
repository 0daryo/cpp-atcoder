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
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
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

struct UnionFind
{
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x)
  {
    if (d[x] < 0)
      return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    // 根は負で管理している
    if (d[x] > d[y])
      swap(x, y);
    // x大きい方
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y)
  {
    return root(x) == root(y);
  }
  int size(int x)
  {
    return -d[root(x)];
  }
};