#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  ll n;
  cin >> n;
  set<string> st;
  rep(i, n)
  {
    string in;
    cin >> in;
    st.insert(in);
  }
  cout << st.size() << endl;
  return 0;
}
