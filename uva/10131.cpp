#include <iostream>
#include <cstring>
#include <algorithm>

struct Ele
{
    int w, iq, no;
} ele[1010];

int dp[1010];
int seq[1010];
using namespace std;

void print(int x, int i)
{
    if (x == 0)
        return;
    print(x-1, seq[i]);
    cout << ele[i].no << endl;
}

bool cmp(Ele a, Ele b)
{
    if (a.w == b.w)
        return a.iq < b.iq;
    return a.w < b.w;
}

int main()
{
    int n = 0;
    while (cin >> ele[n].w >> ele[n].iq)
        n++;

    for (int i = 0; i < n; i++)
        ele[i].no = i+1;

    sort(ele, ele+n, cmp);

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    int mx = 1;
    int mi = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (dp[i] + 1 > dp[j] && ele[i].w < ele[j].w && ele[i].iq > ele[j].iq) {
                dp[j] = dp[i] + 1;
                seq[j] = i;
                if (dp[j] > mx) {
                    mx = dp[j];
                    mi = j;
                }
            }

    if (n == 0)
        cout << 0 << endl;
    else
    {
        cout << mx << endl;
        print(mx, mi);
    }

    return 0;
}

