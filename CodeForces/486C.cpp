#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    char p1[n];
    forn(i,0,n) cin >> p1[i];
    p--;
    if(p >= n/2) p = n-p-1;
    int ans = 0;
    int curr = p;
    int next;
    if(p < n/2-p)
    {
        for(int i = p; i >= 0; i--)
        {
            if(p1[i] != p1[n-i-1])
            {
                next = i;
                ans += abs(next-curr);
                ans += abs(min(abs(p1[i]-p1[n-i-1]), abs(26 - abs(p1[i] - p1[n-i-1]))));
                curr = next;
            }
        }
        for(int i = p+1; i < n/2; i++)
        {
            if(p1[i] != p1[n-i-1])
            {
                next = i;
                ans += abs(next-curr);
                ans += abs(min(abs(p1[i]-p1[n-i-1]), abs(26 - abs(p1[i] - p1[n-i-1]))));
                curr = next;
            }
        }
    }
    else
    {
        //cout << "in\n";
        for(int i = p; i < n/2; i++)
        {
          //  cout << i << " ";
            if(p1[i] != p1[n-i-1])
            {
            //    cout << "n " << i << endl;
                next = i;
                ans += abs(next-curr);
              //  cout << p1[i] << " " << p1[n-i-1] << endl;
                ans += abs(min(abs(p1[i]-p1[n-i-1]), abs(26 - abs(p1[i] - p1[n-i-1]))));
                //cout << "ans = " << ans << endl;
                curr = next;
            }
        }
        for(int i = p-1; i >= 0; i--)
        {
            //cout << i << " ";
            if(p1[i] != p1[n-i-1])
            {
                next = i;
                ans += abs(next-curr);
                ans += abs(min(abs(p1[i]-p1[n-i-1]), abs(26 - abs(p1[i] - p1[n-i-1]))));
                curr = next;
            }
        }
    }
    cout << ans;
    return 0;
}
/*
39 30
yehuqwaffoiyxhkmdip x
roolhahbhzprioobxfy
*/
