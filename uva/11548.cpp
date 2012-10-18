#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string w[71];
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> w[j];

        int mx = 0;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) if (j != k) {
                for (int x = 0; x < w[j].size(); x+=1) {
                    //cout << "Comparing " << w[j].substr(x) << " and " << w[k] << endl;
                    int tmp = 0;
                    for (int s = 0; s < min(w[j].size()-x, w[k].size()); s++) {
                        if (w[j][x+s] == w[k][s])
                            tmp++;
                    }
                    mx = max(mx, tmp);
                }
            }

        cout << mx << endl;
    }

    return 0;
}

