#include<iostream>
using namespace std;
#define forn(i,a,b) for(int i = a; i < b; i++)

int top(int p[], int i, int n)
{
    bool vis[n];
    forn(i,0,n) vis[i] = 0;
    int j = i;
    while(!vis[j])
    {
        vis[j] = true;
        j = p[j];
    }
    return j;
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    forn(i,0,n)
    {
        cin >> p[i];
        p[i]--;
    }
    forn(i,0,n) cout << top(p,i,n)+1 << " ";
    return 0;
}
