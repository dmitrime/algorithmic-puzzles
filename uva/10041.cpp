#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    while (N-- > 0)
    {
        int M;
        vector<int> v;
        
        cin >> M;
        for (int i = 0; i < M; i++)
        {
          int x;
          cin >> x;
          v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        unsigned sum = 0;
        for (int i = 0; i < v.size(); i++)
          sum += abs(v[(v.size()-1)/2] - v[i]);
        cout << sum << endl;
    }
    
    return 0;
}
