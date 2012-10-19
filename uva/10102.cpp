#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

char G[1011][1011];
int dist[1011][1011];


int main()
{
  int n;
  while (cin >> n)
  {
    vector<pair<int, int> > v1, v3;
    v1.clear();
    v3.clear();
    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
	cin >> G[i][j];
	if (G[i][j] == '1')
	  v1.push_back(make_pair(i, j));
	else if (G[i][j] == '3')
	  v3.push_back(make_pair(i, j));
      }

    int mx = 0;
    for (size_t i = 0; i < v1.size(); i++)
    {
      int m = 9999999;
      for (size_t j = 0; j < v3.size(); j++)
	m = min(m, abs(v1[i].first - v3[j].first) + abs(v1[i].second - v3[j].second));
      mx = max(mx, m);
    }

    cout << mx << endl;
  }

  return 0;
}

