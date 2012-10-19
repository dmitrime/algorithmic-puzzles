#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int G[1001][1001];
int Num[1001];
int T = 1;
vector<pair<int, int> > vp;

void print_gr(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << G[i][j] << " ";
    cout << endl;
  }
}

int dfs(int s, int p, int n)
{
  Num[s] = T++;
  int la = Num[s];

  for (int i = 0; i < n; i++)
  {
    if (G[s][i] && i != p)
    {
      if (!Num[i])
      {
	int r = dfs(i, s, n);

	if (Num[s] < r)
	  vp.push_back(make_pair(min(s,i), max(s,i)));

	la = min(la, r);
      }
      else
	la = min(la, Num[i]);
    }
  }

  return la;
}

void search(int n)
{
  for (int i = 0; i < n; i++)
    if (!Num[i])
      dfs(i, i, n);
}

int main()
{
  int n = 0;

  while (cin >> n)
  {
    T = 1;
    memset(G, 0, sizeof G);
    memset(Num, 0, sizeof Num);
    vp.clear();

    for (int k = 0; k < n; k++)
    {
      int srv = 0;
      int m;
      char c1, c2;

      cin >> srv >> c1 >> m >> c2;
      for (int i = 0; i < m; i++)
      {
	int x;
	cin >> x;
        G[srv][x] = 1;
        G[x][srv] = 1;
      }
    }

    search(n);
    sort(vp.begin(), vp.end());

    cout << vp.size() << " critical links" << endl;
    for (size_t j = 0; j < vp.size(); j++)
      cout << vp[j].first << " - " << vp[j].second << endl;
    cout << endl;

    //print_gr(n);
  }

  return 0;
}


