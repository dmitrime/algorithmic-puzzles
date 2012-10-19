#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

string MIS(vector<int> vv, int c)
{
    for (int i = 1; i < vv.size(); i++)
      vv[i] = max(vv[i], vv[i-1] + vv[i]);
      
    
    int mx = 0;
    int mm = 0;
    bool b = false;
    for (int i = 0; i < vv.size(); i++)
    {
        if (vv[i] > 0 && vv[i] > mm)
        {
            mx = i;
            mm = vv[i];
            b = true;
        }
    }
    
    /*cout << "-------------------------" << endl;
    for (int i = 0; i < vv.size(); i++)
      cout << vv[i] << " ";
    cout << endl << "-------------------------" << endl;
    */

    if (!b)
    {
        char buf[128];
        sprintf(buf, "Route %d has no nice parts", c);
        return buf;
    } 
    
    int IND = mx;
    int MXI = -1;
    while (vv[IND] >= 0 && IND >= 0) {MXI++; IND--;}
    
    for (int i = mx+1; i < vv.size(); i++)
    {
        if (vv[i] == vv[mx])
        {
            int mxi = -1;
            int ind = i;
            while (vv[ind] >= 0 && ind >= 0) {mxi++; ind--;}
            if (mxi > MXI) {MXI = mxi; mx = i;};
        }
    }
    

  
    
    char buf[128];
    sprintf(buf, "The nicest part of route %d is between stops %d and %d", c, (mx-MXI)+1, mx+2);
    return buf;
}

int main()
{
    int N = 0;
    int c = 1;
    
    cin >> N;
    while (c <= N)
    {
        int M = 0;
        cin >> M;
        vector<int> v;
        
        for (int i = 1; i < M; i++)
        {
            int x = 0;
            cin >> x;
            v.push_back(x);
        }
        
        cout << MIS(v, c) << endl;
        
        c++;
    }

    return 0;
}
