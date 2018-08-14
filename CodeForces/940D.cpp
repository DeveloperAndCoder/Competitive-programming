#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;
#define M 1000000000
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    forn(i,0,n) cin >> a[i];
    string b;
    cin >> b;
    ll l = -M,r=M;
    ll cur_l = -M,cur_r = M;
    forn(i,4,n)
    {
        cur_l = -M;
        cur_r = M;
        if(b[i-4] == '0' && b[i-3]=='0'&&b[i-2]=='0'&&b[i-1]=='0' && b[i]=='1')
        {
            cur_l = max(a[i-4],a[i-3]);
            cur_l = max(cur_l, a[i-2]);
            cur_l = max(cur_l, a[i-1]);
            cur_l = max(cur_l, a[i]);
          //  cout << "cur_l = " << cur_l << " " << l << endl;
            l = max(l,cur_l+1);
        }
        else if(b[i-4] == '1' && b[i-3]=='1'&&b[i-2]=='1'&&b[i-1]=='1' && b[i] == '0')
        {
            cur_r = min(a[i-4],a[i-3]);
            cur_r = min(cur_r, a[i-2]);
            cur_r = min(cur_r, a[i-1]);
            cur_r = min(cur_r, a[i]);
            r = min(r,cur_r-1);
            //cout << "cur_r = " << cur_r << " " << r << endl;
        }
        if(r < l) r = l;
        //cout << l << " blah " << r << endl;
    }
    cout << l << " " << r;
    return 0;
}
