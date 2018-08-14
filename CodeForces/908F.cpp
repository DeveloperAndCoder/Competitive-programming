#include<iostream>
#include<vector>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n];
    char c[n];
    forn(i,0,n)
    {
        cin >> p[i] >> c[i];
    }
    long long ans = 0;
    bool bo = true;
    int k = 0;
    forn(i,0,n)
    {
        if(c[i] == 'G' && bo)
        {
            k = i;
            bo = false;
        }
        else if(c[i] == 'G')
        {
            ans += k-i;
        }
    }
    bo = true;
    bool red = false;
    forn(i,0,n)
    {
        if(c[i] == 'R' && bo)
        {
            int diff1 = n;
            for(int l = i-1;l >= 0; i--)
            {
                if(c[l] == 'G')
                    diff1 = i-l,break;
            }
            for(int l = i+1; l < n; l++)
            {
                if(c[l] == 'G' || c[l] == 'R')
                    diff1 = min(diff1,l-i);
            }
        }
    }
}
