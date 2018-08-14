#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    string s;
    cin >> s;
    /*
    int n = s.length();
    int len = n;
    forn(i,0,s.length()-2)
    {
        if(s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            s.erase(s.begin()+i+2);
            i--;
        }
    }
    //cout << s << " " << s.length()<<'\n';
    vector<int> freq(s.length(), 1);
    forn(i,0,s.length()-1)
    {
        if(s[i] == s[i+1])
            freq[i+1] = ++freq[i];
    }
   // forn(i,0,s.length()) cout << freq[i] << " ";
   // cout << endl;
    forn(i,1,s.length())
    {
        //cout << "i = "<< i <<"\n";
        if(s[i] != s[i-1] && freq[i] == 2 && freq[i-1] == 2)
        {
            //cout << i << " = i " << s[i] << " = s[i]"<<endl;
            //freq[i];
            freq[i+1]--;
            s.erase(s.begin()+i);
            freq.erase(freq.begin()+i);
        }
    }
    //cout << "OUT\n";
    cout << s << endl;
    */
    string ans;
    forn(i,0,s.length())
    {
        //cout << i << endl;
        if(i == s.length()-1)
        {
            ans.push_back(s[i]);
            break;
        }
        int rep = 1;
        int j = i;
        while(s[j+1] == s[j]) rep++,j++;
        if(rep >= 2)
        {
            ans.push_back(s[i]);
            ans.push_back(s[i]);
        }
        else
            ans.push_back(s[i]);
        i = j;
    }
    int len = 0;
    //cout << ans.length() << endl;
    int n = ans.length()-3;
    //cout << ans << endl;
    forn(i,0,n)
    {
        //cout << "i = " << i << endl;
        if(ans[i] == ans[i+1] && ans[i+2] == ans[i+3])
        {
            cout << ans[i] << ans[i] << ans[i+2];
            i = i+3;
            len+=3;
        }
        else
        {
            cout << ans[i];
        }
        len++;
    }
    while(len < ans.length())
        cout << ans[len++];
    return 0;
}
