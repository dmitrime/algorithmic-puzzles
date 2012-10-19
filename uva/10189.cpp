#include <iostream>
using namespace std;

char M[101][101];
int main()
{
    int n, m;
    int k = 1;
    bool first = true;
    while(1)
    {
        cin >> n >> m;
        if (!n || !m)
          break;
        
        if (!first)           
          cout << endl;
        first = false;
        
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
            cin >> M[i][j];
        
        cout << "Field #" << k << ":" << endl;
        
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
          {
                if (M[i][j] == '*')
                  continue;
                else
                {
                    M[i][j] = '0';
                    if (i > 0) if (M[i-1][j] == '*') M[i][j]++;
                    if (j > 0) if (M[i][j-1] == '*') M[i][j]++;
                    if (i > 0 && j > 0) if (M[i-1][j-1] == '*') M[i][j]++;
                    if (i < n-1) if (M[i+1][j] == '*') M[i][j]++;
                    if (j < m-1) if (M[i][j+1] == '*') M[i][j]++;
                    if (i < n-1 && j < m-1) if (M[i+1][j+1] == '*') M[i][j]++;
                    if (i > 0 && j < m-1) if (M[i-1][j+1] == '*') M[i][j]++;
                    if (i < n-1 && j > 0) if (M[i+1][j-1] == '*') M[i][j]++;
                }
          }
        
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)
            cout << M[i][j];
          cout << endl;
        }

        k++;
    }
    
    return 0;
}
