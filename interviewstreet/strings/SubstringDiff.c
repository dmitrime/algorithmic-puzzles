#include <stdio.h>
#include <string.h>

#define MAX 15010
char s1[MAX];
char s2[MAX];
/*short M[MAX][MAX];
int goodI[MAX];*/
int main(void)
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        unsigned res = 0, len = 0;
        int i, j, k, K, p, prev, best, gap, hi, lo;
        scanf("%d %s %s", &K, s1, s2);

        /*memset(M, 0, sizeof M);
        memset(goodI, 1, sizeof goodI);*/
        len = strlen(s1);

        hi = len;
        lo = 1;
        while (lo <= hi)
        {
            k = lo + (hi-lo)/2;
            best = k+1;
            for (gap = 0; gap < len-k+1; gap++)
            {
                p = 0;
                i = 0;
                j = gap+i;
                for (; i < k; i++, j++)
                    if (s1[i] != s2[j])
                        p++;
                prev = p;
                for (; i < len-gap+1; i++, j++)
                {
                    prev += (s1[i] != s2[j]); /* current */
                    prev -= (s1[i-k] != s2[j-k]); /* first out */
                    if (p > prev)
                        p = prev;
                }
                if (best > p)
                    best = p;

                p = 0;
                i = gap;
                j = gap-i;
                for (; i < gap+k; i++, j++)
                    if (s1[i] != s2[j])
                        p++;
                prev = p;
                for (; i < len; i++, j++)
                {
                    prev += (s1[i] != s2[j]); /* current */
                    prev -= (s1[i-k] != s2[j-k]); /* first out */
                    if (p > prev)
                        p = prev;
                }
                if (best > p)
                    best = p;
            }
            if (best <= K)
            {
                if(res < k)
                    res = k;
                lo = k+1;
            }
            else
                hi = k-1;
        }
        printf("%d\n", res);

        /*for (k = 1; k <= len; k++)
        {
            for (i = 0; i < len-k+1; i++)
            {
                if (!goodI[i])
                    continue;
                goodI[i] = 0;

                for (j = 0; j < len-k+1; j++)
                {
                    if (s1[i+k-1] != s2[j+k-1])
                        M[i][j] += 1;
                    if (M[i][j] <= K)
                    {
                        goodI[i] = 1;
                        if(res < k)
                            res = k;
                    }
                }
            }
        }

        printf("%d\n", res);*/
    }
    return 0;
}


