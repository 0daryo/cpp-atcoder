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
#define INF 10000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, vector<int>> mp;
  rep(i, n)
  {
    mp[s[i]].push_back(i);
  }
  string sample = "RGB";
  vector<int> r = mp[sample[0]];
  vector<int> g = mp[sample[1]];
  vector<int> b = mp[sample[2]];
  ll ans = 0;
  rep(i, r.size())
  {
    int R = r[i];
    rep(j, g.size())
    {
      int G = g[j];
      int mx, mn, md;
      md = INF;
      int tmpMx = max(R, G);
      int tmpMn = min(R, G);
      mx = tmpMx + tmpMx - tmpMn;
      mn = max(tmpMn - (tmpMx - tmpMn), 0);
      if ((tmpMx + tmpMn) % 2 == 0)
      {
        md = (tmpMn + tmpMx) / 2;
      }
      rep(k, b.size())
      {
        if (b[k] == mn || b[k] == mx || b[k] == md)
        {
          continue;
        }
        ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}