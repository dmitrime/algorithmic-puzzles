#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        cout << abs(((((((n * 567/9) +7492) * 235)/47 - 498) % 100)) / 10) << endl;
    }

    return 0;
}

