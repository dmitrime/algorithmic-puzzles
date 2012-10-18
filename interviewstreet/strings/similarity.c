#include <stdio.h>
#include <string.h>

char buf[100010];
int main(void)
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        unsigned counter = 0, len = 0;
        int i, j;
        scanf("%s", buf);
        counter = len = strlen(buf);
        for (i = 1; i < len; i++)
            for (j = i; j < len; j++)
                if (buf[j] == buf[j-i])
                    counter++;
                else 
                    break;
        printf("%d\n", counter);
    }
    return 0;
}

