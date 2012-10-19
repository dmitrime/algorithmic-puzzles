#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned LCS(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int> > dpmat(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i-1] == b[j-1])
          dpmat[i][j] = dpmat[i-1][j-1] + 1;
        else  if (dpmat[i][j-1] > dpmat[i-1][j])
          dpmat[i][j] = dpmat[i][j-1];
        else
          dpmat[i][j] = dpmat[i-1][j];
          
    return dpmat[n][m];
}

int main()
{
    string a = "1";
    string b = "2";
    
    while (1)
    {
        getline(cin, a);
        getline(cin, b);
        
        if (a.empty() || b.empty())
          break;
        
        cout << LCS(a, b) << endl;
    }
    
    return 0;
}
