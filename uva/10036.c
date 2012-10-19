#include <stdio.h>
#include <string.h>

char dp[201];
char clear[201];
int main(void)
{
    int n, m, k;
    int i, j, l;
    int a;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        memset(dp, 0x7F, sizeof dp);
        memset(clear, 0x7F, sizeof clear);
        scanf("%d %d", &m, &k);
        
        scanf("%d", &a);
        dp[100 + (a%k)] = (a%k);
        
        for (j = 1; j < m; j++)
        {
          scanf("%d", &a);
          for (l = 0; l < 201; l++)
          {
                if (dp[l] < 101)
                {
                    clear[100 + ((dp[l] + a) % k)] = (dp[l] + a) % k;
                    clear[100 + ((dp[l] - a) % k)] = (dp[l] - a) % k;       
                }
          }
          memcpy(dp, clear, sizeof clear);
          memset(clear, 0x7F, sizeof clear);
        }
        if (!dp[100])
          printf("Divisible\n");
        else
          printf("Not divisible\n");
          
    }
    
    return 0;
}
