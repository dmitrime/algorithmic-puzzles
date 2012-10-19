#include <iostream>
#include <queue>

using namespace std;

int L, R, C;
char M[40][40][40];

struct node
{
		int i, j, k;
		int ret;
};

int bfs(int a, int b, int c)
{
		int tot = 0;
		queue<node> qq;
		node s;
		s.i = a; s.j = b; s.k = c;
		s.ret = 0;

		qq.push(s);
		while(!qq.empty())
		{
				node cur = qq.front();
				qq.pop();
				int i = cur.i; int j = cur.j; int k = cur.k;
				if (M[i][j][k] != '#')
				{
						if (M[i][j][k] == 'E')
						{
                                return cur.ret;
								/*if (!tot)
										tot = cur.ret;
								else
										tot = tot < cur.ret ? tot : cur.ret;
								*/
						}
						else
						{
								cur.ret++;
								if (i-1 >= 0) {node xx = cur; xx.i--; qq.push(xx);}
								if (i+1 < L) {node xx = cur; xx.i++; qq.push(xx);}
								if (j-1 >= 0) {node xx = cur; xx.j--; qq.push(xx);}
								if (j+1 < R) {node xx = cur; xx.j++; qq.push(xx);}
								if (k-1 >= 0) {node xx = cur; xx.k--; qq.push(xx);}
								if (k+1 < C) {node xx = cur; xx.k++; qq.push(xx);}

								M[i][j][k] = '#';
						}
				}
		}

		return tot;
}

int main()
{
		while (1)
		{
				cin >> L >> R >> C;

				if (!L && !R && !C)
						break;

				int s1, s2, s3;

				for (int i = 0; i < L; i++)
						for (int j = 0; j < R; j++)
								for (int k = 0; k < C; k++)
								{
										cin >> M[i][j][k];
										if (M[i][j][k] == 'S')
										{
												s1 = i;
												s2 = j;
												s3 = k;
										}
								}

				int rr = bfs(s1, s2, s3);

				if (!rr)
						cout << "Trapped!" << endl;
				else
						cout << "Escaped in " << rr << " minute(s)." << endl;
		}

		return 0;
}

