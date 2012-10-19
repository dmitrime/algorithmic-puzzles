#include <iostream>
#include <set>
#include <cmath>

using namespace std;

typedef double ll;

ll poow(ll a, ll b)
{
    return pow(double(a), double(b));
}

int main()
{
    set<ll> s;
    s.insert(1);
    int c = 1500;
    
    for (int i = 0; i < 30; i++)
      for (int j = 0; j < 30; j++)
        for (int k = 0; k < 30; k++)
        {
          s.insert( poow(2, k) * poow(3, j) * poow(5, i) );
        }
    
    
    int n = 1;    
    for (set<ll>::iterator it = s.begin(); it != s.end(); it++)
    {
      if (n == 1500)
      {
        unsigned long long x = *it;
        cout << "The 1500'th ugly number is " << x << "." << endl;
      }
      n++;
    }

    return 0;
}
