#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i =a; i < b; i++)
#define ll long long

using namespace std;
const int M = 100001;
//int occ[M];
int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int occ[M];
    memset(occ, 0, sizeof(occ));
    forn(i,0,n)
        occ[a[i]]++;
    //int ans = 0;
    bool ans = true;
    for(int i = M-1; i >= 0; i--)
    {
        if(occ[i]&1)
            {
                ans = false;
                break;
                //cout << i << endl;
            }
    }
    if(!ans) cout << "Conan";
    else cout << "Agasa";
    return 0;
}
