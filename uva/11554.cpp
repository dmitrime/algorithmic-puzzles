#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long ar[1000005];
int main()
{
    int t = 0;
    cin >> t;

    ar[3] = 0;
    ar[4] = 1;
    unsigned long long sum = 1;
    unsigned long long a = 1;
    unsigned long long b;
    for (int i = 5; i <= 1000001; i++) {
        b = a - (i-1)/2 + i - 2;
        sum += b;
        a = b;
        ar[i] = sum;
    }

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        cout << ar[n] << endl;
    }

    return 0;
}

