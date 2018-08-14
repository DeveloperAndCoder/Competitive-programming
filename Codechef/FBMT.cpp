#include<iostream>
#include<string>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

bool cmp(string s1, string s3)
{
    if(s1.length() != s3.length())
        return false;
    forn(i,0,s1.length())
    {
        if(s1[i] != s3[i])
            return false;
    }
    return true;
}

void cmp1(string & s3, string &s2)
{
    forn(i,0,s3.length())
    s2.push_back(s3[i]);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s1,s2,s3;
        int a=0,b=0;
        bool once = false;
        forn(i,0,n)
        {
            if(i==0)
            {
                cin >> s1;
                a++;
            }
            else
            {
                cin >> s3;
                if(cmp(s1,s3))
                {
                    a++;
                }
                else
                {
                    if(!once)
                    cmp1(s3,s2);
                    b++;
                    once = true;
                }
            }
        }
       // cout << s1 << " " << s2 << endl;
       // cout << a << " " << b << endl;
        if(a > b)
        {
            cout << s1;
        }
        else if(b > a)
        {
            cout << s2;
        }
        else
        {
            cout  << "Draw";
        }
        cout << endl;
    }
}
