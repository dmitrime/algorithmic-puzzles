#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned n = 0;
        unsigned long long k = 0;
        cin >> n;
        cin >> k;

        unsigned long long mx = k;
        int n10 = 1;
        for (int j = 1; j <= n; j++)
            n10 *= 10;

        unsigned long long tmp;
        for (int x = 0; x < 10000 ; x++) {
            tmp = k * k;
            while (tmp >= n10)
                tmp /= 10;

            if (mx < tmp)
                mx = tmp;

            k = tmp;
        }
        cout << mx << endl;
    }

    return 0;
}

