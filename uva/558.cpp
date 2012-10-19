#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

//558 - Wormholes
//graphs, negative cycles, bellman-ford

int main()
{
  int N = 0;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int n, m;
    int x, y, t;
    vector<pair< pair<int, int>, int> > vi;

    cin >> n >> m;
    for (int j = 0; j < m; j++)
    {
      cin >> x >> y >> t;
      vi.push_back(make_pair(make_pair(x, y), t));
    }
    //go bellman-ford
    vector<int> dist(1005, INF);
    dist[0] = 0;

    for (int k = 1; k < n; k++)
      for (size_t l = 0; l < vi.size(); l++)
      {
	int u = vi[l].first.first;
	int v = vi[l].first.second;
	int t = vi[l].second;

	if (dist[u] != INF && dist[v] > dist[u] + t)
	  dist[v] = dist[u] + t;

      }
    //cout << "!! " << endl;
    //for (int k = 0; k < n; k++)
    //  cout << dist[k] << " ";
    //cout << endl;

    //check for negative cycles
    bool neg = false;
    for (size_t l = 0; l < vi.size(); l++)
    {
      int u = vi[l].first.first;
      int v = vi[l].first.second;
      int t = vi[l].second;

      if (dist[u] != -1 && dist[v] > dist[u] + t)
	neg = true;
    }

    if (neg)
      cout << "possible" << endl;
    else
      cout << "not possible" << endl;

  }

  return 0;
}

