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
    int mini = a[0];
    forn(i,0,n)
    {
        if(mini > a[i]) mini = a[i];
    }
    vector<int> v;
    forn(i,0,n)
    {
        if(a[i] == mini)
            v.push_back(i);
    }
    mini = v[1]-v[0];
    forn(i,0,v.size()-1)
    {
        if(v[i+1]-v[i] < mini)
            mini = v[i+1]-v[i];
    }
    cout << mini;
    return 0;
}
