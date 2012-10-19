#include <stdio.h>
#include <string.h>

#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))

int p[101];
long long dp[45001];
int solve(int s, int m)
{
    int i, j;
    int diff = s;
    int best = 0;
    int mm = m/2;
    
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    
    for (i = 0; i < m; i++)
      for (j = s; j >= p[i]; j--)
        if (dp[j-p[i]])
        {
            dp[j] |= (dp[j-p[i]] << 1);
            if (dp[j] & 1LL << (mm))
              if (diff > abs(s-j-j))
                diff = abs(s-j-j), best = j;
        }
    return min(s-best, best);
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    
    while (N--)
    {
        int m, i, res;
        int sum = 0;
        
        scanf("%d", &m);
        for (i = 0; i < m; i++)
        {
            scanf("%d", p+i);
            sum += p[i];
        }
        
        res = solve(sum, m);
        
        printf("%d %d\n", res, sum-res);
        
        if (N)
          putchar('\n');
    }
    
    return 0;
}

