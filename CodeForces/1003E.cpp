#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n, d, k;
    cin >> n >> d >> k;
    if(d >= n)
    {
        cout << "NO";
        return 0;
    }
    int deg[n];
    forn(i,0,n) deg[i] = 0;
    vector<pair<int,int> > ans;
    priority_queue<pair<int,int> > q;
    forn(i,0,d)
    {
        deg[i]++;
        deg[i+1]++;
        ans.push_back({i, i+1});
    }
    forn(i,0,d+1)
    {
        if(deg[i] > k)
        {
            cout << "NO";
            return 0;
        }
        if(i!=0 && i != d)
        q.push({max(i,d-i), i});
    }
    int v = d+1;
    while(v < n && !q.empty())
    {
        auto u = q.top();
        //cout << u.second << " " << deg[u.second] << endl;
        if(deg[u.second] == k || u.first == d)
        {
            q.pop();
            continue;
        }
        if(deg[u.second] > k || u.first > d)
        {
            cout << "NO";
            return 0;
        }
        //cout << v << " " << u.second << endl;
        deg[u.second]++;
        deg[v]++;
        q.push({u.first+1, v});
        ans.push_back({v,u.second});
        v++;
    }
    if(v < n)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for(auto v : ans)
    {
        cout << v.first+1 << " " << v.second+1 << endl;
    }
    return 0;
}
