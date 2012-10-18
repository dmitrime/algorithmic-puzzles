#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct point 
{
  int x, y;
  int sx, sy;
  int c;
};

int G[32][32];
void print(int X, int Y)
{
  cout << endl;
  for (int i = 0; i < Y; i++)
  {
    for (int j = 0; j < X; j++)
    {
      char x = G[i][j];
      cout << x << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int process(int xs, int ys, int X, int Y, int xf, int yf)
{
  point p;
  queue<point> qu;
  int m = -1;

  p.x = xs; p.y = ys; p.sx = 0; p.sy = 0; p.c = 1;

  if (G[yf][xf] == '#' || G[ys][xs] == '#')
    return -1;
  if (xs == xf && ys == yf)
    return 0;

  qu.push(p);
  while (!qu.empty())
  {
    point q = qu.front();
    qu.pop();

    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++)
	if (!(i + q.sx == 0 && j + q.sy == 0))
	  if (q.sx+i >= -3 && q.sx+i <= 3 && q.sy+j >= -3 && q.sy+j <= 3)
	    if (q.x+q.sx+i >= 0 && q.x+q.sx+i < X && q.y+q.sy+j >= 0 && q.y+q.sy+j < Y)
	    {
	      if (q.x+q.sx+i == xf && q.y+q.sy+j == yf)
	      {
		return q.c;
		//if (m == -1)
		//  m = q.c;
		//else
		//  m = min(m, q.c);

		//continue;
	      }

	      point a = q;
	      a.sx += i; a.sy += j;
	      a.x += a.sx; a.y += a.sy;
	      a.c += 1;

	      if (G[a.y][a.x] != '#')
		qu.push(a);

	      //cout << "new point " << a.x << ", " << a.y  << " sp: " << a.sx << ", " << a.sy << endl;
	    }

    //print(X, Y);
    G[q.y][q.x] = '#';
  }

  return m;
}

int main()
{
  int N = 0;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int X, Y;
    int xs, ys, xf, yf;
    int P;
    cin >> X >> Y;

    for (int j = 0; j < X; j++)
      for (int k = 0; k < Y; k++)
	G[k][j] = '@';

    cin >> xs >> ys >> xf >> yf;
    cin >> P;

    for (int j = 0; j < P; j++)
    {
      int x1, y1, x2, y2;
      cin >> x1 >> x2 >> y1 >> y2;

      for (int q = min(x1,x2); q <= max(x2,x1); q++)
	for (int w = min(y2,y1); w <= max(y2,y1); w++)
	  G[w][q] = '#';
    }

    int ans = process(xs, ys, X, Y, xf, yf);
    if (ans == -1)
      cout << "No solution." << endl;
    else
      cout << "Optimal solution takes " << ans << " hops." << endl;

  }

  return 0;
}

