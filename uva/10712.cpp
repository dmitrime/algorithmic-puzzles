#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

unsigned dp[11][10][10];
int main()
{
    int a, b;
    long long n;
    memset(dp, 255, sizeof dp);
    cout << dp[0][0][0] << endl;
    
    while (1)
    {
        cin >> a >> b >> n;
        if (n == -1)
          break;
          
        if (a > b)
          swap(a, b);
        
        memset(dp, 0, sizeof dp);
        
        int sum = 0;
        for (int i = 1; i < 10; i++)
        {
            //if (n)
            //  for (int j = 0; j <= 9; j++)
                
        }
    }
    
    return 0;
}
