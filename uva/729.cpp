#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N = 0;
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int K, H;
        vector<char> v;
        
        cin >> K >> H;
        for (int j = 0; j < K; j++)
          if (j < (K-H))
            v.push_back('0');
          else
            v.push_back('1');
            
        do
        {
            for (int k = 0; k < v.size(); k++)
              cout << v[k];
            cout << endl;
        } while (next_permutation(v.begin(), v.end()));
        
        if (i != N-1)
          cout << endl;
    }
    
    return 0;
}

