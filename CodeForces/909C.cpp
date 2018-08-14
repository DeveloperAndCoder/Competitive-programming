#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define N 101
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    char c[n];
    forn(i,0,n) cin >> c[i];
    int fo = 0;
    int i= 0;
    long long ans = 0;
    for(i;i < n;i++)
    {
        if(c[i] == 's')
        {
        }
        else
            break;
    }
    bool cv = false;
    if(i == 0) i++;
    for(i; i < n; i++)
    {
        if(c[i] == 's' && c[i-1] == 'f')
        {
            fo++;
            cout << " 1. " << i << endl;
            if(!cv)
            ans += ((fo)*(fo+1))/2-1;
            else
                fo = 0;
            cout << "fo = " << fo << " ans = " << ans << endl;
            cv = false;
            i++;
        }
        else if(c[i] == 'f' && c[i-1] == 'f')
        {
            cout << " 2. " << i << endl;
            fo+=2;
            cout << "fo = " << fo << " ans = " << ans << endl;
            cv = true;
            if(i == n-2) break;
            i++;
        }
        else
        {
            cout << " 3. " << i << endl;
            if(fo > 0)
            ans += ((fo)*(fo+1))/2-1;
            cout << "fo = " << fo << " ans = " << ans << endl;
            fo = 0;
        }
    }
    if(cv && ans == 0)
    {
        ans = 1;
    }
    cout << ans;
}
