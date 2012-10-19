#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
map<pair<string, string>, int> memo;
int LCS(string a, string b)
{
    if (a.empty() || b.empty())
      return 0;
    
    pair<string, string> p = make_pair(a, b);
    if (memo.find(p) != memo.end())
      return memo[p];
    else
    {
        if (a[0] == b[0])
        {
            memo[p] = 1 + LCS(a.substr(1), b.substr(1));
            return memo[p];
        }
        else
          return max(LCS(a.substr(1), b), LCS(a, b.substr(1)));
    }
    return memo[p];
}
*/

int LCS(string a, string b)
{
    int n = a.size(); 
    int m = b.size();
    vector<vector<int> > dpmat(n+1, vector<int> (m+1, 0));
    
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i-1] == b[j-1])
          dpmat[i][j] = dpmat[i-1][j-1] + 1;
        else if (dpmat[i-1][j] > dpmat[i][j-1])
          dpmat[i][j] = dpmat[i-1][j];
        else
          dpmat[i][j] = dpmat[i][j-1];
    return dpmat[n][m];
}

int main()
{
    string a, b;
    int c = 0;
    while (1)
    {
        getline(cin, a);
        if (a == "#")
          break;
        getline(cin, b);
        
        c++;
        cout << "Case #" << c << ": you can visit at most " << LCS(a, b) << " cities." << endl;
    }
    
    return 0;
}
