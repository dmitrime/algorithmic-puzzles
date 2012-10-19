#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned seg[20005][2];
unsigned dp[20005][2];
int N = 0;


//cover [s,e] from source and come backe to s
int cheq0(int source, int s, int e)
{
		if (source < s)
				return e-source+e-s;
		if (source >= e)
				return source-s;
		
		return e-source+e-s;
}

//cover [s,e] from source and come backe to e
int cheq1(int source, int s, int e)
{
		if (source <= s)
				return e-source;
		if (source > e)
				return source-s+e-s;

		return source-s+e-s;
}

unsigned doit()
{
		dp[0][0] = seg[0][1]-1+seg[0][1]-seg[0][0];
		dp[0][1] = seg[0][1]-1;
		//cout << "Row 0: `0`= " << dp[0][0] << ", `1`= " << dp[0][1] << endl;
		for (int i = 1; i < N; i++)
		{
				int start = seg[i-1][0]; //drop 1
				int stop  = seg[i-1][1]; //drop 2

				dp[i][0] = 1 + min(cheq0(start, seg[i][0], seg[i][1]) + dp[i-1][0], cheq0(stop, seg[i][0], seg[i][1]) + dp[i-1][1]);
				dp[i][1] = 1 + min(cheq1(start, seg[i][0], seg[i][1]) + dp[i-1][0], cheq1(stop, seg[i][0], seg[i][1]) + dp[i-1][1]);

				//cout << "Row " << i << ": `0`= " << dp[i][0] << ", `1`= " << dp[i][1] << ", best=" << min(dp[i][0],dp[i][1]) << endl;
		}
		return min(dp[N-1][0] + N-seg[N-1][0], dp[N-1][1] + N-seg[N-1][1]);
}

int main()
{
		while(1)
		{
				cin >> N;
				if (!N)
						break;

				memset(dp, 0, sizeof dp);
				for (int i = 0; i < N; i++)
						cin >> seg[i][0] >> seg[i][1];

				cout << doit() << endl;
		}

		return 0;
}

