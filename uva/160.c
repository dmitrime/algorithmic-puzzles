#include <stdio.h>

int main(void)
{
    int Primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int N = (sizeof Primes)/(sizeof Primes[0]);
    int ans[101];
    int K;
    int i, j;
    int mx;
    
    while (1)
    {
        scanf("%d", &K);
        if (!K)
          break;
        
        mx = 0;
        for (i = 0; i < 101; i++)
          ans[i] = 0;
        
        for ( i = 2; i <= K; i++)
        {
            int b = i;
            while (b != 1)
            {
              for ( j = 0; j < N; j++)
                if (b % Primes[j] == 0)
                  break;
                  
              ans[Primes[j]]++;
              b /= Primes[j];
              mx = j > mx ? j : mx;
            }
            
            /*printf("I == %d\n", i);
            for ( j = 0; j <= mx; j++)
              printf("%d ", ans[Primes[j]]);
            printf("\n");*/
        }
        
        printf("%3d! =", K);
        for ( i = 0; i <= mx; i++)
        {
          if (i % 15 == 0 && i != 0)
            printf("\n      ");
          printf("%3d", ans[ Primes[i] ]);
        }
        printf("\n");
        
    }
    
    return 0;
}
