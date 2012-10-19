#include <stdio.h>
#include <string.h>

char M[101][101];
int m, n;

void dfs(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
      return;
    if (M[i][j] != '@')
      return;
    
    M[i][j] = '#';
    
    dfs(i+1, j+1); dfs(i, j+1); dfs(i, j-1); dfs(i+1, j); 
    dfs(i-1, j); dfs(i-1, j-1); dfs(i-1, j+1); dfs(i+1, j-1);
}

int main(void)
{
    int i, j;    
    int ret;
    while (1)
    {
        scanf("%d %d", &m, &n);
        if (m == 0)
          break;
          
        for ( i = 0; i < m; i++)
          scanf("%s", M[i]);
        
        ret = 0;
        for ( i = 0; i < m; i++)
          for ( j = 0; j < n; j++)
            if (M[i][j] == '@')
            {
              dfs(i, j);
              ret++;
            }
        printf("%d\n", ret);
    }
    
    return 0;
}
