/*
   Articulation points
   undirected graph
   connected graph
   nodes are numbered from 1 to n
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n';

const int MXSIZE = 10001;


int parent [MXSIZE];
int child  [MXSIZE];
int low    [MXSIZE];
int tym    [MXSIZE];
bool seen  [MXSIZE];
bool is_cut[MXSIZE];

vector <int > adj [MXSIZE]; //adjacency graph
int ans = 0;
/*
low[u] => the highest ancestor(identified by its smallest discovery time) of u that can be reached from a descendant of u by using back-edges.
*/
vector<pair<int,int> > bridge;
void dfs(int s)
{
    static int c = 0;
    seen[s] = true; // Mark as visited
    low[s] = tym[s] = c++;
    for(int i = 0; i < adj[s].size(); i++)
    {
        int curr = adj[s][i];
        if(curr == parent[s])
        {
            continue;       // Do nothing
        }
        if(!seen[curr])
        {
            child[s]++;
            parent[curr] = s;
            dfs(curr);
            low[s] = min(low[curr], low[s]);
            if(s != 1 && low[curr] >= tym[s])
            is_cut[s] = true;
        }
        else
        {
            low[s] = min(low[s], tym[curr]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t)
    {
        ans = 0;
        for(int i = 0; i < MXSIZE; i++)
        {
            adj[i].clear();
            seen[i] = false;
            parent[i] = -1;
            low[i] = INT_MAX;
            tym[i] = INT_MAX;
            child[i] = 0;
            is_cut[i] = false;
        }

        int n,m;

        cin>>n>>m;  // no. of vertices and edges
        if(n == 0 && m == 0) return 0;

        for(int i=1; i<=m; i++)
        {
            int a,b;
            // undirected edge between a and b
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        parent[1]=-1;
        dfs(1);

        /* the vertex from where we started dfs
           must have atleast two independent children
           otherwise it is not a cut vertex  */
        is_cut[1]= child[1]>1 ? true : false;
        //cout << child[1] << endl;
        for(int i = 1; i <= n; i++) if(is_cut[i]) ans++;

        cout << ans << endl;
    }
    return 0;
}
