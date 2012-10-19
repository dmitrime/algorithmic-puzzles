#include <iostream>
#include <algorithm>

using namespace std;

int dp[3001];
int from[3001];
int diggy[3001];


int digi(int x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int sumFacDigits(int x)
{
    int y = 0;
    for (int i = 1; i <= x; i++)
        if (x % i == 0)
            y += digi(i);

    return y;
}

void precomp()
{
    for (int i = 1; i < 3001; i++)
        diggy[i] = sumFacDigits(i);
}

int go(int x, int p)
{
    //cout << "x = " << x << endl;
    if (dp[x] != -1)
        return dp[x];

    if (x == p)
        return 0;

    from[x] = diggy[x];
    return (dp[x] = 1 + go(from[x], x));
}

int main()
{
    int a, b;
    int k = 1;

    precomp();

    while (cin >> a >> b)
    {
        int A, B;
        A = a; B = b;

        if (B < A)
            swap(A, B);

        memset(dp, -1, sizeof dp);
        memset(from, -1, sizeof from);
        int m = 0;
        int w = -1;
        for (int i = A; i <= B; i++)
        {
            if (m < go(i, -1))
            {
                m = go(i, -1);
                w = i;
            }
        }


        cout << "Input" << k << ": " << a << " " << b << endl;
        cout << "Output" << k << ":";

        for (int i = 0; i < m; i++, w = from[w])
            cout << " " << w;

        cout << endl;
        k++;
    }

    return 0;
}

