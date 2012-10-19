#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int winds[10][1001];
int dp[10][1001];
int X = 0;

int bestFlight()
{
		for (int i = 0; i < 10; i++)
				for (int j = 0; j < 1001; j++)
						dp[i][j] = 1234567899;


		dp[0][0] = 0;
		for (int x = 0; x < X; x += 100)
		{
				int a = x/100;
				for (int i = 0; i < 10; i++)
				{
						dp[i][a+1] = min(dp[i][a+1], dp[i][a] + 30 - winds[i][a]);
						if (i != 0)
								dp[i-1][a+1] = min(dp[i-1][a+1],   dp[i][a] + 20 - winds[i][a]);
						if (i != 9)
								dp[i+1][a+1] = min(dp[i+1][a+1],   dp[i][a] + 60 - winds[i][a]);
				}
		}

		return dp[0][X/100];
}

int main()
{
		int N = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
				cin >> X;
				for (int j = 9; j >= 0; j--)
						for (int k = 0; k < X; k += 100)
								cin >> winds[j][k/100];

				cout << bestFlight() << endl << endl;
		}

		return 0;
}
/*
#include <stdio.h>

#define MAX 10000000

int main()
{
		long i,j,k,t,num,cnt,tmp,map[10][1001],sum[10][1001];
		scanf("%ld",&cnt);
		for(t=0;t<cnt;t++)
		{
				scanf("%ld",&num);
				num/=100;
				for(i=0;i<10;i++)
				{
						for(j=0,sum[i][num]=MAX;j<num;j++)
						{
								scanf("%ld",&map[i][j]);
								map[i][j]=-map[i][j],sum[i][j]=MAX;
						}
				}
				for(i=0,sum[9][0]=0;i<num;i++)
				{
						for(j=1;j<10;j++)
								if(sum[j][i]+map[j][i]+60<sum[j-1][i+1])
										sum[j-1][i+1]=sum[j][i]+map[j][i]+60;
						for(j=0;j<9;j++)
								if(sum[j][i]+map[j][i]+20<sum[j+1][i+1])
										sum[j+1][i+1]=sum[j][i]+map[j][i]+20;
						for(j=0;j<10;j++)
								if(sum[j][i]+map[j][i]+30<sum[j][i+1])
										sum[j][i+1]=sum[j][i]+map[j][i]+30;
				}
				printf("%ld\n\n",sum[9][num]);
		}
}
*/
