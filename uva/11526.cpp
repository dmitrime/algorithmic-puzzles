#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define size() sz
#define push_back pb
using namespace std;

int main()
{
  int N = 0;
  scanf("%d", &N);
  while (N--)
  {
    int n = 0;
    scanf("%d", &n);

    long long res = 0;
    //int q = int(floor(sqrt(double(n))));
    //int qq = int(ceil(sqrt(double(n))));
    int qqq = int(sqrt(double(n)));
    for (int i = 1; i <= qqq; i++) {
      res = res + n/i;
      res = res + i * (n/i - max(qqq, n/(i+1)) );
    }
    

    //long long res1 = 0;
    //for (int i = 1; i <= n; i++) {
    //  res1 = (res1 + n/i);
    //}

    printf("%lld\n", res);
    //printf("res1 = %lld\n", res1);
  }

  return 0;
}

