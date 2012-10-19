#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

string s;
void permute(string a, unsigned n)
{
    if (n == s.size())
    {
        cout << a << endl;
        return;
    }
    
    for (int i = 0; i <= n; i++)
      permute(a.substr(0, i) + s[n] + a.substr(i), n+1);
}

int main(void)
{
    bool f = false;
    while (cin >> s)
    {   
        if (f)
          cout << endl;
        permute("", 0);
        f = true;
    }
    
    return 0;
}
