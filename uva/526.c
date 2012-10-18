#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[85][85];
char bq[85][85];
char a[85];
char b[85];
int solve(int n, int m)
{
    int i, j;

    for (i = 1; i <= n; i++)
        dp[i][0] = i;
    for (j = 0; j <= m; j++)
        dp[0][j] = j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                bq[i][j] = '-';
            }
            else {
                if (dp[i-1][j] < min(dp[i-1][j-1], dp[i][j-1])) {
                    dp[i][j] = dp[i-1][j] + 1;
                    bq[i][j] = 'D';
                }
                else if (dp[i][j-1] < min(dp[i-1][j-1], dp[i-1][j])) {
                    dp[i][j] = dp[i][j-1] + 1;
                    bq[i][j] = 'I';
                }
                else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    bq[i][j] = 'R';
                }
            }
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++)
            printf("%c ", bq[i][j]);
        printf("\n");
    }

    return dp[n][m];
}

void print(int k, int n, int m)
{
    int x = 1;
    int i = 1, j = 1;
    while (x <= k && i <= n && j <= m)
    {
        switch(bq[n-i+1][m-j+1]) {
            case 'I':
                printf("%d Insert %d,%c\n", x, i, b[j-1]);
                j++;
                break;
            case 'D':
                printf("%d Delete %d\n", x, i);
                i++;
                break;
            case 'R':
                printf("%d Replace %d,%c\n", x, i, b[j-1]);
                i++; j++;
                break;
            case '-':
                i++; j++;
                break;
            default: break;
        }
        x++;
    }
}

int main()
{
    while (fgets(a, sizeof a, stdin) != NULL)
    {
        char* l;
        int res = 0;
        int n, m;

        memset(dp, 0, sizeof dp);
        memset(bq, 0, sizeof bq);

        if ((l = strchr(a, '\n')) != NULL)
                *l = '\0';
        fgets(b, sizeof b, stdin);
        if ((l = strchr(b, '\n')) != NULL)
                *l = '\0';

        n = strlen(a);
        m = strlen(b);

        res = solve(n, m);
        printf("%d\n", res);
        print(res, n, m);
        printf("\n");
    }

    return 0;
}

