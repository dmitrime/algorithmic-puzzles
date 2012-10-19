#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int> > & result (vector<pair<int, int> > & vv)
{
  int t;
  for (int i = vv.size()-1; i > 0; i--)
  {
    t = vv[i].first;
    vv[i].first = (vv[i].first + vv[i].second) % 10;
    vv[i-1].first += ((t + vv[i].second) / 10);
    //cout << "i = " << i << endl;
  }
  
  return vv;
} 

void print(vector<pair<int, int> > & v)
{
  int i = 0;
  if (v[i].first == 0) i++;
  
  for ( ; i < v.size(); i++)
    cout << v[i].first;

  cout << endl;
}

int main()
{
  int N = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int M = 0;
    cin >> M;

    vector<pair<int, int> > vv(M+1, make_pair(0, 0));

    for (int j = 1; j <= M; j++)
    {
      int x, y;
      cin >> x >> y;
      vv[j] = make_pair(x, y);
    }

    print(result(vv));
    
    if (i != N-1)
      cout << endl;
  }
  
  return 0;
}
 
