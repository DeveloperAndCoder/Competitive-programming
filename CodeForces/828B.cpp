#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    char grid[n][m];
     int i_min = n;
    int j_min = m;
    int i_max = -1;
    int j_max = -1;
    int bs = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
           {
               if(grid[i][j] == 'B')
               {
                   bs++;
                   if(i < i_min)
                    i_min = i;
                   if(i > i_max)
                    i_max = i;
                   if(j < j_min)
                    j_min = j;
                   if(j > j_max)
                    j_max = j;
               }
           }
    }
            int maxi = i_max-i_min;
        if(j_max-j_min > maxi)
            maxi = j_max - j_min;
    if(j_min == -1 || j_max == -1 || i_min == -1 || i_max == -1)
    {
        cout << 1;
        return 0;
    }
    else if(maxi < n && maxi < m)
    {
            maxi++;
        cout << maxi*maxi-bs;
    }
    else
        cout << -1;

    return 0;
}
