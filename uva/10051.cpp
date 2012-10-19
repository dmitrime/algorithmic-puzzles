#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct cube
{
    int face;
    int up, down;
    int from;
    int id;
    int res;
};
cube cb[501*6];
static char* direzione[] = {"front", "back", "left", "right", "top", "bottom"};

int solve(int N)
{
      for (int i = 6; i < N*6; i++)
        for (int j = 0; j < i; j++)
          if (cb[i].id != cb[j].id)
            if (cb[i].up == cb[j].down)
              if (cb[i].res < cb[j].res+1)
              {
                  cb[i].res = cb[j].res+1;
                  cb[i].from = j;
              }
            
       int mx = 1;
       int ind = 0;
       for (int i = 0; i < N*6; i++)
       {
            if (mx < cb[i].res)
            {
                mx = cb[i].res;
                ind = i;
            }
       }
       
       cout << mx << endl;
       return ind;
}

void print(int N)
{
    if (cb[N].from == -1)
    {
        cout << cb[N].id << " " << direzione[cb[N].face] << endl;
        return;
    }
    
    print(cb[N].from);
    cout << cb[N].id << " " << direzione[cb[N].face] << endl;
}

int main()
{
        int cases = 1;
		bool b = false;
		while (1)
		{
				int N;
				cin >> N;
				if (!N)
						break;

				if (b)
					cout << endl;
				b = true;

				for (int i = 0; i < N; i++)
				{
                    int a, b;
                    for (int j = 0; j < 6; j += 2)
                    {
                      cin >> a >> b;
                      cb[6*i+j].up = a;
                      cb[6*i+j].down = b;
                      cb[6*i+j].from = -1;
                      cb[6*i+j].res = 1;
                      cb[6*i+j].id = i+1;
                      cb[6*i+j].face = j;
                      
                      cb[6*i+j+1].up = b;
                      cb[6*i+j+1].down = a;
                      cb[6*i+j+1].from = -1;
                      cb[6*i+j+1].res = 1;
                      cb[6*i+j+1].id = i+1;
                      cb[6*i+j+1].face = j+1;
                    }
				}
				
				cout << "Case #" << cases << endl;
				cases++;
				print(solve(N));
		}

		return 0;
}

