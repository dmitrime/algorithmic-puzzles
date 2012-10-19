#include <iostream>
#include <cstring>
#include <vector>
#define INF 1234567899

using namespace std;

vector<pair<pair<int, int>, int> > vp;
int dist[2][505];
void bellmanFord(int s, int fin, int n)
{
  for (int i = 0; i < n; i++)
    dist[0][i] = dist[1][i] = INF;

  dist[0][s] = 0;

  for (int i = 0; i < n-1; i++)
  {
    for (size_t j = 0; j < vp.size(); j++)
    {
      int x, y, t;
      x = vp[j].first.first;
      y = vp[j].first.second;
      t = vp[j].second;

      for (int k = 0; k < 2; k++)
      {
	if (dist[k][y] != INF && dist[1-k][x] > dist[k][y] + t)
	  dist[1-k][x] = dist[k][y] + t;

	if (dist[k][x] != INF && dist[1-k][y] > dist[k][x] + t)
	  dist[1-k][y] = dist[k][x] + t;
      }
    }
  }
}

int main()
{
  int n, m;
  int T = 1;
  while (cin >> n >> m)
  {
    vp.clear();
    for (int i = 0; i < m; i++)
    {
      int x, y, t;
      cin >> x >> y >> t;
      vp.push_back(make_pair(make_pair(x, y), t));
    }

    cout << "Set #" << T++ << endl;

    bellmanFord(0, n-1, n);

    if (dist[0][n-1] != INF)
      cout << dist[0][n-1] << endl;
    else
      cout << '?' << endl;
  }


  return 0;
}

