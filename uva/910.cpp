#include <iostream>
#include <cstring>
using namespace std;

struct carp
{
  int s, e1, e2, spec;
};

int dp[50][50];
carp pos[50];
int main()
{
  int N;
  while (cin >> N)
  {
    memset(dp, 0, sizeof dp);
    memset(pos, 0, sizeof pos);

    for (int i = 0; i < N; i++)
    {
      char a, b, c, d;
      cin >> a >> b >> c >> d;
      pos[i].s = a-'A';
      pos[i].e1 = b-'A';
      pos[i].e2 = c-'A';

      pos[i].spec = 0;
      if (d == 'x')
	pos[i].spec = 1;
    }
    int m;
    cin >> m;


    dp[1][pos[0].e1] = 1;
    dp[1][pos[0].e2] = 1;

    for (int i = 1; i <= m; i++)
      for (int k = 0; k < N; k++)
      {
	dp[i+1][pos[k].e1] += dp[i][pos[k].s];
	dp[i+1][pos[k].e2] += dp[i][pos[k].s];
      }
    int sum = 0;
    for (int k = 0; k < N; k++)
      if (pos[k].spec)
	sum += dp[m][pos[k].s];

    cout << sum << endl;

  }
  return 0;
}

