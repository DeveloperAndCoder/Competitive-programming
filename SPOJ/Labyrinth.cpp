#include<iostream>
using namespace std;

int m = 0;

void dfs(char** arr, int n, int m, int i, int j, bool** vis, int d)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.' && !vis[i][j])
            {
                vis[i][j] = true;
                if(i < n-1 && arr[i+1][j] == '.')
                {
                    d++;
                    if(m < d)
                        m = d;
                    vis[i+1][j] = true;
                    dfs(arr, n, m, i+1, j, vis, d);
                    d--;
                }
                else if(j < n-1 && arr[i][j+1] == '.')
                {
                    d++;
                    if(m < d)
                        m = d;
                    vis[i][j+1] = true;
                    dfs(arr, n, m, i, j+1, vis, d);
                    d--;
                }
                else if(i == n-1 && j < n-1 && arr[i][j+1] == '.' && !vis[i][j+1])
                {
                    vis[i][j+1] = true;
                    d++;

                }

            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    char** arr = new char*[n];
    bool** vis = new bool*[n];

    for(int i = 0; i < n; i++)
    {
        *(arr+i) = new char[m];
        *(vis+i) = new bool[m];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        cin >> arr[i][j];
        vis[i][j] = false;
    }
    int d = 0;
    vis[0][0] = true;
    dfs(arr, n, m, 0, 0, vis, d);
    cout << ::m;
    return 0;
}
