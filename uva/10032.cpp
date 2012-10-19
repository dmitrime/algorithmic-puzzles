#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int p[101];
long long dp[45001];
int solve(int s, int mm)
{
    int i, k;
    int m = mm/2;
    int diff = s;
    int best = 0;
    
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    
    
    for (i = 0; i < mm; i++)
      for (k = s; k >= p[i]; k--)
        if (dp[k-p[i]])
        {
          dp[k] |= (dp[k-p[i]] << 1); 
          if (dp[k] & (1LL << m))
          {
                if (diff > abs(s-k-k))
                {
                    diff = abs(s-k-k);
                    best = k;
                }
          }
        }
        
    return min(best, s-best);
}

int main()
{
		int N;
		cin >> N;

		while (N--)
		{
				int m;
				int sum = 0;

				cin >> m;
				for (int i = 0; i < m; i++)
				{
						cin >> p[i];
						sum += p[i];
				}
				
				int res = solve(sum, m);
				cout << res << " " << (sum-res) << endl;

				if (N)
					cout << endl;
		}

		return 0;
}

