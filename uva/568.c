#include <stdio.h>

int dp[10001];
int solve(int n)
{
    int i, t;
    if (dp[n])
      return dp[n] % 10;
      
    dp[0] = dp[1] = 1;
    for (i = 2; i <= n; i++)
    {
        if (dp[i])
          continue;
        
        t = i * dp[i-1];
        while (t % 10 == 0)
          t /= 10;
        
        dp[i] = t % 100000;
    }
    
    return dp[n] % 10;
}

int main(void)
{
    int n = 0;
    while (scanf("%d", &n) == 1)
        printf("%5d -> %d\n", n, solve(n));
    
    return 0;
}
