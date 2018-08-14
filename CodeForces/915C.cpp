#include<iostream>
#include<algorithm>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    string ans;
    int suf[10];
    memset(suf, 0, sizeof(suf));
    forn(i,0,a.length())
    {
        suf[a[i]-'0']++;
    }
    if(a.length() == b.length())
    {
        st:
        forn(i,0,b.length())
        {
            if(suf[b[i]-'0'] > 0)
            {
                ans.push_back(b[i]);
                suf[b[i]-'0']--;
            }
            else
            {
                i = b[i]-'0';
                while(i >= 0 && suf[i] == 0)
                {
                    i--;
                }
                if(i < 0)
                {
                   // cout << ans << endl;
                    goto last;
                }
                //forn(i,0,10) cout << suf[i] << " ";
                //cout << endl;
                //cout << ans << endl;
                ans.push_back(i+'0');
                //cout << ans << endl;
                suf[i]--;
                //cout << i << " = i\n";
                //forn(i,0,10) cout << suf[i] << " ";
                //cout << "\n";
                for(int j = 9; j >= 0; j--)
                {
                    while(suf[j] > 0)
                    {
                        ans.push_back(j+'0');
                        suf[j]--;
                    }
                }
                cout << ans;
                return 0;
            }
        }
    }
    else if(a.length() < b.length())
    {
        sec:
        for(int j = 9; j >= 0; j--)
        {
            while(suf[j] > 0)
            {
                ans.push_back(j+'0');
                suf[j]--;
            }
        }
    }
    cout << ans;
    return 0;
    last:
        int l = ans.length()-1;
        for(l; l >= 0; l--)
        {
            for(int i = b[l]-'0'-1; i >= 0; i--)
            {
                if(suf[i]>0)
                {
                    suf[b[l]-'0']++;
                    suf[i]--;
                    ans[l] = i+'0';
                    goto x;
                }
            }
            suf[ans[l]-'0']++;
            ans.erase(ans.end()-1);
        }
        x:
        goto sec;
}
