#include <iostream>

using namespace std;
int coins[] = {1, 5, 10, 25, 50};
int dp[7500];

int ways(int s)
{
    if (dp[s])
      return dp[s];
      
    dp[0] = 1;
    for (int j = 0; j < 5; j++)     
        for (int i = 1; i <= s; i++)
            if (i >= coins[j])
              dp[i] += dp[i-coins[j]];
    
    return dp[s];
}

int main()
{
    int sum = ways(7489);
    while (cin >> sum)
        cout << dp[sum] << endl;
    
    return 0;
}
