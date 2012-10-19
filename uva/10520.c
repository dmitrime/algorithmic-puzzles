#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)

long long dp[21][21];

long long go(int n, int i, int j)
{
		long long m = 0;
		int k = 0;

		if (dp[i][j] != -1)
				return dp[i][j];

		if (i >= j)
		{
				if (i == n)
						dp[i][j] = 0;
				else if (i < n)
				{
						for (k = i+1; k <= n; k++)
								m = max(go(n,k,1)+go(n,k,j), m);

						dp[i][j] = m;
				}

				if (j > 0)
				{
						m = 0;
						for (k = 1; k < j; k++)
								m = max(go(n,i,k)+go(n,n,k), m);

						dp[i][j] += m;
				}
		}
		else
		{
				for (k = i; k < j; k++)
						m = max(go(n,i,k)+go(n,k+1,j), m);

				dp[i][j] = m;
		}

		return dp[i][j];
}

int main(void)
{

		int n, a;
		while (scanf("%d %d", &n, &a) == 2)
		{
				memset(dp, -1, sizeof dp);
				dp[n][1] = a;

				printf("%lld\n", go(n, 1, n));
		}

		return 0;
}

