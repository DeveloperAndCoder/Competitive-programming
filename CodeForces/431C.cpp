#include <iostream>
#include <vector>
#include <queue>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007
#define pb push_back
#define em emplace_back
#define mk make_pair
#define fr first
#define sc second

using namespace std;

int findit(int n, int k, int d)
{
    queue< pair<int,bool> > q;
    vector< vector<int> > sum(101, vector<int>(2) );
    forn(i,0,101)
    {
        sum[i][0] = -1;
        sum[i][1] = -1;
    }
    sum[0][0] = 0;
    sum[0][1] = 0;
    //sum.pb(mk(0,0));
    int ans = 0;
    q.push(mk(0,0));
    while(!q.empty())
    {
        pair<int,bool> u = q.front();
        q.pop();
        //cout << u.fr << " " << u.sc << " " << ans << endl;

        if(u.fr > n)
        {
           // cout << "Continued\n";
            continue;
        }

        if(sum[u.fr][u.sc] != -1)
        {
            ans += sum[u.fr][u.sc];
            continue;
        }

        if(u.fr == n)
        {
            if(u.sc)
            ans ++;
            ans %= mod;
            continue;
        }
        forn(i,1,k+1)
        {
            q.push(mk(u.fr+i, (u.sc|(i>=d))));
        }
    }
    return ans;
}

int main()
{
    int n,k,d;
    cin >> n >> k >> d;
    int ans = findit(n,k,d);
    cout << ans;
    return 0;
}
