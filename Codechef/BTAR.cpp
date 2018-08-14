#include<iostream>
#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        forn(i,0,n) cin >> a[i];
        forn(i,0,n)
        {
            a[i] = a[i]%4;
        }
        int one = 0, two = 0, thr = 0;
        ll sum = 0, ans = 0;
        forn(i,0,n)
        {
            if(a[i] == 1)
                one++;
            else if(a[i] == 2)
                two++;
            else if(a[i] == 3)
                thr++;
            sum += a[i];
        }
        //cout << one << " " << two << " " << thr << endl;
        if(sum % 4 != 0)
        {
            cout << -1;
            goto la;
        }
        else
        {
            if(one >= thr)
            {
                ans += thr;
                one -= thr;
                thr = 0;
            }
            else
            {
                ans += one;
                thr -= one;
                one = 0;
            }
            //cout << one << " " << two << " " << thr << endl;
            if(one > 0 && two >= 0)
            {
                while(one > 1 && two > 0)
                {
                    ans += 2;
                    one -= 2;
                    two--;
                }
                if(one > 0 && two == 0)
                {
                    if(one % 4 == 0)
                    {
                        ans += 3*(one/4);
                    }
                    else
                    {
                        cout << -1;
                        goto la;
                    }
                }
                else if(two > 0 && one == 0)
                {
                    if(two%2 == 0)
                    {
                        ans += two/2;
                    }
                    else
                    {
                        cout << -1;
                        goto la;
                    }
                }
            }
            else
            {
                if((3*thr + 2*two)%4 != 0)
                {
                    cout << -1;
                    goto la;
                }
                else
                {
                    //cout << one << " " << two << " " << thr << endl;
                    if(thr % 4 == 0 && two % 2 == 0)
                    {
                        ans += 3*(thr/4);
                        ans += (two/2);
                     //   cout << "ans = " << ans << " " << two;
                    }
                    else
                    {
                        while(thr > 1 && two >= 1)
                        {
                            ans += 2;
                            thr -= 2;
                            two --;
                        }
                        //cout << one << " " << two << " " << thr << endl;
                        if(thr > 0 && two == 0)
                        {
                            if(thr%4 == 0)
                            {
                                ans += 3*(thr/4);
                            }
                            else
                            {
                                cout << -1;
                                goto la;
                            }
                        }
                        else if(thr == 0 && two > 0)
                        {
                            if(two%2 == 0)
                            {
                                ans += (two/2);
                            }
                            else
                            {
                                cout << -1;
                                goto la;
                            }
                        }
                    }
                }
            }
        }
        cout << ans;
        la:
        cout << endl;
    }
}
