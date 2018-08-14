#include<iostream>
#include<utility>
#include<map>
using namespace std;
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    map<char,char> m;
    map<char,char>:: iterator it;
    pair<char,char> p;

    for(int i = 0; i < 26; i++)
    {
        p.first = s1[i];
        p.second = s2[i];

        m.insert(p);
    }


    string s;
    cin >> s;
    bool caps = false;
    char c;

    for(int i = 0; i < s.length(); i++)
    {
        c = s[i];
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            it = m.find(s[i]);
            c = (*it).second;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            it = m.find((char)(s[i]+32));
            c = (*it).second;
            c-=32;
        }
        cout << c;
    }

    return 0;
}
