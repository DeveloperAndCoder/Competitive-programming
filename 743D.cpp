#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<algorithm>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

const int N = 200001;
const int M = 1000000001;
vector<int> v[N];
ll ss[N],mx1,mx2;
vector<ll> sum;
vector<ll> mx;
ll ans;

void print(ll a[], int n)
{
    cout << "\n----------------\n";
    forn(i,0,n)
    cout << i << " " << a[i] << "\n";
    cout << "----------------\n";
    return;
}
void print(vector<ll> a, int n)
{
    cout << "\n----------------\n";
    forn(i,0,n)
    cout << i << " " << a[i] << "\n";
    cout << "----------------\n";
    return;
}
void dfs(int u, int par, int a[], int n)
{
    //cout << u << " " << ss[u] << " ";
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dfs(x, u, a, n);
        ss[u] += ss[x];
        //mx1 = max(ss, mx1);
    }
    ss[u] += a[u];
    /*
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        ss[u] += ss[x];
    }
    int idx;
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        mx1 = max(ss[x],mx1);
        idx = x;
    }
    */
    //cout << u << " " << ss[u] << endl;
    return;
}

void dfs2(int u, int par, int a[], int n)
{
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dfs2(x, u, a, n);
        mx[u] = max(mx[u], mx[x]);
    }
    mx[u] = max(mx[u], ss[u]);
    //cout << u << " " << mx[u] << " " << v[u].size() << endl;
    return;
}

void dfs3(int u, int par, int a[], int n)
{
    vector<ll> cmx;
    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        cmx.eb(mx[x]);
        sort(cmx.begin(), cmx.end(), greater<ll>());
        if(cmx.size() == 3)
            cmx.pop_back();

    }

    if(cmx.size() == 2)
    ans = max(cmx[0]+cmx[1], ans);

    forn(i,0,v[u].size())
    {
        int x = v[u][i];
        if(x == par) continue;
        dfs3(x, u, a, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    mx.resize(n);
    forn(i,0,n) mx[i] = -M-1;
    int a[n];
    forn(i,0,n) cin >> a[i];
    forn(i,0,n-1)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].eb(b);
        v[b].eb(a);
    }
    bool possible = false;
    forn(i,0,n)
    {
        if(i == 0 && v[i].size() > 1)
        {
            possible = 1;
            break;
        }
        else if(v[i].size() > 2)
        {
            possible = 1;
            break;
        }
    }
    if(!possible)
    {
        cout << "Impossible";
        return 0;
    }
    ans = -2*M-1;
    dfs(0, -1, a, n);
    //print(ss, n);
    dfs2(0, -1, a, n);
    //print(mx, n);
    dfs3(0, -1, a, n);

    cout << ans;
    /*
    int root = 0, par = -1;
    if(v[root].size() == 1)
    {
        root=v[0][0];
        par = 0;
    }
    if(v[0].size() == 1)
        while(root < n && v[root].size() == 2)
        {
      //      cout << root << " " << v[root].size() << " par = " << par << endl;
            if(v[root][0] == par)
                {
                    par = root;
                    root = v[root][1];
                }
            else
            {
                par = root;
                root = v[root][0];
            }
        }
    //cout << "root = " << root << " " << par << " "  << v[root].size() << endl;
    if(root >= n || v[root].size() == 1)
    {
        cout << "Impossible";
    }
    else
    {
        forn(i,0,v[root].size())
        {
            mx1 = -N;
            mx2=mx1;
            //ss = 0;
            if(v[root][i] == par) continue;
            dfs(v[root][i], root, a, n);
            //cout << v[root][i] << " " << mx1 << endl;
        }
        ll ans = -N-1, mx = -N-1, idx = -1;
        forn(i,0,sum.size())
        {
            if(ans < sum[i])
            {
                ans = sum[i];
                idx = i;
            }
        }
        forn(i,0,sum.size())
        {
            if(i != idx && mx < sum[i])
            {
                mx = sum[i];
            }
        }
        ans += mx;
        cout << ans;
    }
    */
    return 0;
}
