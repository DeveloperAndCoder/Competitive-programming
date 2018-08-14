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

#define M 1000000000
const int mod = 1000000007;

using namespace std;

int main()
{
    ll k, d, t;
    cin >> k >> d >> t;
    if(k%d == 0)
    {
        cout << t;
        return 0;
    }
    double cyclework;
    double time;
    //if(d < k)
    {
        time = (k/d+1)*d;
        //cout << time << endl;
        cyclework = k*2 + ((k/d+1)*d-k);
        //cout << cyclework << endl;
        ll cycles = ((2*t) / cyclework);
        //cout << cycles << endl;
        double work = cycles*cyclework;
        time = time*cycles;
        //cout << work << endl;
        double rem_work = (2*t - work);
        //cout << rem_work << endl;
        work += min(rem_work, 2.0*k);
        time += (min(rem_work, 2.0*k)/2);
        rem_work -= min(rem_work, 2.0*k);
        //cout << time << endl;
        time += rem_work;
        work += (rem_work);
        //cout << work << endl;
        cout << fixed << setprecision(10) << time;
        return 0;
    }
    /*
    else
    {
        ll x=1;
        while(((ll)(d*x)/k)%2 == 0)
            x++;
        //cout << x << endl;
        ll y = d*x/k;
        //cout << ((y/2+1)*k) << endl;
        time = ((y/2+1)*k) + (y/2)*k + (d-y*k);
        cout << time << endl;
        cyclework = 2*((y/2+1)*k) + (y/2)*k + (d-y*k);
        cout << cyclework << endl;
        ll cycles = ((2*t) / cyclework);
        cout << cycles << endl;
        double work = cycles*cyclework;
        cout << work << endl;
        time = time*cycles;
        cout << time << endl;
        double rem_work = (2*t - work);
        cout << rem_work << endl;
        ll i = 0;
        while(rem_work)
        {
            if(!i)
            {
                time += (min(rem_work, 2.0*k)/2);
                rem_work -= min(rem_work, 2.0*k);
            }
            else
            {
                time += (min(rem_work, k*1.0));
                rem_work -= min(rem_work, k*1.0);
            }
            if(i) i = 0;
            else i = 1;
        }
        cout << fixed << setprecision(10) << time;
        return 0;
    }
    */
    return 0;
}
