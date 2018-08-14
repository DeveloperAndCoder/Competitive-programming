#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int bo, inc, damage;
    cin >> bo >> inc >> damage;
    int m_h[n];
    int s_h[n];
    int reg[n];
    forn(i,0,n) cin >> m_h[i] >> s_h[i] >> reg[i];
    int t[m], e[m], he[m];
    forn(i,0,m) cin >> t[i] >> e[i] >> he[i];
    vector<int> cross(n, -1);
    forn(i,0,n)
    {
        if(m_h[i] <= damage)
        {
            cout << -1;
            return 0;
        }
    }
    forn(i,0,n)
    {
        if(damage >= s_h[i])
            {
                cross[i] = (damage-s_h[i])/reg[i];
            }
    }
    forn(i,0,m)
    {
        if(t[i] > cross[e[i]-1] || cross[e[i]-1] == -1)
        {
            ll tm = (damage-he[i])/(reg[i]);
            tm += t[i];
            cross.push_back(tm);
        }
    }
    sort(cross.begin(), cross.end());
    int j = 0;
    ll ans = 0;
    forn(i,0,cross.size())
    {
        j = cross[i];
        int k = 0;
        while(i < cross.size() && cross[i] == j)
        {
           // cout << cross[i] << " ";
            k++;
            i++;
        }
        ans = max(ans, (ll)bo+j*inc);
    }
    cout << ans;
    return 0;
}
