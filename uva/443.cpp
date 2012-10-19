#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a[4] =  {2, 3, 5, 7};
    vector<int> res(1, 1);
    vector<int> s(a, a+4);
    vector<int> k(s.size(), 0);
    vector<int> t(s.size());
    
    while (res.size() < 5842)
    {
      t[0] = s[0]*res[k[0]];
      t[1] = s[1]*res[k[1]];
      t[2] = s[2]*res[k[2]]; 
      t[3] = s[3]*res[k[3]];
      
      int mn = min_element(t.begin(), t.end()) - t.begin();
      k[mn]++;
      
      if (res.back() != t[mn])
        res.push_back(t[mn]);
    }
    
    
    int i = 0;
	char *suf[] = {"th", "st", "nd", "rd"};
	int n = 1;
	
    while (n)
    {
        cin >> n;
        
        if (!n)
          break;
        
		if (n%100 >= 11 && n%100 <= 13)
			i = 0;
		else
		{
			switch (n%10)
			{
				case 1:
				case 2:
				case 3:
					i = n%10;
					break;
				default:
					i = 0;
			}
        }
          
      cout << "The " << n << suf[i] << " humble number is " << res[n-1] << "." << endl;
    }
    
    return 0;
}
