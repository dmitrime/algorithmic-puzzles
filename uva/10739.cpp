#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string st;
int dp[1001][1001];
int go(int s, int e)
{
		if (dp[s][e] != -1)
				return dp[s][e];

		int& ret = dp[s][e];
		if (s == e || s > e)
				return ret = 0;

		//cout << "s = " << s << ", e = " << e << ", and st == " << st << endl;
		if (st[s] == st[e])
				ret = go(s+1, e-1);
		else
				ret = 1 + min(go(s+1, e-1), min(go(s+1, e), go(s, e-1)));

		return ret;

}

int main()
{

		int N = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
				memset(dp, -1, sizeof dp);

				cin >> st;
				cout << "Case " << (i+1) << ": " << go(0, st.size()-1) << endl;
		}
		return 0;
}
