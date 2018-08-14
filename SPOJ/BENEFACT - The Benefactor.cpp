#include<iostream>
#include<vector>
using namespace std;

int m = 0;
int index = 0;

void dfs_vis(vector< pair<int,int> > v[], int u, int n, bool vis[], int& d);
void dfs(vector< pair<int,int> > v[], int u, int n, bool vis[], int& d)
{
    for(int l = 0; l < n; l++)
    {
        if(!vis[l])
        {
            vis[l] = true;
            d = 0;
            if(v[l].size() != 0)
            {
                dfs_vis(v, l, n, vis, d);
            }
        }

    }
}

void dfs_vis(vector< pair<int,int> > v[], int u, int n, bool vis[], int& d)
{
     for(int i = 0; i < v[u].size(); i++)
            {
                if(!vis[v[u][i].first])
                {
                    d += v[u][i].second;
                    if(m < d)
                    {
                        m = d;
                        index  = v[u][i].first;
                    }
                    vis[v[u][i].first] = true;
                    dfs_vis(v, v[u][i].first, n, vis, d);
                    d -= v[u][i].second;
                }
            }
}

int main()
{
    int test;
    cin >> test;
    for(int k = 1; k <= test; k++)
    {
        int n;
        cin >> n;
        vector< pair<int, int> > v[n];
        for(int i = 0; i < n-1; i++)
        {
            int a,b,d;
            cin >> a >> b >> d;
            v[a-1].push_back(make_pair(b-1,d));
            v[b-1].push_back(make_pair(a-1,d));
        }
        bool vis[n];
        for(int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        int d = 0;
        dfs_vis(v, 0, n, vis, d);

        for(int i = 0; i < n; i++)
        {
            vis[i] = false;
        }

        m = 0;
        d = 0;
        dfs_vis(v, index, n, vis, d);

        cout << m << endl;
        m = 0;
    }
    return 0;
}
