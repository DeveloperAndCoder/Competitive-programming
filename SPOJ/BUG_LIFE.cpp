#include<iostream>
#include<vector>
using namespace std;
void dfs_vis(vector<int> v[], int u, int n, bool vis[], bool gen[]);
void dfs(vector<int> v[], int u, int n, bool vis[], bool gen[])
{
    for(int l = 0; l < n; l++)
    {
        if(!vis[l])
        {
            vis[l] = true;
            gen[l] = true;

            if(v[l].size() != 0)
            {
                /*
                gen[l]?gen[v[l][0]] = false: gen[v[l][0]] = true;
                vis[v[l][0]] = true;*/
                dfs_vis(v, l, n, vis, gen);
            }
        }

    }
}

void dfs_vis(vector<int> v[], int u, int n, bool vis[], bool gen[])
{
     for(int i = 0; i < v[u].size(); i++)
            {
                if(!vis[v[u][i]])
                {
                    vis[v[u][i]] = true;
                    (gen[u]) ? gen[v[u][i]] = false : gen[v[u][i]] = true;
                    //cout << v[u][i] +1 << " = v[u][i] ";
                    dfs_vis(v, v[u][i], n, vis, gen);
                }
            }
}

int main()
{
    int test;
    cin >> test;
    for(int k = 1; k <= test; k++)
    {
        int bugs, inter;
        cin >> bugs >> inter;
        vector<int> v[bugs];
        for(int i = 0; i < inter; i++)
        {
            int a,b;
            cin >> a >> b;
            v[a-1].push_back(b-1);
            v[b-1].push_back(a-1);
        }
        /*
        for(int i = 0; i < bugs; i++)
        {
            cout << "i = " << i+1 << endl;
            for(int j = 0; j < v[i].size(); j++)
            cout << v[i][j]+1 << " ";
        }
        */
        bool vis[bugs];
        bool gen[bugs];
        for(int i = 0; i < bugs; i++)
        {
            vis[i] = false;
            gen[i] = false;
        }
        //vis[0] = true;
        gen[0] = true;                      //Male : True ; Female: False
        dfs(v, 0, bugs, vis, gen);
        //cout << "out";
        for(int i = 0; i < bugs; i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                if((gen[i] && !gen[v[i][j]]) || (!gen[i] && gen[v[i][j]]))
                {
                    continue;
                }
                else
                {
                    cout << "Scenario #"<< k <<":\n";
                 // cout << "at " << i + 1<< " " << j + 1<< " " << v[i][j] +1<< endl;
                //   cout << gen[i] << " " << gen[v[i][j]] << endl;
                    cout << "Suspicious bugs found!\n";
                    goto next;
                }
            }
        }
        cout << "Scenario #" << k << ":\n";
        cout << "No suspicious bugs found!\n";
        next:;
    }
}
