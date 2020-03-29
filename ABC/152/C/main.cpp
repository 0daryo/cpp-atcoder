#include <bits/stdc++.h>
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
  cout << counter << endl;
}