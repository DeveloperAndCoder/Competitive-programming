#include<iostream>
#include<vector>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

//int o;
void update(vector<int> &h,const int &x,const int &y, ll &ans, bool vis[], const int n, vector<int> x_c[])
{
    //o++;
    if(x < n && vis[x]) {
  //      cout << "LSKAJD\n\n\n\n";
            return;
    }
    int x1 = (x & (-x));
    if(x < n && h[x] > 0)
    {
        h[x] -= y;
        vis[x] = true;
    //    cout << "x = " << x << endl;
        //cout << x << " " << h[x] << endl;
        if(h[x] <= 0) ans--;
    }
    for(x1 = max(1,x1); x1 <= x; x1<<=1)
    {
        if((x1 & x) == x1)
        {
          // x_c[x].push_back(x^x1);
           update(h, x^x1, y, ans, vis, n, x_c);
        }
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q, x, n, y;
    cin >> n;

    vector<int> h(n);
    forn(i,0,n)
    {
        cin >> h[i];
       // h[i] = 1;
    }

    cin >> q;

    ll ans = n;
    vector<int> x_c[n];
    bool vis[n];
    //int h1 = n;//
    int g = 1;
    while(g < n)
    {
        g <<= 1;
    }
    g--;
    while(q--)
    {
        memset(vis, false, sizeof(vis));
        cin >> x >> y;
        //cout << g << " ";
        x = x & g;
        //cout << x << " ";
        update(h, x, y, ans, vis, n, x_c);
        //cout << "o " << o << " ";
        cout << ans << '\n';
    }
    return 0;
}
