#include <iostream>
using namespace std;

int modPow(long long a, long long n, long long p)
{
  if (n == 1)
    return a % p;
  if (n % 2 == 1)
    return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}