#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  int n;
  cin >> n;
  int an, bn;
  vector<int> num(n), a(n), b(n);
  rep(i, n)
  {
    num[i] = i + 1;
  }
  rep(i, n)
  {
    int in;
    cin >> in;
    a[i] = in;
  }
  rep(i, n)
  {
    int in;
    cin >> in;
    b[i] = in;
  }
  int count = 1;
  do
  {
    if (num == a)
    {
      an = count;
    }
    if (num == b)
    {
      bn = count;
    }
    count++;
  } while (next_permutation(num.begin(), num.end()));
  cout << abs(an - bn) << endl;
  return 0;
}