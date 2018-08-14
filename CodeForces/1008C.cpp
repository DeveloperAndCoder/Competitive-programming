#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a, a+n);
    int b[n];
    forn(i,0,n) b[i] = a[i];
    int i = 0, ans = 0;
    int occ = 0;
    while(i < n)
    {
        int p_freq = 0;
        int j = i;
        //cout << a[i];
        while(a[i] == a[j]) i++, p_freq++;
        //cout << " " << p_freq << " " << occ << endl;
        if(p_freq > j - occ)
        {
            ans += j-occ;
            occ += j-occ;
        }
        else
        {
            ans += p_freq;
            occ += p_freq;
        }
    }
    cout << occ;
    return 0;
}
