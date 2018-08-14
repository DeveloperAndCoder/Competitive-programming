#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

void call(vector<int> &ans, ll &sum, int n)
{
    ll len = n;
    ll j = len-1;
    while(j >= 0 && sum > 0)
    {
        if(sum >= j+1)
            {
                if(ans[j] == 2)
                {
                    j--;
                    continue;
                }
              //  cout << " cut = " << j+1 << " " << sum << " ";
                sum -= (j+1);
                ans[j] = 1;
                j--;
            }
        else
        {
            //cout << "remaining " << sum << " j+1 = " << j+1 << endl;
            if(ans[sum-1] == 2)
            {
                if(sum > 2)
                {
                    ans[sum-2] = 1;
                    ans[0] = 1;
                    sum = 0;
                }
                else
                {
                    if(sum == 1)
                    {
                        ans[j+1] = 0;
                        ans[j] = 1;
                        ans[1] = 1;
                        sum = 0;
                    }
                    if(sum == 2)
                    {
                        ans[j+1] = 0;
                        ans[j] = 1;
                        ans[2] = 1;
                        sum = 0;
                    }
                }
            }
            else
            {
               // cout << "in" << ans[sum-1] << endl;
                ans[sum-1] = 1;
                sum = 0;
            }
        }
    }
    return;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        ll x, n;
        cin >> x >> n;
        vector<int> ans(n, -1);
        ans[x-1] = 2;
        ll sum = (ll)((n*(n+1))/2);
        sum -= x;
        if((sum & 1) || n == 2 || n == 3)
        {
            cout << "impossible";
        }
        else
        {
         //   ll su = (n*(n+1))/2;
            //cout << su << " " << n << " ";
           // cout << sum << endl;
            sum /= 2;
           // cout << "SUM = " << sum << endl;
            call(ans, sum, n);
                forn(i,0,n)
                {
                    if(ans[i] == -1) cout << "0";
                    else cout << ans[i];
                }
        ////////////////////Testing///////////////////////////////
            /*
            ll sum1 = 0, sum2 = 0;
            for(int i = 0; i < n; i++)
                {
                   // cout << ans[i] << " ";
                    if(ans[i] == 1)
                        {
                            sum1+=(i+1);
                            //cout << i+1 << " in " << sum1 << '\n';
                        }
                    else if(ans[i] == 0)
                        sum2 += (i+1);
                }
                */
                //cout << n << " " << x;
        }
        cout << '\n';
    }
    return 0;
}
