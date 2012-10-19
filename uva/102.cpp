#include <string>
#include <iostream>
#include <sstream>
using namespace std;

char *v[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
    string in;
    while (getline(cin, in))
    {
        int a1[3];
        int a2[3];
        int a3[3];
        istringstream ss(in);
        ss >> a1[0] >> a1[1] >> a1[2];
        ss >> a2[0] >> a2[1] >> a2[2];
        ss >> a3[0] >> a3[1] >> a3[2];
            
        int min[6];
        min[0] = a1[2]+a2[0]+a1[1]+a3[0]+a2[1]+a3[2];
        min[1] = a1[1]+a2[0]+a1[2]+a3[0]+a2[2]+a3[1];
        min[2] = a1[0]+a2[2]+a1[1]+a3[2]+a2[1]+a3[0];
        min[3] = a1[1]+a2[2]+a1[0]+a3[2]+a2[0]+a3[1];
        min[4] = a1[0]+a2[1]+a1[2]+a3[1]+a2[2]+a3[0];
        min[5] = a1[2]+a2[1]+a1[0]+a3[1]+a2[0]+a3[2];
        
        int mn = min[0];
        int ind = 0;
        for (int i = 1; i < 6; i++)
        {
          if (mn > min[i])
          {
                mn = min[i];
                ind = i;
          }
        }
        cout << v[ind] << " " << mn << endl;
        
        /*
        for (int i = 0; i < 6; i++)
          cout << min[i] << " ";
        */
        
    }
    
    return 0;
}
