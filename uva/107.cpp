#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ll;
const unsigned INF = 1234567890;
    
int main()
{
    ll H = 0;
    ll L = 0;
    
    while (1)
    {
      cin >> H >> L;
      if (H == 0 && L == 0)
	    break;

      int N = 0;
      ll catsH = 0;
      ll lazyCats = 0;
      
      for (int i = 1; i <= H; i++)
      {
	    ll h = 1;
	    ll l = L;
	    while (H > h && l >= 1)
	    {
	      h = i*h + h;
	      l /= i;
        }
	    if ( H == h && l == 1)
	    {
	      N = i;
	      break;
	    }
      }
      
      //cout << "N = " << N << endl;
      
      ll h = H;
      int deep = 0;
      while (h > 1)
      {
	    ll lzC = ll(pow(double(N), double(deep)));
	    catsH += lzC * h;
	    lazyCats += lzC;

	    h /= (N+1);
	    deep++;
      }
      
      cout << lazyCats << " " << (catsH+L) << endl;
    }
    
    return 0;
}
