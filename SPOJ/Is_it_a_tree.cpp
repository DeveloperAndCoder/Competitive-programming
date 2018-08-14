#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int> v[], int n, int u, bool vis[])
{
    for(int i = 0; i < v[u].size(); i++)
    {
        if(!vis[v[u][i]])
        {
            vis[v[u][i]] = true;
            dfs(v, n, v[u][i], vis);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    if(n != m+1)
    {
        cout << "NO";
        return 0;
    }
    vector<int> v[n];
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    bool vis[n];
    for(int i = 0; i < n; i++)
        vis[i] = false;
    vis[0] = true;
    dfs(v, n, 0, vis);
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
