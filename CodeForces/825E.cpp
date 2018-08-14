#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v[n];
    int node,edge;
    for(int i = 0; i < m; i++)
    {
        cin >> node >> edge;
        v[node-1].push_back(edge-1);
    }
    int ans[n] = {0};
    int pos = 0;
    bool check[n] = {false};

    for(int j = n-1; j >= 0; j--)
    {
        for(int i = 0; i < n; i++)
        {
            if(!check[i])
            if (v[i].size() == 0)
            {
                pos = i;
            }
        }

        ans[pos] = j+1;
        check[pos] = true;

        // Deleting the node with pos = i;
        for(int i = 0; i < n; i++)
        {
            if(i != pos)
            {
                for(int j = 0; j < v[i].size(); j++)
                {
                    if (v[i][j] == pos)
                        v[i].erase(v[i].begin() + j);
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

        return 0;
}
