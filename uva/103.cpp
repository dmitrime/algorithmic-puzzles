#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int up[31];
int dp[31];
int solve(vector<pair<vector<int>, int> >& b, int k, int n)
{
    int best = 0;
    int mx = 0;
    
    for (int i = 0; i < k; i++)
      for (int j = 0; j < i; j++)
      {
        bool good = true;
        for (int k = 0; k < n; k++)
          if (b[j].first[k] >= b[i].first[k])
            good = false;
            
        if (good && dp[i] < dp[j] + 1)
        {
            dp[i] = dp[j] + 1;
            up[i] = j;
            if (mx < dp[i])
            {
                mx = dp[i];
                best = i;
            }
        }
      }
    
    /*
      cout << "!!!" << endl;
    for (int i = 0; i < k; i++)
      cout << b[i].second << " ";
    cout << "!!!" << endl;
    */
      return best;
}

void print(vector<pair<vector<int>, int> >& b, int ind, int x)
{
    if (up[ind] == -1)
    {
        cout << b[ind].second;
        
        if (dp[ind] == x)
          cout << endl;
        else cout << " ";
        
        return;
    }
    print(b, up[ind], x);
     
    cout << b[ind].second;
        
    if (dp[ind] == x)
      cout << endl;
    else cout << " ";
}

bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
    bool small = true;
    for (size_t i = 0; i < a.first.size(); i++)
      if (a.first[i] > b.first[i])
        small = false;
        
    return small;
}

int main()
{
    int k, n;
    
    while (cin >> k >> n)
    {
        vector<pair<vector<int>, int> > b(k, make_pair(vector<int> (n, 0), 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
              cin >> b[i].first[j];
              
            b[i].second = i+1;
            sort(b[i].first.begin(), b[i].first.begin()+n);
            up[i] = -1;
            dp[i] = 1;
        }
        
        sort(b.begin(), b.begin()+k, cmp);
        /*
        cout << "------" << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
              cout << b[i].first[j] << " ";
              cout << " | " << b[i].second << endl;
        }
        cout << "------" << endl;
        */
        
        int res = solve(b, k, n);
        cout << dp[res] << endl;
        print(b, res, dp[res]);
    }
    
    return 0;
}
