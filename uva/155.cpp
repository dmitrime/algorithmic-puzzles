#include <iostream>
#include <iomanip>
using namespace std;

int a = 0;
void rec (int k, int x, int y, int c1, int c2)
{
    
    if (k < 1)
      return;
          
    if (x <= c1+k && x >= c1-k && y <= c2+k && y >= c2-k)
    {
        
      /*cout << endl << "K = " << k << endl << "POINT: (" << x << ";" << y << ")" << endl;
      cout << "CENTER: (" << c1 << ";" << c2 << ")" << endl;
      cout << "L-Upper: (" << c1-k << ";" << c2-k << ")" << endl;
      cout << "L-Lower: (" << c1-k << ";" << c2+k << ")" << endl;
      cout << "R-Upper: (" << c1+k << ";" << c2-k << ")" << endl;
      cout << "R-Lower: (" << c1+k << ";" << c2+k << ")" << endl << endl;*/
      a++;
    }
    
    rec(k/2, x, y, c1+k, c2+k);
    rec(k/2, x, y, c1-k, c2+k);
    rec(k/2, x, y, c1-k, c2-k);
    rec(k/2, x, y, c1+k, c2-k);
}

int main()
{
    int k, x, y;

    
    while (1)
    {
        cin >> k >> x >> y;
        if (!k && !x && !y)
          break;
        
        rec(k, x, y, 1024, 1024);
        
        cout << setw(3) << a << endl;
        a = 0;
    }
    
    return 0;
}
