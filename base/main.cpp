#include <vector> // vectorを使うためにインクルードする
#include <iostream>
using namespace std;
int main()
{
  vector<int> vc; // <T>でT型のvector
  int n;
  cin >> n;
  while (n--)
  {
    int x;
    cin >> x;
    vc.push_back(x);
  }
  sort(vc.begin(), vc.end());
  for (int i = 0; i < vc.size(); i++)
    cout << vc[i] << endl;
}