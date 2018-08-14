#include<iostream>
#include<vector>

using namespace std;
int main()
/*
{
    int n,x,len;
    cin >> n;
    string s;
    char f[1000000];
    int k;
    int sizer = 0;
    for(int i = 0; i < n; i++)
    {
       // cout << i <<endl;
        cin >> s >> k;
        int pos[k];
        len = s.length();
     //   cout << s << endl;
        for(int i = 0; i < k; i++)
        {
            cin >> pos[i];
            if(pos[i] > sizer)
                sizer = pos[i];
        }
        for(int l = 0; l < k; l++)
        for(int j = 0; j < len; j++)
        {
            if(l == k-1)
           {
           //    cout << pos[l]+len-1 << " " << sizer << endl;
               if(pos[l]+len-1 > sizer)
                sizer = pos[l] + len - 1;
           }
            f[pos[l]+j-1] = s[j];
        }

    }
    for(int i = 0; i < sizer; i++)
    {
        if(f[i] >= 97 && f[i] <= 122)
        {
            //f[i] = 'a';
        }
        else
            f[i]='a';
    }
    //cout << "sizer = "<<sizer<<endl;
   for(int i = 0; i < sizer; i++)
   cout << f[i];
}
*/
{
    int n;
    cin >> n;
    vector<char> vec;
    int k;
    int x;
    for(int i = 0; i  < n; i++)
    {
        string s;
        cin >> s;
        cin >> k;

        for(int j = 0; j < k; j++)
        {
            cin >> x;
            if(x + s.size() - 1 > vec.size())
            {
                vec.resize(x+s.size()-1);
            }
            for(int a = x-1; a < x+s.size()-1; a++)
            {
                vec[a] = s[a-(x-1)];
            }
        }
    }
    for(int i = 0; i < vec.size(); i++)
        {
                if(vec[i] == 0)
                    vec[i] = 'a';
                cout << vec[i];
        }
    return 0;
}
