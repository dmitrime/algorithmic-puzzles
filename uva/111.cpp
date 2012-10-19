#include <iostream>
using namespace std;

int N;
int A[32];
int B[32];
int C[32];

unsigned LCrS()
{
    int dp[32];
    int i, j;
    
    for (i = 0; i < N; i++)
      dp[i] = 1;
    
    int mx = 1;
    for (i = 1; i < N; i++)
      for (j = 0; j < i; j++)
        if (B[i] > B[j])
          if (dp[i] < dp[j] + 1)
          {
            dp[i] = dp[j] + 1;
            mx = mx > dp[i] ? mx : dp[i];
          }
    
    /*cout << "DP: " << endl;
    for (i = 0; i < N; i++)
      cout << dp[i] << " ";
    cout << endl;*/
    return mx;
}

int change(int a)
{
    int j;
    for (j = 0; j < N; j++)
      if (B[j] == a && C[j] == 0)
      {
        C[j] = 1;
        return j;
      }
}

int main()
{
    int i;
    cin >> N;
    
    for (i = 0; i < N; i++)
      cin >> C[i];
      
    for (i = 0; i < N; i++)
      A[C[i] - 1] = i+1;
    
    int x = 0;
    while (cin >> x)
    {
        C[0] = x;
        for (i = 1; i < N; i++)
          cin >> C[i];
          
        for (i = 0; i < N; i++)
          B[C[i] - 1] = i+1;
        
        for (i = 0; i < N; i++)
          C[i] = 0;
          
        for (i = 0; i < N; i++)
          B[ change(A[i]) ] = i+1;
                  
        /*cout << "New: " << endl;
        for (i = 0; i < N; i++)
          cout << B[i] << " ";
        cout << endl;*/

        cout << LCrS() << endl;
    }
    
    return 0;
}
