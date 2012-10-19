#include <iostream>

using namespace std;

typedef unsigned long long ull;
ull dp[70][70];
char us[70][70];

ull trib(int n, unsigned back)
{

		if (us[n][back])
				return dp[n][back];

		if (n < 2)
				return 1;

		dp[n][back]++;
		for(unsigned i = 1; i <= back; i++)
				dp[n][back] += trib(n-i, back);

		us[n][back] = 1;
		return dp[n][back];
}

int main()
{
		int n;
		unsigned back;
  int k = 1;
		while (cin >> n >> back)
		{
				if (n > 60)
						break;

				ull Count = trib(n, back);
				cout << "Case " << k << ": " << Count << endl;
				k++;
		}

		return 0;

}

