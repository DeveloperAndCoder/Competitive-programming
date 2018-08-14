#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;

const int N = 10000001;
int count[N];
bool prime[N];
ll pre[N];
ll f[N];

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(prime, 1, sizeof(prime));
    memset(f, 0, sizeof(f));
    memset(count, 0, sizeof(count));

    int n;
    cin >> n;
    int x[n];
    forn(i,0,n) cin >> x[i];
    forn(i,0,n)
    count[x[i]]++;
    for(int p = 2; p*p < N; p++)
    {
        if(prime[p])
        {
            for(int i = p*2; i<N; i+=p)
            prime[i] = false;
        }
    }
    for(int i = 2; i < N; i++)
    {
        if(prime[i])
        {
            for(int k = i; k < N; k+=i)
            {
                f[i] += count[k];
            }
        }
    }
    forn(i,0,N)
        pre[i] = f[i]+pre[i-1];
    int m;
    cin >> m;
    while(m--)
    {
        ll l,r;
        cin >> l >> r;
        if(r >= N) r = N-1;
        if(l >= N) l = N-1;
        cout << pre[r]-pre[l-1] << '\n';
    }
    return 0;
}
