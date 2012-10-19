#include <iostream>
#include <cstring>
#define INF 1234567899

using namespace std;

int G[505][505];
int dist[2][505];
char seen[2][505];

void dijkstra(int s, int fin, int n)
{
  for (int i = 0; i < n; i++)
  {
    dist[0][i] = dist[1][i] = INF;
    seen[0][i] = seen[1][i] = 0;
  }
  dist[0][s] = 0;

  bool good[2];
  good[0] = good[1] = true;
  while (good[0] || good[1])
  {
    for (int k = 0; k < 2; k++)
    {
      int u = -1;
      int distBest = INF;
      for (int i = 0; i < n; i++) 
	if (!seen[k][i]) 
	  if (dist[k][i] < distBest)
	  {
	    u = i;
	    distBest = dist[k][i];
	  }

      if (u == -1) 
      {
	good[k] = false;
	continue;
      }
      else good[k] = true;

      for (int i = 0; i < n; i++) if (!seen[1-k][i] && G[u][i]) {
	if (dist[1-k][i] > dist[k][u] + G[u][i])
	  dist[1-k][i] = dist[k][u] + G[u][i];
      }

      seen[k][u] = 1;
      //cout << "u = " << u << ", k = " << k << endl;
    }
  }
    //for (int k = 0; k < 2; k++)
    //{
    //  for (int i = 0; i < n; i++) 
    //    cout << dist[k][i] << " ";
    //  cout << endl;
    //}
}

int main()
{
  int n, m;
  int T = 1;
  while (cin >> n >> m)
  {
    memset(G, 0, sizeof G);
    for (int i = 0; i < m; i++)
    {
      int x, y, t;
      cin >> x >> y >> t;
      G[x][y] = G[y][x] = t;
    }

    cout << "Set #" << T++ << endl;

    dijkstra(0, n-1, n);

    if (dist[0][n-1] != INF)
      cout << dist[0][n-1] << endl;
    else
      cout << '?' << endl;
  }


  return 0;
}

