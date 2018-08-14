#include<iostream>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)
typedef long long ll;
using namespace std;

int main()
{
    string str;
    cin >> str;
    int b,s,c;
    cin >> b >> s >> c;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    ll ans = 0;
    int one_h = 0, ob=0, os=0, oc=0;
    forn(i,0,str.length())
    {
        if(str[i] == 'B') one_h += pb,ob++;
        else if(str[i] == 'S') one_h += ps,os++;
        else one_h += pc, oc++;
    }
    int curr_b=0,curr_s=0,curr_c=0;
    if(ob == 0) b = 0;
    if(oc == 0) c = 0;
    if(os == 0) s = 0;
    while(1)
    {
        if(curr_b <= ob)
        {
            if(b < ob - curr_b)
            {
                curr_b += b;
                b = 0;
                if (r >= pb*(ob - curr_b))
                r -= pb*(ob - curr_b);
                else break;
            }
            else
            {
                b -= (ob-curr_b);
                curr_b = ob;
            }
        }
        if(curr_c < oc)
        {
            if(c < oc - curr_c)
            {
                curr_c += c;
                c = 0;
                if(r >= pc*(oc - curr_c))
                r -= pc*(oc - curr_c);
                else break;
            }
            else
            {
                c -= (oc-curr_c);
                curr_c = oc;
            }
        }
        if(curr_s < os)
        {
            if(s < os - curr_s)
            {
                curr_s += s;
                s = 0;
                if(r >= ps*(os - curr_s))
                r -= ps*(os - curr_s);
                else break;
            }
            else
            {
                s -= (os-curr_s);
                curr_s = os;
            }
        }
        //cout << b << " " << s << " " << c << endl;
        if(b == 0 && c == 0 && s == 0)
        {
            ans++;
            ans += r/one_h;
            break;
        }
        ans++;
        curr_b = 0;
        curr_c = 0;
        curr_s = 0;
    }
    cout << ans;
    return 0;
}
