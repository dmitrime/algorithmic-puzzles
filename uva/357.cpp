#include <iostream>

using namespace std;

const int SZ = 30000;
int values[] = {1, 5, 10, 25, 50};
unsigned long long lin[SZ+1];
//int input[SZ+1];

int main()
{
    lin[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= SZ; j++)
          if (j - values[i] >= 0)
            lin[j] += lin[j - values[i] ];
    }
    
    unsigned s = 0;
    //while (cin >> input[s++])
      //if (input[s-1] == 0) break;;
   // for (int i = 0; i < s; i++)
   while (cin >> s)
      if (lin[ s ] != 1)
        cout << "There are " << lin[ s ] << " ways to produce " << s << " cents change." << endl;
      else
        cout << "There is only 1 way to produce " << s << " cents change." << endl;
    
    //while (cin.get() == '\n');
    return 0;
}
