#include<iostream>
#include<vector>
using namespace std;
long long ans = 0;
void dfs_vis(vector<int> v[], int u, int n, bool vis[]);
void dfs(vector<int> v[], int u, int n, bool vis[])
{
    for(int l = 0; l < n; l++)
    {
        if(!vis[l])
        {
            ans++;
            vis[l] = true;

            if(v[l].size() != 0)
            {
                dfs_vis(v, l, n, vis);
            }
        }

    }
}

void dfs_vis(vector<int> v[], int u, int n, bool vis[])
{
     for(int i = 0; i < v[u].size(); i++)
            {
                if(!vis[v[u][i]])
                {
                    vis[v[u][i]] = true;
                    dfs_vis(v, v[u][i], n, vis);
                }
            }
}

int main()
{
    int test;
    cin >> test;
    for(int k = 1; k <= test; k++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v[n];
        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool vis[n];
        for(int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        dfs(v, 0, n, vis);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
