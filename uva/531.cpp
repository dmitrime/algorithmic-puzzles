#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;

string LCS(VS& a, VS& b)
{
    int n = a.size();
    int m = b.size();
    string emo[n+1][m+1];
    vector<vector<int> > vvv(n+1, vector<int> (m+1, 0));
    
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i-1] == b[j-1])
        {
          emo[i][j] = emo[i-1][j-1] + a[i-1] + " ";
          vvv[i][j] = vvv[i-1][j-1] + 1;
        }
        else if (vvv[i-1][j] < vvv[i][j-1])
        {
          emo[i][j] = emo[i][j-1];
          vvv[i][j] = vvv[i][j-1];
        }
        else
        {
          emo[i][j] = emo[i-1][j];
          vvv[i][j] = vvv[i-1][j];
        }
          
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
          cout << emo[i][j] << " | ";
        cout << endl;
    }*/
          
    return emo[n][m];
}

int main()
{
    VS vv;
    VS cc;
    
    while (1)
    {
        string s;
        while (1)
        {
            cin >> s;
            if (s.empty())
              goto end;
              
            if (s == "#")
              break;
            
            vv.push_back(s);
        }
        while (1)
        {
            cin >> s;
            if (s.empty())
              goto end;
              
            if (s == "#")
              break;
            
            cc.push_back(s);
        }
        
        s = LCS(vv, cc);
        
        if (!s.empty())
          cout << s.substr(0, s.size() - 1) << endl;
        else
          cout << endl;
        
        vv.clear();
        cc.clear();
    }
    
    end:
    return 0;
}
