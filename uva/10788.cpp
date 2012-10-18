#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string str;
int dp[101][101];

int go1(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a > b)
        return 1;
    if (a == b)
        return 0;

    dp[a][b] = 1;
    int ind = a;
    while (ind < b) {
        int ld = b;
        while (str[ld] != str[ind])
            ld--;
        dp[a][b] &= go1(ind+1, ld-1);
        ind = ld + 1;
    }

    if (ind == b)
        dp[a][b] = 0;

    return dp[a][b];
}

int main()
{
    int N = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        memset(dp, -1, sizeof dp);
        cin >> str;
        cout << "Case " << i << ": ";
        switch(go1(0, str.size()-1)) {
            case 0:
                cout << "Invalid";
                break;
            case 1:
                cout << "Valid, Unique";
                break;
            default:
                cout << "Valid, Multiple";
                break;
        }
        cout << endl;
    }
    return 0;
}

