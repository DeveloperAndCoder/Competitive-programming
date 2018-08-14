#include<iostream>
#include<string>

using namespace std;

int main()
{/*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l, r;
    char c;

    while(m--)
    {
        cin >> l >> r >> c;
        l--;r--;
      //  cout << l << " " << r << " " << c << endl;
        for(int i = l; i <= r; i++)
        {
            //cout << "in";
            if(i < l) break;
            if(s[i] == c)
            {
                int k = i;
                while(k <= r && s[k] == c)
                {
                    k++;
                }
                //cout << s << " ";
                s.erase(s.begin()+i, s.begin()+k);
                //cout << " k = " << k << " i = " << i;// << " size of string is " << s.size();
                r-=(k-i);
                i-=(k-i);
                if(i < l) break;
                if(r<l) break;
                //cout << " i = " << i << " r = " << r << " string = ";
                cout << s << endl;
            }
        }
    }
    cout << s;
    return 0;
}
