#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int mat[12][2];
int dp[12][12];
int res[12][12];

int solve_memo(int i, int n)
{
    if (dp[i][n] != -1)
        return dp[i][n];

    int t = 2134567890;
    for (int k = i; k < n; k++)
    {
        int tmp = solve_memo(i, k) + solve_memo(k+1, n) + mat[i][0]*mat[k][1]*mat[n][1];
        if (tmp < t)
        {
            t = tmp;
            res[i][n] = k;
        }
    }
    dp[i][n] = t; 
    return t;
}

string operator+ (string a, int b)
{
    char buf[32];
    sprintf(buf, "%d", b+1);
    return a + string(buf);
}

string build(int i, int n)
{
    if (i == n)
        return string("A") + i;

    return "(" + build(i,res[i][n]) + " x " + build(res[i][n]+1, n) + ")";
}

string go(int n)
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            if (i == j) {
                dp[i][j] = 0;
                res[i][j] = -1;
            }
            else
                dp[i][j] = res[i][j] = -1;

    solve_memo(0, n-1);
    //for (int i = 0; i < 12; i++)
    //{
    //    for (int j = 0; j < 12; j++)
    //        cout << dp[i][j] << "\t ";
    //    cout << endl;
    //}
    //cout << dp[0][n-1] << " !!" << endl;
    return build(0, n-1);
}

int main()
{
    int N;
    int cs = 1;
    while (1)
    {
        cin >> N;
        if (!N)
            break;
        for (int i = 0; i < N; i++)
            cin >> mat[i][0] >> mat[i][1];

        cout << "Case " << cs << ": " << go(N) << endl;
        cs++;
    }

    return 0;
}

