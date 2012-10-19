#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int dp[128][128];
char can[128][128];


void print(int rows, int cols)
{
    int i, j;
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= cols; j++)
          printf("%d\t", dp[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int N;
    char buf[128];
    
    fgets(buf, sizeof buf, stdin);
    sscanf(buf, "%d", &N);
    
    while (N--)
    {
        int rows, cols;
        int i, j;
        
        memset(dp, 0, sizeof dp);
        memset(can, 1, sizeof can);
        
        fgets(buf, sizeof buf, stdin);
        fgets(buf, sizeof buf, stdin);
        sscanf(buf, "%d %d", &rows, &cols);
        
        for (i = 0; i < rows; i++)
        {
            char *p = NULL;
            
            fgets(buf, sizeof buf, stdin);
            p = strtok(buf, " \t\n");
            
            while (1)
            {
                int xx;
                
                p = strtok(NULL, " \t\n");
                if (p == NULL)
                  break;
                  
                sscanf(p, "%d", &xx);
                can[i+1][xx] = 0;
            }
        }
        
          dp[1][0] = 1;
          for (i = 1; i <= rows; i++)
          {
            for (j = 1; j <= cols; j++)
              if (can[i][j])
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
          }
          
          /*print(rows, cols);*/
            
          printf("%d\n", dp[rows][cols]);
        
        if (N)
          printf("\n");
    }
    
    return 0;
}
