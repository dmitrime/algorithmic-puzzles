#include <iostream>
#include <stack>
using namespace std;

char G[200][200];
char use[200];

int color(int N)
{
    stack<int> st;
    unsigned char c = 0;
    use[0] = c;
    st.push(0);
    while (!st.empty())
    {
        int k = st.top();
        c = ~use[k];
        st.pop();
        
        /*cout << "# " << k << " col " << (int)use[k] << endl;*/
        
        for (int i = 0; i < N; i++)
        {
          if (G[k][i] == 0)
            continue;
            
          if (use[i] == -1)
          {
            use[i] = c;
            st.push(i);
          }
          else if (use[i] == use[k])
            return 1;
        }

    }
    return 0;
}

int main()
{
    while (1)
    {
        int N, E;
        cin >> N;
        if (!N)
          break;
        cin >> E;
        
        for (int i = 0; i < N; i++)
        {
          use[i] = -1;
          for (int j = 0; j < N; j++)
            G[i][j] = 0;
        }
        
        for (int i = 0; i < E; i++)
        {
            int z, x;
            cin >> z >> x;
            G[z][x] = 1;
            G[x][z] = 1;
        }
        
        if (color(N))
          cout << "NOT BICOLORABLE." << endl;
        else
          cout << "BICOLORABLE." << endl;
          
        /*for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
              cout << (int)G[i][j] << " ";
            cout << endl;
        }*/
    }
    
    return 0;
}


