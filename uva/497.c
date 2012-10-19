#include <stdio.h>
#include <string.h>

int targets[1024];
int results[1024];

int shoot(int N)
{
    int dp[1024];
    int pr[1024];
    int mi = 0;
    int mx = 0;
    int i, j;
    
    for (i = 0; i < N; i++)
    {
        dp[i] = 1;
        pr[i] = 0;
    }
    
    for ( i = 1; i < N; i++)
    {
        for ( j = 0; j < i; j++)
        {
            if (targets[i] > targets[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    pr[i] = j;
                    
                    if (dp[i] > mx) {mx = dp[i]; mi = i;}
                }
            }
        }
    }
    
    /*i = mi;
    j = 0;
    do
    {
      results[j++] = targets[i];
      i = pr[i];
    } while(pr[i] != 0);
    
    results[j] = targets[i];*/
    
    for (j = dp[mi]-1, i = mi; j >= 0; j--)
    {
        results[j] = targets[i];
        i = pr[i];
    }
    
    /*for (i = 0; i < j/2; i++)
    {
        int t = results[j-1-i];
        printf(" t = %d\n", t);
        results[j-1-i] = results[i];
        results[i] = t;
    }*/
    
    return dp[mi];
}

int main(void)
{
    char buf[32];
    int N = 0;
    int i, j, k;
    
    fgets(buf, sizeof buf, stdin);
    N = strtol(buf, NULL, 10);
    fgets(buf, sizeof buf, stdin);
    
    for (i = 0; i < N; i++)
    {
        memset(targets, 0, sizeof targets);
        memset(results, 0, sizeof results);
        j = 0;
        
        while (1)
        {
          if (fgets(buf, sizeof buf, stdin) == NULL)
            break;
        
          if ((k = strtol(buf, NULL, 10)) == 0)
            break;
          targets[j++] = k;
        }
        
        if (j)
        {
          int r = 0;
          printf("Max hits: %d\n", (r = shoot(j)) );
          for (k = 0; k < r; k++)
            printf("%d\n", results[k]);
        }
        else 
          printf("Max hits: 0\n");
        
        if (i != N-1)
          putchar('\n');
    
    }
    
    return 0;
}
