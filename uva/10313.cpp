#include <cstring>
#include <cstdio>

typedef long long LL;

LL dp[305][305];
void solve()
{
    dp[0][0] = 1;
    for (int c = 1; c <= 300; c++)
    {
        for (int s = 0; s <= 300; s++)
        {
            dp[c][s] = dp[c-1][s];
            if (s-c >= 0)
                dp[c][s] += dp[c][s-c];
        }
    }
}

int main()
{
    int n = 0;
    int a = 0;
    int b = 0;
    char buf[32];

    solve();

    while (fgets(buf, 32, stdin) != 0)
    {
        switch (sscanf(buf, "%d%d%d", &n, &a, &b))
        {
            case 1:
                printf("%lld\n", dp[n][n]);
                break;
            case 2:
                if (a > 300) a = 300;
                printf("%lld\n", dp[a][n]);
                break;
            default:
                if (n == 0)
                {
                    printf("%d\n", a > 0 ? 0 : 1);
                    break;
                }

                if (a < 1) a = 1;
                if (a > 300) a = 300;
                if (b > 300) b = 300;
                    printf("%lld\n", dp[b][n]-dp[a-1][n]);
                break;
        }
    }

    return 0;
}

