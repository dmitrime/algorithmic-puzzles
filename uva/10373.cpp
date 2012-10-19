#include <iostream>
#include <cstring>
#define INF 100000000

using namespace std;

struct Brick
{
    int c;
    int p;
} b[210];

struct Client
{
    int cmin;
    int cmax;
    int m;
} cl[110];

int dp[22][20010];
//   using  weight
void go(int n)
{
    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 20010; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int j = 0; j < n; j++)
        for (int i = 20; i > 0; i--)
            for (int k = 20000; k >= b[j].c; k--)
                if (dp[i][k] > dp[i-1][k-b[j].c] + b[j].p)
                    dp[i][k] = dp[i-1][k-b[j].c] + b[j].p;
}

void solve(int n, int c)
{
    go(n);
    for (int i = 0; i < c; i++)
    {
        int res = INF;
        int cm = cl[i].m;
        for (int j = cl[i].cmin*cm; j <= 20000 && j <= cl[i].cmax*cm; j++)
            if (dp[cm][j] < res)
                res = dp[cm][j];

        if (res < INF)
            cout << res << endl;
        else 
            cout << "impossible" << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> b[i].c >> b[i].p;

        int c = 0;
        cin >> c;
        for (int i = 0; i < c; i++)
            cin >> cl[i].m >> cl[i].cmin >> cl[i].cmax;

        solve(n, c);
        if (N)
            cout << endl;
    }

    return 0;
}

