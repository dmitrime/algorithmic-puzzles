#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
int cc[41][2];
int dp[301][301];

int cost(int m, int w)
{
		int i, j, k;
		int ret = 9999999;

		dp[0][0] = 0;
		for (i = 0; i <= w; i++)
				for (j = 0; j <= w; j++)
						for (k = 0; k < m; k++)
								if (i >= cc[k][0] && j >= cc[k][1])
								{
										dp[i][j] = min(1 + dp[i-cc[k][0]][j-cc[k][1]] , dp[i][j]);

										if (i*i +j*j == w*w)
												ret = min(ret, dp[i][j]);
								}

		return ret;
}

int main(void)
{
		int n = 0;
		int m, s, res;
		int i, j;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
				memset(cc, 0, sizeof cc);
				memset(dp, 0x7F, sizeof dp);

				scanf("%d %d", &m, &s);

				for (j = 0; j < m; j++)
						scanf("%d %d", &cc[j][0], &cc[j][1]);

				res = cost(m, s);
				if (res > 999)
						printf("not possible\n");
				else
						printf("%d\n", res);
		}

		return 0;
}

