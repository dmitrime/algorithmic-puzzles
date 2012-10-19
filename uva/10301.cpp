#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
  double x;
  double y;
  double r;
};

Point pts[101];
int G[101][101];
char used[101];

bool cross(int i, int j)
{
  double d = sqrt( (pts[i].x-pts[j].x)*(pts[i].x-pts[j].x) + (pts[i].y-pts[j].y)*(pts[i].y-pts[j].y) );

  if (pts[i].r + pts[j].r > d && d > fabs(pts[i].r - pts[j].r))
    return true;

  return false;
}

void print_gr(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << G[i][j] << " ";
    cout << endl;
  }
}

void build_gr(int n)
{
  memset(G, 0, sizeof G);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (G[i][j] == 0 && i != j)
	if (cross(i, j))
	  G[i][j] = G[j][i] = 1;
}

int dfs(int s, int n)
{
  used[s] = 1;
  int c = 1;

  for (int i = 0; i < n; i++)
    if (G[s][i] && !used[i])
      c += dfs(i, n);


  return c;
}

int lcc (int n)
{
  int c = 0;

  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++) 
    if (!used[i]) 
      c = max(c, dfs(i, n));

  return c;
}

int main()
{
  int n = 0;
  while (true)
  {
    cin >> n;
    if (n == -1)
      break;

    memset(pts, 0, sizeof pts);

    for (int i = 0; i < n; i++)
      cin >> pts[i].x >> pts[i].y >> pts[i].r;

    build_gr(n);
    //print_gr(n);

    int c = lcc(n);
    if (c == 1)
      cout << "The largest component contains 1 ring." << endl;
    else
      cout << "The largest component contains " << c << " rings." << endl;
  }

  return 0;
}

