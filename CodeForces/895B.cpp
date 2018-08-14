#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int bin_l(int a[], int y[], int match, int l, int r)
{
    if(l > r)
        return -1;
    int mid = l+r;
    mid /= 2;
    if(match == y[mid] && (l > 0 || y[l-1]<y[l]))
        return l;

    if(match < y[mid])
    return bin_l(a, y, match, l, mid);
    else
    return bin_l(a, y, match, mid+1, r);
}

int bin_r(int a[], int y[], int match, int l, int r, int n)
{
    if(l > r)
        return -1;
    int mid = l+r;
    mid /= 2;
    if(match == y[mid] && (mid < n-1 || y[mid] < y[mid+1]))
        return l;
    if(match > a[mid])
    return bin_r(a, y, match, mid+1, r, n);
    else
    return bin_r(a, y, match, l, mid, n);
}

int main()
{
    int n, x, k;
    cin >> n >> x >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a, a+n);
    int y[n], ans = 0;
    forn(i,0,n) y[i] = a[i]/x;
    forn(i,0,n) cout << y[i] << " ";
    cout << '\n';
    forn(i,0,n)
    {
        int l,r;
        if(a[i]%x != 0)
        l = bin_l( a, y, y[i]+k, 0, n-1 );
        else
        l = bin_l( a, y, y[i]+k-1, 0, n-1 );
        if(a[i]%x != 0)
        r = bin_r( a, y, y[i]+k, 0, n-1, n );
        else
        r = bin_r( a, y, y[i]+k-1, 0, n-1, n );
        if(i == 1) cout << "l = " << l << " r = " << r << " "<< y[i]+k << endl;
        if(l == -1 || r == -1) l=0,r=-1;
        ans += (r-l+1);
        cout << i << " " << r-l+1 << " " << l << " " << r << endl;
    }
    cout << ans;
    return 0;
}
