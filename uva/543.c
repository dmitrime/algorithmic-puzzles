#include <stdio.h>

char primes[1000000];
short pronly[200];
int main(void)
{
    int n = 0;
    int i, j, x, k;
    
    primes[0] = primes[1] = 1;
    
    x = 2; /* have 3 and 5, start w/ 7, totally ignore 2 */
    for (i = 7; i <= 1000; i+=2)
    {
        if (primes[i] || !(i % 3) || !(i % 5))
          continue;
          
        for (j = i*i; j <= 1000000; j += (2*i))
          primes[j] = 1;
        
        pronly[x++] = i;
    }
    pronly[0] = 3;
    pronly[1] = 5;
    
    /*printf("%d\n", x);
    for (i = 0; i < 20; i++)
      printf("%d ", pronly[i]);*/
    
    /*for (i = 2; i <= 1000000; i++)
      if (!primes[i])
        pronly[x++] = i;*/
        
    printf("%f", 1e+3);
    while (1)
    {
        scanf("%d", &n);
        
        if (!n)
          break;
          
        if (!(n & 1))
        {
            for (j = 0; j < x; j++)
            {
                if (n <= pronly[j])
                  break;
                  
                k = n - pronly[j];
                if ((k != 3 && !(k % 3)) || (k != 5 && !(k % 5)) )
                  continue;
                  
                if (!primes[n - pronly[j]])
                {
                    printf("%d = %d + %d\n", n, pronly[j], n-pronly[j]);
                    break;
                }
            }
        }
        else
          printf("Goldbach's conjecture is wrong.\n");
        
    }
    
    return 0;
}
