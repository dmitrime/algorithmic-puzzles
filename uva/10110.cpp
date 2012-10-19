#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;

int main()
{

  ULL n;

  while (cin >> n)
  {
    if (n == 0)
      break;

    ULL t = ULL(sqrt(double(n)));
    if (t*t == n)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}

