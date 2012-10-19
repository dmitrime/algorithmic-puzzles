#include <iostream>
using namespace std;

/*
unsigned f91(unsigned N)
{
    if (N >= 101)
      return N-10;
    
    return f91(f91(N+11));
}
*/
int main()
{
    int N = 0;
    
    while (cin >> N)
    {
        if (!N)
          break;
        int r = N <= 100 ? 91 : N-10;
        cout << "f91(" << N << ") = " << r << endl;
    }
    
    return 0;
}
