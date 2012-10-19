#include <iostream>

using std::cout;
using std::cin;
using std::endl;

inline int  min(int x, int y)
{
   return  x < y ? x : y;
}
inline int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
  int i, j;

  while (cin >> i >> j)
  {
    int mx = 0;
    for (int k = min(i, j); k <= max(i, j); k++)
    {
      int c = 1;
      int t = k;
      
      while(t > 1)
      {
        if (t & 1) t = 3*t + 1;
        else t /= 2;
        c++;  
      } 
      if (mx < c) mx = c;
    }
    
    cout << i << " " << j << " " << mx << endl;
  }

  return 0;
}

