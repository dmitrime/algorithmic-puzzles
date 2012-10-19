#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

const int SZ = 30000/5;
unsigned long long lin[SZ+1];
int val[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};


//matrix style:
/*
unsigned long long matrixStyle(int s)
{
    unsigned long long dp[SZ+1][12];
    
    for (int i = 0; i <= SZ; i++)
      for (int j = 0; j < 12; j++)
        dp[i][j] = 0;

    for (int i = 1; i < 12; i++)
      dp[0][i] = 1;

    for (int i = 1; i < 12; i++)
    {
        for (int j = 1; j <= s; j++)
          if (j - val[i-1] >= 0)
            dp[j][i] = dp[ j - val[i-1] ][i] + dp[j][i-1];
          else
            dp[j][i] = dp[j][i-1];
    }
    return dp[s][11];
}
*/

void doitlinear(int s)
{
    
    for (int i = 0; i < 11; i++)
    {
      for (int j = 0; j <= s; j++)
        if (j - val[i] >= 0)
          lin[j] += lin[j - val[i] ];
    }
}

int main()
{
    lin[0] = 1;
    
    float inp = 0.0;
    doitlinear(SZ);
    
    while (cin >> inp)
    {
        int s = int(inp*20.0 + 0.5);
        if (!s) break;
        
        //cout << "---------" << endl << "correct : " << matrixStyle(s) << endl << "----------" << endl;
        
        printf("%6.2f", inp);
        cout << setw(17) << lin[s] << endl;
    }
    
    return 0;
}
