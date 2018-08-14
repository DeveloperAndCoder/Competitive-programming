#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <cstring>
#include <set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MX 100001
#define pii pair<int,int>

using namespace std;

#define SIZE 100001
#define f first
#define s second
#define INF INT_MAX

vector < pair < int, int > > v [SIZE];    // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
int parent[SIZE];

void dijkstra()
{
    forn(i,0,SIZE) dist[i] = INF;// set the vertices distances as infinity
    dist[1] = 0;
    parent[1] = -1;
    multiset < pair < int, int > > s;           // multiset do the job as a min-priority queue
    s.insert({0, 1});                           // insert the source node with distance = 0
    while(!s.empty())
    {
        pair <int, int> p = *s.begin();         // pop the vertex with the minimum distance
        s.erase(s.begin());
        int x = p.s;
        int wei = p.f;
        for(int i = 0; i < v[x].size(); i++)
        {

            int e = v[x][i].f;
            int w = v[x][i].s;

            if(dist[x] + w < dist[e])             // check if the next vertex distance could be minimized
            {
                dist[e] = dist[x] + w;
                parent[e] = x;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}

void trace(int x)
{
    if(parent[x] == -1)
    {
        cout << x << " ";
        return;
    }
    trace(parent[x]);
    cout << x << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    forn(i,0,m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    dijkstra();
    stack<int> path;
    int p = n;
    if(dist[n] == INF)
    {
        cout << -1;
        return 0;
    }
    trace(n);
    return 0;
}
