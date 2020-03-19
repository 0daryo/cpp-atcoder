#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // エラトステネスのふるい
  // 総数を見つけたらそれ以降のその倍数全てをふるい落す
  int MAX = 101010;
  vector<int> is_prime(MAX, 1);
  is_prime[0] = 0, is_prime[1] = 0;
  for (int i = 2; i < MAX; ++i)
  {
    if (!is_prime[i])
      continue;
    for (int j = i * 2; j < MAX; j += i)
      is_prime[j] = 0;
  }

  // 2017-like 数かどうか
  vector<int> a(MAX, 0);
  for (int i = 0; i < MAX; ++i)
  {
    if (i % 2 == 0)
      continue;
    if (is_prime[i] && is_prime[(i + 1) / 2])
      a[i] = 1;
  }

  // 累積和
  vector<int> s(MAX + 1, 0);
  for (int i = 0; i < MAX; ++i)
    // ただの漸化式
    // s[i+1]はi番目までの和なので最後のクエリで+1
    s[i + 1] = s[i] + a[i];

  // クエリ処理
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; ++q)
  {
    int l, r;
    cin >> l >> r;
    cout << s[r + 1] - s[l] << endl;
  }
}