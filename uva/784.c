#include <stdio.h>
#include <string.h>

char maze[31][85];
int row = 0, col = 0;
void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= row)
      return;
    if (maze[i][j] == '\0' || maze[i][j] != ' ' || maze[i][j] == '\n')
      return;
    
    maze[i][j] = '#';
    
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
}

int main(void)
{
    int N;
    int i;
    int j, k;
    char buf[81];
    
    fgets(buf, sizeof buf, stdin);
    sscanf(buf, "%d", &N);
    
    for (i = 0; i < N; i++)
    {
        row = 0;
        while (fgets(buf, sizeof buf, stdin) != NULL)
        {
            if (buf[0] == '_')
              break;
            col = 0;
            while (buf[col] != '\0')
            {
                if (buf[col] == '*')
                {
                    j = row;
                    k = col;
                }
                
                maze[row][col] = buf[col];
                col++;
            }
            maze[row][col] = '\0';
            row++;
        }
        
        maze[j][k] = ' ';
        dfs(j, k);
        for (j = 0; j < row; j++)
        {
            k = 0;
            while (maze[j][k] != '\0')
              putchar(maze[j][k++]);
        }
        printf("%s", buf);
    }
    
    return 0;
}
