#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for (auto &i : mp)
#define sz(x) int(x.size())
#define INF 1000000000000

// vector<ll> heiro;
// vector<ll> to;

// void f(ll now, ll last)
// {
//   ll next = to[now];
//   if (next >= last)
//   {
//     return;
//   }
//   heiro.push_back(now);
//   f(next, last);
// }

// int main()
// {
//   ll n, k;
//   cin >> n >> k;
//   to.resize(n);
//   vector<ll> steps;
//   rep(i, n)
//   {
//     ll in;
//     cin >> in;
//     to[i] = in;
//   }
//   vector<ll> visitedStep(n, -1);
//   visitedStep[0] = 0;
//   ll step = 0;
//   ll now = 0;
//   ll heirofirst = 0;
//   while (1)
//   {
//     steps.push_back(now);
//     ll next = to[now];
//     if (visitedStep[next] != -1)
//     {
//       heirofirst = visitedStep[next];

//       f(visitedStep[next], next);
//       break;
//     }
//     if (step == k)
//     {
//       break;
//     }
//     visitedStep[now] = step;
//     now = next;
//     step++;
//   }
//   if (heiro.size() == 0)
//   {
//     cout << now + 1 << endl;
//   }
//   else
//   {
//     ll tmpk = k - now;
//     ll idx = tmpk % heiro.size();
//     cout << heiro[idx] + 1 << endl;
//   }
//   return 0;
// }

int main()
{
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> s;
  vector<int> ord(n + 1, -1);
  int c = 1;
  int l = 0;
  {
    int v = 1;
    while (ord[v] == -1)
    {
      ord[v] = s.size();
      s.push_back(v);
      v = a[v - 1];
    }
    c = s.size() - ord[v];
    l = ord[v];
  }
  if (k < l)
  {
    cout << s[k] << endl;
  }
  else
  {
    k -= l;
    k %= c;
    cout << s[l + k] << endl;
  }
  return 0;
}