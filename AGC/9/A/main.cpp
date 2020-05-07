#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i] >> B[i];

  vector<long long> C(N + 1, 0);
  for (int i = N - 1; i >= 0; --i)
  {
    A[i] += C[i + 1];
    long long amari = A[i] % B[i];
    long long need = 0;
    if (amari != 0)
      need = B[i] - amari;
    C[i] = C[i + 1] + need;
  }
  cout << C[0] << endl;
}