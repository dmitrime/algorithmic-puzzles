#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int> > vv(N, vector<int> (N, 0));
    vector<vector<int> > dp(N, vector<int> (N, 0));
    
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> vv[i][j];
        
    
    cout << "-----------------------" << endl;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        cout << vv[i][j] << " ";
      cout << endl;
    }
    
    dp[0][0] = vv[0][0];
    for (int i = 1; i < N; i++)
    {
      dp[0][i] = vv[0][i];
      dp[i][0] = vv[i][0];
    }
    
    long long mx = dp[0][0];
    for (int i = 1; i < N; i++)
    {
      for (int j = 1; j < N; j++)
      {
        dp[i][j] = dp[i-1][j] + dp[i][j-1] + vv[i][j];
        mx = mx > dp[i][j] ? mx : dp[i][j];
      }
    }
    
    cout << "-----------------------" << endl;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        cout << dp[i][j] << " ";
      cout << endl;
    }
    cout << "-----------------------" << endl;
    
    cout << mx << endl;
    while (cin.get() == '\n');
    return 0;
}
