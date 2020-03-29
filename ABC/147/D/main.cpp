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
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
  }

  long long res = 0;
  for (int d = 0; d < 60; ++d)
  {
    long long n0 = 0, n1 = 0;
    for (int i = 0; i < N; ++i)
    {
      if ((A[i] >> d) & 1)
        ++n1; // d 桁目が 1
      else
        ++n0; // d 桁目が 0
    }
    long long tmp = (1ll << d) % mod; // 2^d
    // B の要素 (xor 演算を施した数) で d 桁目が 1 である個数
    long long n = n0 * n1 % mod;
    // B の要素 (xor 演算を施した数) の d 桁目の総和 (= 2^d * n0 * n1)
    tmp = tmp * n % mod;
    res = (res + tmp) % mod;
  }
  cout << res << endl;
}