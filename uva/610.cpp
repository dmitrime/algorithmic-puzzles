#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int G[1003][1003];
int Dnum[1003];
int Num;

int dfs(int s, int p, int n)
{
  Dnum[s] = Num++;
  int la = Dnum[s];

  for (int i = 1; i <= n; i++) if (G[s][i] && i != p) {
    if (Dnum[i] == 0)
    {
      //cout << "Deleting " << i << "-" << s << endl;
      G[i][s] = 0;

      int r = dfs(i, s, n);

      if (Dnum[s] < r)
      {
	//cout << "Fixing " << i << "-" << s << endl;
	G[i][s] = 1;
      }

      la = min(la, r);
    }
    else
    {
      //cout << "Deleting from back " << i << "-" << s << endl;
      G[i][s] = 0;
      la = min(Dnum[i], la);
    }
  }

  return la;
}

void print(int n)
{
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (G[i][j])
	cout << i << " " << j << endl;
}

void solve(int n, int m)
{
  dfs(1, 1, n);

  print(n);
}

int main()
{
  int n, m;
  int incase = 1;
  n = m = 0;

  while (true)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    
    memset(G, 0, sizeof G);
    memset(Dnum, 0, sizeof Dnum);
    Num = 1;

    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      G[x][y] = 1; G[y][x] = 1;
    } 
    cout << incase << endl << endl;
    solve(n, m);
    cout << '#' << endl;

    incase++;
  }
  return 0;
}

