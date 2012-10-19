#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    string s, k, v;
    map<string, string> mp;
    while (1)
    {
        getline(cin, s);
        if (!s.size())
          break;
        istringstream ss(s);
        ss >> v >> k;   
        mp[k] = v;
    }
    
    while (1)
    {
        getline(cin, s);
        if (!s.size())
          break;
          
        if (mp.count(s))
          cout << mp[s] << endl;
        else
          cout << "eh" << endl;
    }
    
    return 0;
}
