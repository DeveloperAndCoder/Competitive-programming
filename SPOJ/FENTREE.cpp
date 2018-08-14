#include <iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define N 1000002

using namespace std;

ll BIT[N];

void update(int x, int val, int n)
{
    for(x; x <= n; x+=x&-x)
    {
        BIT[x] += val;
    }
}

ll query(int x)
{
    ll sum = 0ll;
    for(x; x > 0; x -= x&-x)
    {
        sum += BIT[x];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    forn(i,1,n+1)
    {
        cin >> a[i];
        update(i,a[i],n);
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        cin >> c;
        if(c == 'q')
        {
            int l,r;
            cin >> l >> r;
            cout << query(r) - query(l-1) << endl;
        }
        else
        {
            int idx, val;
            cin >> idx >> val;
            update(idx, val, n);
        }
    }
    return 0;
}
