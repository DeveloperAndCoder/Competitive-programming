#include<iostream>
#include<string>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
const int M = 1001;
const int mod = 1e9+7;
int dp1[M];
ll nCr[M][M];

int ones(int n)
{
    int num_1 = 0;
    while(n)
    {
        if(n&1) num_1++;
        n >>= 1;
    }
    return num_1;
}

void calc_ks_before_1000()
{
    dp1[1] = 0;
    forn(i,2,1001)
    {
        dp1[i] = dp1[ones(i)]+1;
    }
    return;
}

void calc_nCr()
{
    forn(i,0,1001) nCr[i][0] = 1;
    forn(i,1,1001) nCr[0][i] = 0;

    forn(i,1,1001)
    {
        forn(j,1,1001)
        {
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%mod;
        }
    }
    return;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    if(k == 0)
        {
            cout << "1";
            return 0;
        }
    calc_ks_before_1000();
    calc_nCr();
   // cout << nCr[0][0] << nCr[2][1] << endl;
    int pre_ones = 0;
    ll sum = 0;
    forn(i,0,n.length())
    {
        if(n[i] == '0')
            continue;
        forn(j,max(1, pre_ones),1001)
        {
            if(dp1[j] == k-1)
            {
                //cout << i << " " << j << " " << nCr[n.length()-1-i][j-pre_ones] << endl;
                sum = (sum+nCr[n.length()-1-i][j-pre_ones])%mod;
                if(k == 1 && i == 0)
                {
                    sum = (sum-1)%mod;
                }
            }
        }
        pre_ones++;
    }
    int num_of_1_in_n = 0;
    forn(i,0,n.length())
    {
        if(n[i] == '1') num_of_1_in_n++;
    }
    if(dp1[num_of_1_in_n] == k-1) sum++;
    cout << sum%mod;
    return 0;
}
