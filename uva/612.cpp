#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int many(string s)
{
    int inv = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i+1; j < s.size(); j++)
          if (s[i] > s[j])
            inv++;
    }
    return inv;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        vector<string> vs;
        vector<pair<int, int> > vp;
        int n, k;
        string s;
        cin >> n >> k;
        for (int j = 0; j < k; j++)
        {
          cin >> s;
          vs.push_back(s);
          vp.push_back(make_pair(many(s), j));
        }
        sort(vp.begin(), vp.end());
        for (int j = 0; j < vp.size(); j++)
          cout << vs[vp[j].second] << endl;
        if (i != m-1)
          cout << endl;
    }
    
    return 0;
}
