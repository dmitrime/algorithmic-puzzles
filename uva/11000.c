#include <stdio.h>
unsigned dp[128][2];

void go(int N)
{
    int i;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for ( i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + 1;
    }
}

int main(void)
{
    int n;
    go(127);
    
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
          break;
        printf("%u %u\n", dp[n][0], dp[n][0]+dp[n][1]);
    }
    
    return 0;
}
