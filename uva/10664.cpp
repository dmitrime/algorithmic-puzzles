#include <string>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
int wq[128];
int dp[128];
int used[128];
int from[128];

bool knap(int s, int n)
{
    memset(dp, 0, sizeof dp); 
    memset(from, -1, sizeof from); 

				//cout << "S = " << s << endl;

    for (int j = 0; j < n; j++)
      for (int i = s; i >= wq[j]; i--)
								if (dp[i] < dp[i-wq[j]] + wq[j])
								{
										dp[i] = dp[i-wq[j]] + wq[j];
										from[i] = j;
								}
      
				/*
				cout << "dp: ";
    for (int j = 0; j <= s; j++)
						cout << dp[j] << " ";
				cout << endl;
				*/


    if (dp[s] != s)
						return false;

    memset(used, 0, sizeof used); 
				int k = s;
				while (dp[k] != 0)
				{
						used[from[k]] = 1;
						k = dp[k-wq[from[k]]];
				} 

				/*cout << "used: " ;
    for (int j = 0; j < n; j++)
						if (used[j])
								cout << j << " ";
				cout << endl;
				*/

    memset(dp, 0, sizeof dp); 
    memset(from, -1, sizeof from); 
    for (int j = 0; j < n; j++)
      for (int i = s; i >= wq[j]; i--)
								if (!used[j])
										if (dp[i] < dp[i-wq[j]] + wq[j])
										{
												dp[i] = dp[i-wq[j]] + wq[j];
												//from[i] = j;
										}

				/*
    memset(used, 0, sizeof used); 
				k = s;
				while (dp[k] != 0)
				{
						used[from[k]] = 1;
						k = dp[k-wq[from[k]]];
				} 
				cout << "used2: " ;
    for (int j = 0; j < n; j++)
						if (used[j])
								cout << j << " ";
				cout << endl;
				*/

				return dp[s] == s;
}

int main()
{
    int N = 0;
    cin >> N;
    string s;
    getline(cin, s);
    
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        istringstream ss(s);

        int k = 0;
        int sum = 0;
        while (ss >> wq[k++])
          sum += wq[k-1];
        if (sum % 2)
          cout << "NO" << endl;
        else
        {
            if (knap(sum/2, k))
              cout << "YES" << endl;
            else
              cout << "NO" << endl;
        } 
    }
    return 0;
}
