#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
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
    int k = 0;
    scanf("%d", &k);

    set<int> s;
    for (int i = 1; i <= k; i++)
        s.insert(i);

    int x = 0;
    set<int>::iterator it;
    for (int i = 0; i < k; i++) {
      scanf("%d", &x);
      it = s.begin();
      for (int j = 0; j < x; j++, it++);

      printf("%d%c", *it, i == k-1 ? '\n' : ' ');
      s.erase(it);
    }
  }

  return 0;
}

