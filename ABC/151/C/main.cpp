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
#define pb push_back
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef unsigned long long ull;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int N, M;
// ll WA[100010];
bool AC[100010];
int main()
{
  cin >> N >> M;
  // rep(i, 10010)
  // {
  //   WA[i] = 0;
  // }
  ll ac, wa;
  rep(i, 10010)
  {
    AC[i] = false;
  }
  rep(i, M)
  {
    int p;
    string result;
    cin >> p >> result;
    p--;
    if (result == "AC")
    {
      if (!AC[p])
      {
        ac++;
      }
      AC[p] = true;
    }
    else
    {
      if (!AC[p])
      {
        wa++;
      }
    }
  }
  cout << ac << " " << wa << endl;
}