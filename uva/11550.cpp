#include <iostream>
#include <cstring>
using namespace std;

int M[10][32];
unsigned getBits(int i, int n) {
    unsigned r = 0;
    for (int j = 0; j < n; j++)
        if (M[j][i])
            r |= (1 << j);
    return r;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        memset(M, 0, sizeof M);
        cin >> n >> m;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> M[j][k];

        bool good = true;
        for (int k = 0; k < m; k++) {
            int c = 0;
            for (int j = 0; j < n; j++)
                c += M[j][k];

            if (c != 2) {
                good = false;
                break;
            }
        }
        if (good) {
            for (int k = 0; k < m && good; k++) {
                unsigned c1 = getBits(k, n);
                for (int j = k+1; j < m; j++) {
                    unsigned c2 = getBits(j, n);
                    //cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
                    if (c1 == c2) {
                        good = false;
                        break;
                    }
                }
            }
        }

        if (good)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

