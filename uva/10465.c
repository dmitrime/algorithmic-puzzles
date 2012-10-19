#include <stdio.h>
#include <string.h>

#define min(a, b) (a) < (b) ? (a) : (b)

int dp[10000];
int a[2];
int drink;
int knap(int s)
{ 
    int i;
    
    dp[a[0]] = 1;
    dp[a[1]] = 1;
    
    for (i = min(a[1], a[0]); i <= s; i++)
    {
        if (i >= a[0]) if (dp[i-a[0]]) if (dp[i-a[0]]+1 > dp[i]) dp[i] = dp[i-a[0]]+1;
        if (i >= a[1]) if (dp[i-a[1]]) if (dp[i-a[1]]+1 > dp[i]) dp[i] = dp[i-a[1]]+1;
    }
    
    /*
    for (i = 0; i <= s; i++)
      printf("%d ", dp[i]);
    printf("\n");
    */
    
    drink = 0;
    if (!dp[s])
    {
      while (s > 0 && !dp[s])
        drink++, s--;
    }
          
    return dp[s];
}

int main(void)
{
    int s;
    int res = 0;
    
    while (scanf("%d %d %d", &a[0], &a[1], &s) == 3)
    {
        memset(dp, 0, sizeof dp);
        res = knap(s);
        
        printf("%d", res);
        if (drink != 0)
          printf(" %d", drink);
        printf("\n");
    }
        
    return 0;
}
