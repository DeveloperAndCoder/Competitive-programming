
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000
const int mod = 1000001;

using namespace std;

ll ff(ll v[], ll t[], ll n, ll target, int i)
{
    ll xc = t[n-1];
    if(i > 0) xc -= t[i-1];
    if(xc < v[i]) return -1LL;
    ll low = i, high = n-1; // numElems is the size of the tay i.e t.size()
    while (low != high)
    {
        int mid = (low + high) / 2; // Or a fancy way to avoid int overflow
        ll midv = t[mid];
        if(i > 0) midv -= t[i-1];
        if (midv < target) {
            /* This index, and everything below it, must not be the first element
             * greater than what we're looking for because this element is no greater
             * than the element.
             */
            low = mid + 1;
        }
        else {
            /* This element is at least as large as the element, so anything after it can't
             * be the first element that's at least as large.
             */
            high = mid;
        }
}

    return high;
}
template<class T>
void print(T a[], T day[], int n)
{
    forn(i,0,n) cout << a[i] << " " << day[i] << " , ";
    cout << endl;
}
int main()
{
    boost;
    int n;
    cin >> n;
    ll v[n], t[n];
    forn(i,0,n) cin >> v[i];
    forn(i,0,n) cin >> t[i];
    forn(i,1,n) t[i] += t[i-1];
    ll day[n];
    ll p[n];
    forn(i,0,n) p[i]=0,day[i]=0;
    forn(i,0,n)
    {
        ll xn = ff(v,t,n,v[i],i);
        p[i]++;
     //   cout << xn << " " << v[i] << endl;
        //p[xn]--;
        if(xn != -1LL)
        {
            p[xn]--;
            if(xn > i)
            {
                if(i > 0)
                day[xn] += (v[i]-(t[xn-1]-t[i-1]));
                else
                    day[xn] += (v[i]-t[xn-1]);
            }
            else
            day[xn] += v[i];
        }
    }
    //if(n == 100000)
    //print(p,day,n);
   // cout << "\n------------------\n";
   // print(day,n);

    forn(i,1,n) p[i] += p[i-1];

    day[0] += p[0]*t[0];
    forn(i,1,n)
    {
        day[i] += p[i]*(t[i]-t[i-1]);
    }
    forn(i,0,n) cout << day[i] << " ";
    return 0;
}

/*
3
10 10 5
5 7 2
*/
