#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int p[101];
int dp[26000];

int solve(int s, int m)
{
    for (int i = 0; i < m; i++)
      for (int j = s; j >= p[i]; j--)
        dp[j] = max(dp[j-p[i]] + p[i], dp[j]);
        
    return dp[s];
}

int main()
{    
    int N;
    cin >> N;
    
    while (N--)
    {
        memset(dp, 0, sizeof dp);
        int m = 0;
        int sum = 0;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
          cin >> p[i];
          sum +=  p[i];
        }
        int res = solve(sum/2, m);
        cout << abs(sum-res-res) << endl;
    }
    return 0;
}  
