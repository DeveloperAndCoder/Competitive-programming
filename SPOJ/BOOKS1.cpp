#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;

bool isvalid(ll p[], int dd, int m, int k)
{
    ll sum = 0, kk=0;
    forn(i,0,m)
    {
        if(sum + p[i] <= dd)
            sum += p[i];
        else
        {
            kk++;
            sum = p[i];
        }
    }
    kk++;
    return kk<=k;
}

ll bin(ll c[], ll p[], int m, int k)
{
    ll low = c[0], high = 0;
    forn(i,k-1,m)
        high += c[i];
    while(low < high)
    {
        if(low == high-1)
        {
            if(isvalid(p,low, m, k)) {
                    cout << "returning low = " << low << endl;
                    return low;
            }
            cout << "returning high = " << high << endl;
            return high;
        }
        ll mid = (low+high)/2;
        cout << "work = " << mid << " ";
        if(isvalid(p,mid, m, k))
        {
            cout << "is valid" << endl;
            high = mid;
        }
        else{
                cout << "is not valid\n";
                low = mid+1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int m,k;cin >> m >> k;
        ll p[m],c[m];
        forn(i,0,m)
        {
            cin >> p[i];
            c[i]=p[i];
        }
        sort(c,c+m);
        ll prt = bin(c,p,m,k);
        ll sum = 0, kl = 0;
        ll ans[m+k-1];
        int j = 0;
        for(int i = m-1; i >= 0; i--)
        {
            if(sum + p[i] <= prt)
            {
                sum += p[i];
                ans[j++] = p[i];
            }
            else
            {
                kl++;
                //cout << "/ " << p[i] << " ";
                ans[j++] = -1;
                ans[j++] = p[i];
                sum = p[i];
            }
        }
        if(kl < k-1)
        {
            cout << p[m-1];
        }
        cout << endl;
    }
}
