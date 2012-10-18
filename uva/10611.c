#include <stdio.h>

unsigned xx[50001];
int binsea(int lo, int hi, unsigned tar)
{
    int mid = lo;
    while (lo <= hi)
    {
        mid = lo + (hi-lo)/2;
        
        if (xx[mid] == tar)
          break;
        else if (xx[mid] > tar)
          hi = mid-1;
        else
          lo = mid+1;
    }
    return mid;
}

int main(void)
{
    
    int n, q;
    unsigned target;
    int i, res;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", xx+i);
      
    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
      scanf("%u", &target);
      res = binsea(0, n-1, target);
      
      if (xx[res] == target)
      {
            if (res == 0)
            {
                if (res+1 == n)
                  printf("X X\n");
                else
                  printf("X %d\n", xx[res+1]);
            }
            else if (res == n-1)
            {
                if (res == 0)
                  printf("X X\n");
                else 
                  printf("%d X\n", xx[res-1]);
            }
            else if (xx[res-1] != target && xx[res+1] != target)
              printf("%d %d\n", xx[res-1], xx[res+1]);
            else if (xx[res-1] == target && xx[res+1] != target)
              printf("X %d\n", xx[res+1]);
            else if (xx[res-1] != target && xx[res+1] == target)
              printf("%d X\n", xx[res-1]);
            else if (xx[res-1] == target && xx[res+1] == target)
              printf("X X\n");
      }
      else if (xx[res] < target)
      {
            if (res == n-1)
              printf("%d X\n", xx[res]);
            else
              printf("%d %d\n", xx[res], xx[res+1]);
      }
      else if (xx[res] > target)
      {
            if (res == 0)
              printf("X %d\n", xx[res]);
            else
              printf("%d %d\n", xx[res-1], xx[res]);
      }
    }
    
    return 0;
}
