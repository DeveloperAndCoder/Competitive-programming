//Kadane's algorithm

#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

ll MaxSubArray(const vector<ll>& a, ll size, ll k)
{
    ll max_so_far = a[0];
    ll curr_max = a[0];
    ll p1 = 0, p2 = 0;
    forn(i,1,size*k)
    {
        curr_max = max((ll)a[i%size], curr_max+a[i%size]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll sum = 0;
        forn(i,0,n)
        {
         cin >> a[i];
         sum += a[i];
        }
        ll take1 = MaxSubArray(a,n,2);
        if(sum < 0 && k != 1)
        {
            cout << max(take1,MaxSubArray(a,n,1))<<endl;
        }
        else if(k == 1)
        {
            cout << MaxSubArray(a,n,1) << endl;
        }
        else
        {
            ll ans = 0;
            int i = n-1;
            ll sum1 = 0;
            ll ma = a[n-1];
            for(i; i >= 0; i--)
            {
                sum1 += a[i];
                if(sum1 > ma)
                    ma = sum1;
            }
            ans = ma;
            ans += sum*(k-2);
            sum1 = 0;
            ma = a[0];
            for(i = 0; i < n; i++)
            {
                sum1 += a[i];
                if(sum1 > ma)
                    ma = sum1;
            }
            ans += ma;
            cout << max(max(take1,ans), MaxSubArray(a,n,1))<<endl;
        }
    }
    return 0;
}
