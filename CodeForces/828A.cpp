// Something is wrong.Think a little more.

#include<iostream>
using namespace std;
int main()
{
    int n,a,b,m;
    cin >> n >> a >> b;
    int vac_s = a, vac_d = b;
    int ans = 0,s_d=0;
    bool is_vac = true;
    for(int i = 0;i < n; i++)
    {
        cin >> m;
        if(m == 1)
        {
            if(vac_s == 0 && vac_d == 0 && is_vac)
            {
                //cout << "in " << m << " i = "<<i << endl ;
                ans++;
                continue;
            }
            else if(vac_s > 0)
            {
                //cout << 1 << " ";
                vac_s--;
                continue;
            }
            else
            {
                if(is_vac)
                {
                    vac_d--;
                    s_d++;
                    if(vac_d == 0)
                        is_vac = false;
                }
                else
                {
                    s_d--;
                    if(!s_d)
                    {
                        is_vac = true;
                    }
                }
            }
        }
        else
        {
            if(vac_d >= 1)
            {
                //cout << 2 << " ";
                vac_d--;
                if(vac_d == 0 && s_d > 0)
                    is_vac = false;
                continue;
            }
            else
            {
                ans+=2;
            }
        }
    }
    cout << ans;
    return 0;
}
