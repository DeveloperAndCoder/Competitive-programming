#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define ll long long
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
//const ll mod=1000000007;
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

class Compare
{
public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        if(a.se < b.se)
            return true;
        return false;
    }
};

using namespace std;

int main()
{
    int n, m,a,b;
    cin >> n  >> m;
    VI v[n];
    //priority_queue<pair<int,int>, vector< pair<int,int> >, Compare> fr;
    priority_queue<pair<int,int>, vector< pair<int,int> >, Compare> nfr;
    forn(i,0,m)
    {
        cin >> a >> b;
        v[a-1].pb(b-1);
        v[b-1].pb(a-1);
    }
    forn(i,0,n)
    {
        nfr.push(make_pair(i, v[i].size()));
    }

    vector<int> ans;
    vector<bool> fr(n, false);
    vector<int> surr;
    while(!nfr.empty())
    {
        int u = nfr.top().fi;
        fr[u] = true;
        //cout << u+1 << " ";
        bool del = false;
        nfr.pop();
        forn(i,0,v[u].size())
        {
            int v_ = v[u][i];
            if(fr[v_])
                continue;
            fr[v_] = true;
            del = true;
            v[v_].erase(find(v[v_].begin(),v[v_].end(), u));
            surr.push_back(v_);
        }

        vector<int>::iterator it;
        forn(i,0,surr.size())
        {
            if(i == u)
            continue;
            forn(j,0,surr.size())
            {
                if(j == u)
                continue;
                it = find(v[surr[i]].begin(), v[surr[i]].end(), surr[j]);
                if(it != v[surr[i]].end())
                    {
      //                  cout << "del " << surr[i] << " " << surr[j] << endl;
                        v[surr[i]].erase(it);
                    }
            }
        }
        surr.clear();
        if(v[u].size() > 0 && del)
        ans.push_back(u);
    }
    //cout << endl;
    cout << ans.size() << endl;
    forn(i,0,ans.size())
    cout << ans[i]+1 << " ";
    return 0;
}
