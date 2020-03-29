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
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1001001001
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h)
  cin >> s[i];
  int ans = 0;
  REP(si, h)
  REP(sj, w)
  {
    if (s[si][sj] == '#')
      continue;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<P> q;
    auto update = [&](int i, int j, int x) {
      if (dist[i][j] != INF)
        return;
      dist[i][j] = x;
      q.push(P(i, j));
    };
    update(si, sj, 0);
    while (!q.empty())
    {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      REP(dir, 4)
      {
        int ni = i + di[dir], nj = j + dj[dir];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w)
          continue;
        if (s[ni][nj] == '#')
        {
          continue;
        }
        update(ni, nj, dist[i][j] + 1);
      }
    }
    REP(i, h)
    REP(j, w)
    {
      if (dist[i][j] == INF)
        continue;
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}