#include<iostream>
#include <vector>

using namespace std;

#define MAX 2000002
#define ll long long

ll tree[MAX] = {0LL};

void constructUtilST(ll arr[], ll ss, ll se, ll si)
{
    if(ss > se) return;
    if(ss == se)
    {
        tree[si] = arr[ss];
    }
    ll mid = (ss+se)/2;
    constructUtilST(arr, ss, mid, 2*si+1);
    constructUtilST(arr, mid+1, se, 2*si+2);

    tree[si] = tree[2*si+1] + tree[2*si+2];
    return;
}

void constructST(ll arr[], ll n)
{
    constructUtilST(arr, 0, n-1, 0);
}

void UpdateValueST(ll arr[], ll n, ll ss, ll se, ll si, ll input, ll val)
{
    if(ss > se) return;
    if(ss == se && ss == input)
    {
        tree[si] += val;
        return;
    }
    else if(ss > input || se < input)
    {
        return;
    }
    tree[si] += val;
    ll mid = (ss+se)/2;
    UpdateValueST(arr, n, ss, mid, 2*si+1, input, val);
    UpdateValueST(arr, n, mid+1, se, 2*si+2, input, val);
    return;
}

void updatevalue(ll arr[], ll n, ll p, ll val)
{
    arr[p] += val;
    UpdateValueST(arr, n, 0, n-1, 0, p, val);
}

ll getsumST(ll n, ll ss, ll se, ll qs, ll qe, ll si)
{
    if(ss > se) return 0;
    if(qs > se || qe < ss) return 0;
    if(ss >= qs && se <= qe)
    {
        return tree[si];
    }
    ll mid = (ss+se)/2;
    return  getsumST(n, ss, mid, qs, qe, 2*si+1) +
            getsumST(n, mid+1, se, qs, qe, 2*si+2);
}

ll getsum(ll n, ll qs, ll qe)
{
    if(qs > qe || qs < 0 || qe >= n)
        return -1;
    return getsumST(n, 0, n-1, qs, qe, 0);
}

int main()
{
    ll n,q;
    cin >> n >> q;
    ll arr[n] = {0LL};
    //constructST()
    while(q--)
    {
        string s;
        cin >> s;
        if(s == "find")
        {
            ll a, b;
            cin >> a >> b;
            a--,b--;
            cout << getsum(n, a, b) << endl;
        }
        else if(s == "add")
        {
            ll p,f;
            cin >> p >> f;
            p--;
            updatevalue(arr, n, p, f);
        }
        else
        {
            cout << "---------------------\n";
            for(int i = 0; i < 25; i++)
                cout << i << " " << tree[i] << endl;
            cout << "---------------------\n";
        }
    }
    return 0;
}
