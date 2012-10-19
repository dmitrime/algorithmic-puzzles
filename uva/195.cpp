#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N = 0;
    string s;
    vector<int> vv;
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
              vv.push_back((s[j] - 'A') * 2);
            else
              vv.push_back((s[j] - 'a') * 2 + 1);
        }
        sort(vv.begin(), vv.end());
        
        do
        {
          for (int j = 0; j < vv.size(); j++)
          {
            if (vv[j] & 1)
                cout << (char)(((vv[j]-1)/2) + 'a');
            else
                cout << (char)((vv[j]/2) + 'A');
          }
          cout << endl;
          
        } while (next_permutation(vv.begin(), vv.end()));
        vv.clear();
    }
    
    return 0;
}
