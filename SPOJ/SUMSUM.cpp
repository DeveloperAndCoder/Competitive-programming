#include <iostream>
#include <math.h>

using namespace std;

#define N 1000010
#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int BIT[N][32], arr[N], n;

ll query(int idx, int x)
{
    if(idx < 0 || x <= 0) return 0LL;
    ll ret = 0;
    for(x; x > 0; x -= x&-x)
        ret += BIT[x][idx];
    return ret;
}

void update(int x, int val)
{
    int idx = x;
    for(x; x<=n; x += x&-x)
    {
        for(int i = 0; i < 32; i++)
        {
            int add = 0;
            if(val & (1<<i)) add++;
            if(arr[idx] & (1<<i)) add--;
            BIT[x][i] += add;
            //cout << x << " " <<  i << " add = " << add  << " " << BIT[x][i] << endl;//((val & (1<<i)) << " " <<  (arr[x] & (1<<i))) << endl;
        }
    }
    arr[idx] = val;
    return;
}

ll C(ll n)
{
    return (n*(n-1))/2;
}

int main()
{
    boost;
    for(int i = 0; i < N; i++)
        forn(j,0,32) BIT[i][j] = 0LL;
    int q;
    cin >> n >> q;
    forn(i,1,n+1) {
        int val;
        cin >> val;
        update(i, val);
        arr[i] = val;
    }
    while(q--)
    {
        int dir;
        cin >> dir;
        if(dir == 1)
        {
            int x, i;
            cin >> x >> i;
            //cout << query(1, 4) << " " << BIT[4][1] << endl;
            update(i, x);
            //cout << query(1, 4) << " " << BIT[4][1] << endl;
        }
        else
        {
            string instr;
            cin >> instr;
            int qs,qe;
            cin >> qs >> qe;
            ll result = 0LL, len = qe-qs+1;
            if(instr == "OR")
            {
                ll one = 0, zero = 0;
                for(int idx = 0; idx < 32; idx++)
                {
                    one = query(idx, qe) - query(idx, qs-1);
                    zero = len - (query(idx, qe) - query(idx, qs-1));
                    result += (C(len)-C(zero))*(1<<idx);
                    //cout << idx << " " << zero << " " << result << endl;
                }
            }
            else if(instr == "AND")
            {
                ll one = 0, zero = 0;
                for(int idx = 0; idx < 32; idx++)
                {
                    one = query(idx, qe) - query(idx, qs-1);
                    zero = len - (query(idx, qe) - query(idx, qs-1));
                    result += (C(one))*(1<<idx);
                    //cout << idx << " " << zero << " " << result << endl;
                }
            }
            else
            {
                ll one = 0, zero = 0;
                for(int idx = 0; idx < 32; idx++)
                {
                    one = query(idx, qe) - query(idx, qs-1);
                    zero = len - (query(idx, qe) - query(idx, qs-1));
                    result += (one*zero)*(1<<idx);
                    //cout << idx << " " << zero << " " << result << endl;
                }
            }
            cout << result << endl;
        }
    }
    return 0;
}
