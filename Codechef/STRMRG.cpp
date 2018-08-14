#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long

using namespace std;

int lcs(const vector<char> &a,const vector<char> &b, int n, int m)
{
    int L[n+1][m+1];
    int i, j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(a[i-1] == b[j-1])
                {
                    L[i][j] = L[i-1][j-1]+1;
                }
            else
            {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[n][m];
}


int main()
{
    int t,n,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        char a[n];
        char b[m];
        vector<char> v1,v2;
        forn(i,0,n)
        {
            cin >> a[i];
            if(i == 0)
                v1.push_back(a[i]);
            else if(i != 0 && a[i] != a[i-1])
                v1.push_back(a[i]);
        }
        forn(i,0,m)
        {
            cin >> b[i];
            if(i == 0)
                v2.push_back(b[i]);
            else if(i != 0 && b[i] != b[i-1])
                v2.push_back(b[i]);
        }
        int cut = 0;
        forn(i,1,n)
        {
            if(a[i] == a[i-1])
                cut++;
        }
        forn(i,1,m)
        {
            if(b[i] == b[i-1])
                cut++;
        }
        cout << n+m-lcs(v1,v2,v1.size(),v2.size())-cut << '\n';
    }
    return 0;
}
