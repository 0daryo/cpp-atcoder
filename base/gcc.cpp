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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

int hoge()
{
  return 3;
}
int main()
{
  int N;
  cin >> N;
  vi P(N);
  rep(i, N) cin >> P.at(i);
  int minimum = N + 1;
  int counter = 0;
  rep(i, N)
  {
    if (minimum > P.at(i))
    {
      counter++;
      minimum = P.at(i);
    }
  }
  cout << hoge() << endl;
}
