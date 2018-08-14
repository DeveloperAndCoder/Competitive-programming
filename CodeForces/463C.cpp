#include<iostream>
#include<vector>
#include<cstring>
#include<utility>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

bool check(int curr, int n)
{
    return (curr < n && curr >= 0);
}

template<class T>
void print(vector< vector<T> > a, int n)
{
    forn(i,0,n)
    {
        forn(j,0,n) cout << a[i][j] << " ";
        cout << endl;
    }
}

void calc_sum(const vector< vector<int> > &a, vector< vector<ll> > &sum, int n)
{
    vector< vector<ll> > sum1(n, vector<ll>(n,0LL));
    //memset(sum1, 0, sizeof(sum1[0][0])*n*n);
    for(int i = 0; i < n; i++)
    {
        int curr_i = 0, curr_j = i;
        while(check(curr_i,n) && check(curr_j,n))
        {
            sum1[0][i] += a[curr_i][curr_j];
            curr_i++;
            curr_j++;
        }
    }
    for(int i = n-1; i > 0; i--)
    {
        int curr_i = i, curr_j = 0;
        while(check(curr_i,n) && check(curr_j,n))
        {
            sum1[i][0] += a[curr_i][curr_j];
            curr_i++;
            curr_j++;
        }
    }
    //print<ll>(sum1,n);
    //cout << endl;
    ///////////////////////////////////////////////////
    for(int i = 0; i < n; i++)
    {
        int curr_i = 0, curr_j = i;
        while(check(curr_i,n) && check(curr_j,n))
        {
            //sum1[0][i] += a[curr_i][curr_j];
            sum[curr_i][curr_j] = sum1[0][i];
            curr_i++;
            curr_j++;
        }
    }
    for(int i = n-1; i > 0; i--)
    {
        int curr_i = i, curr_j = 0;
        while(check(curr_i,n) && check(curr_j,n))
        {
            //sum1[i][0] += a[curr_i][curr_j];
            sum[curr_i][curr_j] = sum1[i][0];
            curr_i++;
            curr_j++;
        }
    }
    /////////////////////////////////////////////////
    //print<ll>(sum,n);
    //cout << endl;
    for(int i = 0; i < n; i++)
    {
        sum1[0][i] = 0;
        int curr_i = 0, curr_j = i;
        while(check(curr_i,n) && check(curr_j,n))
        {
            sum1[0][i] += a[curr_i][curr_j];
            //sum[curr_i][curr_j] = sum1[i][0];
            curr_i++;
            curr_j--;
        }
    }
    for(int i = n-1; i > 0; i--)
    {
        sum1[i][n-1] = 0;
        int curr_i = i, curr_j = n-1;
        while(check(curr_i,n) && check(curr_j,n))
        {
            sum1[i][n-1] += a[curr_i][curr_j];
            //sum[curr_i][curr_j] = sum1[i][0];
            curr_i++;
            curr_j--;
        }
    }
    //print<ll>(sum1,n);
    //cout << endl;
    //////////////////////////////////////////////////////
    for(int i = 0; i < n; i++)
    {
        int curr_i = 0, curr_j = i;
        while(check(curr_i,n) && check(curr_j,n))
        {
            //sum1[0][i] += a[curr_i][curr_j];
            sum[curr_i][curr_j] += sum1[0][i];
            curr_i++;
            curr_j--;
        }
    }
    for(int i = n-1; i > 0; i--)
    {
        int curr_i = i, curr_j = n-1;
        while(check(curr_i,n) && check(curr_j,n))
        {
            //sum1[i][0] += a[curr_i][curr_j];
            sum[curr_i][curr_j] += sum1[i][n-1];
            curr_i++;
            curr_j--;
        }
    }
    forn(i,0,n)
    {
        forn(j,0,n)
        {
            sum[i][j] -= a[i][j];
        }
    }
    //print<ll>(sum,n);
    ///////////////////////////////////////////////////////
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(n,0));
    vector< vector<ll> > sum(n, vector<ll>(n,0LL));

    //memset(sum, 0, sizeof(sum[0][0])*n*n);

    forn(i,0,n)
    forn(j,0,n)
    cin >> a[i][j];

    calc_sum(a,sum,n);
    //print<ll>(sum,n);
    //cout << endl;
    ll sum1 = 0, sum2 = 0;
    pair<int, int> p1, p2;

    forn(i,0,n)
    {
        forn(j,0,n)
        {
            if(((i+j)%2 == 0) && sum[i][j] >= sum1)
            {
                p1.first = i;
                p1.second = j;
                sum1 = sum[i][j];
            }
            else if((i+j)%2 != 0 && sum[i][j] >= sum2)
            {
                p2.first = i;
                p2.second = j;
                sum2 = sum[i][j];
            }
        }
    }
    cout << sum1 + sum2 << '\n';
    cout << p1.first+1 << " " << p1.second+1 << " " << p2.first+1 << " " << p2.second+1;
    return 0;
}
