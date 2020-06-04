#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())

const double PI = acos(-1);

int main()
{
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double th = double(h * 60 + m) / 720 * 2 * PI;
  double tm = double(m) / 60 * 2 * PI;
  double xh = a * cos(th), yh = a * sin(th);
  double xm = b * cos(tm), ym = b * sin(tm);
  double dx = xh - xm, dy = yh - ym;
  double ans = sqrt(dx * dx + dy * dy);
  printf("%.10f\n", ans);
  return 0;
}
