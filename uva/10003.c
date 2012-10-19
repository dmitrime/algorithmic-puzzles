#include <stdio.h>
#include <string.h>

int cc[55];
int dp[55][55];
int n;

int solve(int s, int e)
{
    int i, t;
    
    if (cc[e]-cc[s] <= 1)
      return 0;
    
    if (dp[s][e])
      return dp[s][e];
    
    for (i = 1; i <= n; i++)
    {
        if (cc[s] < cc[i] && cc[i] < cc[e])
        {
            t = cc[e]-cc[s] + solve(s, i) + solve(i, e);
            if (dp[s][e] == 0 || t < dp[s][e])
              dp[s][e] = t;
        }
    }
    
    return dp[s][e];
}

int main(void)
{
    int L;
    int i;
    while (1)
    {
        memset(dp, 0, sizeof dp);
        memset(cc, 0, sizeof cc);
        
        scanf("%d", &L);
        if (!L)
          break;
        scanf("%d", &n);
        
        for (i = 1; i <= n; i++)
          scanf("%d", &cc[i]);  
        cc[n+1] = L;
        
        printf("The minimum cutting is %d.\n", solve(0, n+1));
    }
    
    return 0;
}
