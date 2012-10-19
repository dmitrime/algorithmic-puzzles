#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int m[25][25];
int N;

void print()
{
  for (int i = 0; i < N; i++)
  {
        for (int j = 0; j < N; j++)
          cout << m[i][j] << " ";
        cout << endl;
    }
}

void search(int k, int *a, int *b)
{
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (m[i][j] == k)
        {
            *a = i;
            *b = j;
        }
}

void pile(int i, int j, bool over)
{
  if (i == j) 
    return;
    
  int a, b, c, d;
  search(i, &a, &b);
  search(j, &c, &d);
  
  if (b == d) return;
      
  
  if (!over)
  {
    for (int k = c+1; k < N; k++)
    {
      if (m[k][d] == -1) break;
      m[0][ m[k][d] ] = m[k][d];
      m[k][d] = -1;
    }
    
    for (int k = a; k < N; k++)
    {
        if (m[k][b] == -1) break;
        m[++c][d] = m[k][b];
        m[k][b] = -1;
    }
  }
  else
  {
    for ( ; c < N; c++)
      if (m[c][d] == -1) break;
      
    for (int k = a; k < N; k++)
    {
        if (m[k][b] == -1) break;
        m[c++][d] = m[k][b];
        m[k][b] = -1;
    }
  }
}

void move(int i, int j, bool over)
{
  if (i == j) 
    return;
    
  int a, b, c, d;
  search(i, &a, &b);
  search(j, &c, &d);
  
  if (b == d) return;
    
    if (!over)
    {
        for (int k = a+1; k < N; k++)
        {
            if (m[k][b] == -1) break;
            m[0][ m[k][b] ] = m[k][b];
            m[k][b] = -1;
        }
        for (int k = c+1; k < N; k++)
        {
            if (m[k][d] == -1) break;
            m[0][ m[k][d] ] = m[k][d];
            m[k][d] = -1;
        }
        
        m[c+1][d] = m[a][b];
        m[a][b] = -1;

    }
    else
    {
        for (int k = a+1; k < N; k++)
        {
            if (m[k][b] == -1) break;
            m[0][ m[k][b] ] = m[k][b];
            m[k][b] = -1;
        }
        
        for (c += 1; c < N; c++)
          if (m[c][d] == -1) break;
          
        m[c][d] = m[a][b];
        m[a][b] = -1;

    }
}

int main()
{
  char buf[32];
  memset(m, -1, sizeof m);
  
  cin >> N;
  for (int k = 0; k < N; k++)
    m[0][k] = k;
    
  do
  {
        cin >> buf;
        if (!strcmp(buf, "quit"))
          break;
        else if (!strcmp(buf, "move"))
        {
            int i, j;
            cin >> buf;
            sscanf(buf, "%d", &i);
            cin >> buf;
            //true - over, false - onto
            bool w = !strcmp(buf, "over");
            cin >> buf;
            sscanf(buf, "%d", &j);
            move(i, j, w);
        }
        else if (!strcmp(buf, "pile"))
        {
            int i, j;
            cin >> buf;
            sscanf(buf, "%d", &i);
            cin >> buf;
            //true - over, false - onto
            bool w = !strcmp(buf, "over");
            cin >> buf;
            sscanf(buf, "%d", &j);
            pile(i, j, w);
        }
  }
  while (1);
  
  for (int i = 0; i < N; i++)
  {
        cout << i << ":";
        for (int k = 0; k < N; k++)
        {
            if (m[k][i] == -1) break;
            cout << " " << m[k][i];
        }
        cout << endl;
  }

  return 0;
}

