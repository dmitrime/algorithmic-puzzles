#include <iostream>
using namespace std;

int solve(int x) 
{
    char c;
    int y;

    cin >> c; // (
    cin >> y;
    int r = 0;
    if (cin) {
        int k1 = solve(x - y);
        int k2 = solve(x - y);
        if (k1 == 1 || k2 == 1 || k1 == 2 && k2 == 2)
            r = 1;
    }
    else {
        if (x == 0)
            r = 2;
        cin.clear();
    }
    cin >> c; // )
    return r;
}
int main()
{
    int x = 0;
    while (cin >> x) {
        if (solve(x) == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
