#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

int main()
{
  int n;
  cin >> n;
  int last = n % 10;
  string ans;
  switch (last)
  {
  case 2 /* constant-expression */:
    /* code */
    ans = "hon";
    break;
  case 4 /* constant-expression */:
    /* code */
    ans = "hon";
    break;
  case 5 /* constant-expression */:
    /* code */
    ans = "hon";
    break;
  case 7 /* constant-expression */:
    /* code */
    ans = "hon";
    break;
  case 9 /* constant-expression */:
    /* code */
    ans = "hon";
    break;
  case 0 /* constant-expression */:
    /* code */
    ans = "pon";
    break;
  case 1 /* constant-expression */:
    /* code */
    ans = "pon";
    break;
  case 6 /* constant-expression */:
    /* code */
    ans = "pon";
    break;
  case 8 /* constant-expression */:
    /* code */
    ans = "pon";
    break;
  case 3 /* constant-expression */:
    /* code */
    ans = "bon";
    break;

  default:
    break;
  }
  cout << ans << endl;
  return 0;
}
