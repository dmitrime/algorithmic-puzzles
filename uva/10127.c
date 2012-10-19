#include <stdio.h>

int main(void)
{
    int N = 0;
    int i, n = 1;
    
    while (scanf("%d", &N) == 1)
    {
        if (N % 2 == 0 || N % 5 == 0)
          continue;
          
        n = 1;
        for (i = 1; (n % N) != 0; i++, n = n*10 + 1)
            n %= N;
        
        printf("%d\n", i);
    }
    
    return 0;
}
