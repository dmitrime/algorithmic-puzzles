#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> primes(1000000, true);
    int n = 0;
    
    primes[0] = primes[1] = false;
    for (int i = 2; i < 1000; i++)
    {
      if (primes[i] == false) 
        continue;
      for (int j = i*i; j <= primes.size(); j += i)
        primes[j] = false;
    }
    
    while (cin >> n)
    {
        if (!n)
          break;
        bool b = false;
        
        if (!(n & 1))
        {
          for (int j = 0; j < n; j++)
            if ( primes[j] && primes[n-j])
            {
              cout << n << " = " << j << " + " << n-j << endl;
              b = true;
              break;
            }
        }
        
        if (!b)
          cout << "Goldbach's conjecture is wrong." << endl;
    }
    
    return 0;
}

