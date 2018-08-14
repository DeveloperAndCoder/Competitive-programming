#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define MX 100001
#define pii pair<int,int>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int dist[MX];
    forn(i,0,MX) dist[i] = -1;
    queue<pii> q;
    q.push({n,0});
    dist[n] = 0;
    while(true)
    {
        pii p = q.front();
        q.pop();
        //cout << p.first << endl;
        if(p.first == 0) continue;
        if(p.first == m)
        {
            cout << p.second;
            return 0;
        }
        dist[p.first] = p.second;
        if(p.first < m)
        {
            if(dist[p.first*2] == -1)
            {
                q.push({p.first*2, p.second+1});
            }
        }
        if(p.first > 1 && dist[p.first-1] == -1)
        {
            q.push({p.first-1, p.second+1});
        }
    }
    return 0;
}
