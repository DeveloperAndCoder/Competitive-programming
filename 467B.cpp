#include<iostream>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b ; i++)

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int x[m+1];
    int ans = 0;
    forn(i,0,m+1) cin >> x[i];
    int abc=0;
    forn(i,0,m)
    {
        abc=0;
        for(int j = 1; j < 1<<n; j<<=1)
        {
            if((j&x[m])^(j&x[i]))abc++;
            if(abc > k) break;
        }
        if(abc <= k) //{cout << i << " " << c_o << " " << c_z << endl;ans++;}
            ans++;
    }
    cout << ans;
    return 0;
}
