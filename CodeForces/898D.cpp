#include<iostream>
#include<algorithm>

#define uni unsigned int
#define lli long long int
#define li long int
#define N 1000001

#define For(a,b) for(int i = a; i < b; i++)
#define fori(a) for(int i = 0; i < a; i++)
#define Forn(a,b) for(int i = b; i >= a; i--)
#define forn(a) for(int i = a; i >= 0; i--)

using namespace std;

bool a[N];

int main()
{
    size_t n,m,k;
    cin >> n >> m >> k;
    int x;
    fori(n)
    {
        cin >> x;
      //  cout << x << " ";
        a[x] = true;
    }
    int cnt = 0;
    uni ans = 0;
    fori(N)
    {
        /*
        if(i <= n+m)
        cout << i << " " << boolalpha << a[i] << " " << cnt << '\n';
        */
        if(a[i]) cnt++;
        if(i >= m && a[i-m]) cnt--;
        if(cnt >= k)
        {
     //       cout << i << " " << cnt << endl;
            a[i] = false;
            cnt--;
            ans++;
        }
    }
    cout << ans;
}
