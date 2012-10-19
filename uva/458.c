#include <stdio.h>

int main()
{
    char buf[256];
    char *p;
    while (fgets(buf, sizeof buf, stdin) != NULL)
    {
        p = buf;
        while (*p != '\0')
        {
            if (*p != '\n')
              putchar (*p - 7);
            else
              putchar( *p );
              
            p++;
        }   
    }
    
    return 0;
}
