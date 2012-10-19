#include <stdio.h>

unsigned long long dp[10000];
int val[22];

void precomp1()
{
		int i;
		for (i = 1; i < 22; i++)
				val[i] = i*i*i;
}

void precomp2()
{
		int i, j;

		dp[0] = 1;

		for (i = 1; i < 22; i++)
				for (j = 1; j < 10000; j++)
						if (j >= val[i])
								dp[j] += dp[j-val[i]];
}

int main(void)
{
		int n = 0;
		precomp1();
		precomp2();

		while (scanf("%d", &n) == 1)
				printf("%llu\n", dp[n]);

		return 0;
}

