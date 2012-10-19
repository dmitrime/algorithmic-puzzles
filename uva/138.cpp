#include <iostream>
using namespace std;

int main()
{
    unsigned  long long a = 36;
    unsigned  long long b = 50;
    int c = 0;
    while (c < 8)
    {
        for (; ;)
        {
          unsigned long long s1 = (a * (a-1)) / 2;
          unsigned long long s2 = ((b-a)*(a+1 + b)) / 2;
          if (s1 == s2)
          {
                cout << a << " " << b << endl;
                a++;
                b++;
                c++;
                break;
          }
          else if (s1 > s2)
            break;
            
          a++;
        }
        b++;
    }
    
    while(10);
    return 0;
}
