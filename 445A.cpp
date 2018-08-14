#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j;
    cin >> n >> m;
    char grid[n][m];

    for(i=0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>grid[i][j];

    bool v = true;
    for(i = 0; i < n; i++)
    {
        if(i%2 == 0)
            v = true;
        else
            v = false;
        for(j = 0; j < n; j++)
        {

            if(i % 2 == 0)
            {
                if(grid[i][j] == '-')
                    {
                    cout << "-";
                    if(v)
                      v = 0;
                    else
                      v = 1;
                    }

                else
                {
                    if(v)
                    {
                    cout << "W";
                    v = 0;
                    }
                    else
                    {
                        cout << "B";
                        v = 1;
                    }
                }
            }
            else
            {
                if(grid[i][j] == '-')
                {
                    cout << "-";
                    if(v)
                    v = 0;
                    else v=1;
                }
                else
                {
                    if(v)
                    {
                    cout << "W";
                    v = 0;
                    }
                    else
                    {
                        cout << "B";
                        v = 1;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}
