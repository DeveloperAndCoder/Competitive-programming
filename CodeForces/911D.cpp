#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int swap = 0;
    forn(i,0,n)
    {
        forn(j,i+1,n)
        {
            if(a[j]<a[i])
                swap++;
        }
    }
    swap&=1;
    int m;
    cin >> m;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        int s = r-l+1;
        s = s*(s-1)/2;
        s &= 1;
        swap ^= s;
        cout << (swap ? "odd\n" : "even\n");
    }
    return 0;
}
