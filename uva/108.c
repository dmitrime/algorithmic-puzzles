#include <stdio.h>

#define max(x, y) (x) > (y) ? (x) : (y)

int sums[101][101];
int inpt[101][101];

int calc(int N)
{
    int i, j, k, t;
    int mx;
    
    mx = sums[0][0] = inpt[0][0];
    for (i = 1; i < N; i++)
    {
      sums[i][0] = sums[i-1][0] + inpt[i][0];
      /*mx = mx > sums[i][0] ? mx : sums[i][0];
        mx = mx > inpt[i][0] ? mx : inpt[i][0];*/
    }
    
    for (j = 1; j < N; j++)
    {
        t = 0;
        for (k = 0; k < N; k++)
        {
          t += inpt[k][j];
          sums[k][j] = t + sums[k][j-1];
          /*mx = mx > sums[k][j] ? mx : sums[k][j];
            mx = mx > inpt[k][j] ? mx : inpt[k][j];*/
        }
    }
    
    for (i = 0; i < N; i++) /*main rows*/
    {
        for (j = 0; j < N; j++) /*main cols*/
        {
            mx = max(mx, sums[i][j]);
            for (k = 0; k < j; k++) /*temp cols*/
            {
                mx = max(mx, sums[i][j] - sums[i][k]);
                for (t = 0; t < i; t++) /*temp rows*/
                {
                    mx = max(mx, sums[i][j] - sums[t][j]);
                    mx = max(mx, sums[i][j] - sums[t][j] - sums[i][k] + sums[t][k]);
                }
            }
        }
    }
    
    /*
        printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
          printf("%d ", sums[i][j]);
        printf("\n");
    }
        printf("\n");
    */
    
    return mx;
}

int main(void)
{
    int N;
    int i, j;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
        scanf("%d", &inpt[i][j]);
        
    printf("%d\n", calc(N));
    
    return 0;
}
