#include<iostream>
#include<stack>
#include<math.h>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

const int N = 1e5*5+1;
ll num_of_nodes=1;
int t[2000000];

int gcd(int x, int y)
{
    return y == 0? x : gcd(y, x%y);
}

void build()
{
    for(int i = num_of_nodes-1; i > 0; i--)
        t[i] = gcd(t[i<<1],t[i<<1|1]);
}
void modify(int p, int value)
{
    for(t[p+=(num_of_nodes-1)] = value; p > 1; p>>=1)
        t[p>>1] = gcd(t[p],t[p^1]);
}
void query(int root, int l, int r, int u, int v, int x, int &ans)
{
    if(v < u || r < l || r < u || v < l)
        return;
    if(l <= u && v <= r)
    {
        if(t[root]%x == 0)
            return;
        else
        {
            while(root < num_of_nodes)
            {
              //  cout << "root = " << root << " t[" << 2*root << "] = " << t[2*root] << " t[" << 2*root+1 << "] = " << t[2*root+1] << endl;
                if(t[2*root]%x != 0)
                {
                    if(t[2*root + 1]%x != 0)
                    {
                        ans += 2;
                        return;
                    }
                    root <<= 1;
                }
                else
                    root = 2*root+1;
            }
            ans++;
            return;
        }
    }
    else
    {
        int mid = (u+v)/2;
        query(2*root, l, r, u, mid, x, ans);
        if(ans > 1) return;
        query(2*root+1, l, r, mid+1, v, x, ans);
    }
}
bool check(int n)
{
    while(n > 1)
    {
        if(n&1) return false;
        n >>= 1;
    }
    return true;
}
/*
void print()
{
    stack<int> st;
    st.push(t[1]);
    int nu = 1;
    cout << t[1];
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(check(nu))
        {
            cout << endl;
            nu--;
        }
        if(2*u <= num_of_nodes)
            {
                st.push(2*u);
                cout << t[2*u] << " ";
                nu++;
            }
        if(2*u+1 <= num_of_nodes)
            {
                st.push(2*u+1);
                cout << t[2*u+1] << " ";
                nu++;
            }
    }
    return;
}
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while(num_of_nodes < n) num_of_nodes<<=1;
    forn(i,num_of_nodes,num_of_nodes+n) cin >> t[i];
    build();
    //print();
    int q;
    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch;
        if(ch == '1')
        {
            int l, r, x;
            cin >> l >> r >> x;
            int ans = 0;
            query(1,l,r,1,num_of_nodes,x,ans);
            //cout << ans << endl;
            if(ans > 1) cout << "NO\n";
            else cout << "YES\n";
        }
        else
        {
            int i, y;
            cin >> i >> y;
            modify(i, y);
        }
    }
    return 0;
}
