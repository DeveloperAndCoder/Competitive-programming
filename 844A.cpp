#include<iostream>
using namespace std;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    if (k > s.length())
    {
        cout << "impossible";
        return 0;
    }
    int l[26] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        l[(int)(s[i]-'a')]++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(l[i] > 0)
        {
          //  cout << i << endl;
          k--;
          l[i]-=1;
        }
    }
    int ans = 0;
    if(k > 0)
    {
      for(int i = 0; i < 26; i++)
      {
          if(l[i] > 0)
          {
            if(l[i] < k)
            {
                k -= l[i];
                ans += l[i];
            }
            else
            {
                ans += k;
                k = 0;
                break;
            }

          }
      }
    }
    cout << ans;
    return 0;
}
