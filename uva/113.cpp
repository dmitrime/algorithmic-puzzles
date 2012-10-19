#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double p = 0.0;
    int n = 0;
    
    while (cin >> n >> p)
    {
        unsigned long long a = 0;
        a = exp( log(p) / n );
        cout << a << endl;
    }
    
    return 0;
}
