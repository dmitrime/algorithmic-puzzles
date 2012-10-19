#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define size() sz
#define push_back pb
using namespace std;

char mat[15][15];
int vis[15][15];
void dfs(int i, int j, int m)
{
  if (i < 1 || j < 1 || i > m || j > m)
    return;

  if (vis[i][j])
    return;

  if (mat[i][j] == '.') {
    char mn = 'a';
    for (char p = 'A'; p <= 'Z'; p++) {
      if (mat[i-1][j] && mat[i-1][j] == p)
	continue;
      if (mat[i+1][j] && mat[i+1][j] == p)
	continue;
      if (mat[i][j-1] && mat[i][j-1] == p)
	continue;
      if (mat[i][j+1] && mat[i][j+1] == p)
	continue;
      mn = p;
      break;
    }
    mat[i][j] = mn;
  }
  vis[i][j] = 1;

  dfs(i+1,j,m);
  dfs(i-1,j,m);
  dfs(i,j-1,m);
  dfs(i,j+1,m);
}
int main()
{
  int N = 0;
  scanf("%d", &N);

  int cs = 1;
  while (cs <= N)
  {
    memset(mat, 0, sizeof mat);
    memset(vis, 0, sizeof vis);
    int m = 0;
    scanf("%d", &m);

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++) {
	char c;
	scanf("%c", &c);
	if (c == '\n' || c == ' ')
	  scanf("%c", &c);
	mat[i][j] = c;
      }

    dfs(1,1,m);

    printf("Case %d:\n", cs);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++)
	printf("%c", mat[i][j]);
      printf("\n");
    }
    cs++;
  }

  return 0;
}

