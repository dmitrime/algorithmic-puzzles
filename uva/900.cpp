#include <iostream>

using std::cout;
using std::endl;
using std::cin;
int main()
{
    int n;
    while (1)
    {
						  cin >> n;
        if (!n)
          break;
        
        long long a = 0;
        long long b = 1;
        long long c = a+b;
        for (int i = 1; i < n; i++)
        {
            a = b;
            b = c;
            c = a+b;
        }
								cout << c << endl;
    }
    
    return 0;
}
