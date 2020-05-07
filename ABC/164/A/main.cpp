#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  int s, w;
  cin >> s >> w;
  if (s <= w)
  {
    cout << "unsafe" << endl;
  }
  else
  {
    cout << "safe" << endl;
  }
  return 0;
}
