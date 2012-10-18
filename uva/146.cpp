#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    while(1)
    {
        getline(cin, s);
        if (s.find('#') != string::npos)
          break;
        if (next_permutation(s.begin(), s.end()))
          cout << s << endl;
        else
          cout << "No Successor" << endl;
    }
    
    return 0;
}
