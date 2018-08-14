#include<iostream>
#include<map>
#include<vector>
#include<string.h>

using namespace std;

bool cmp(string s, string s1)   //s1 is substring of s then return true
{
    int i = s.size();
    int j = s1.size();
    if(j>i)
        return false;
    for(i; j>=0; i--, j--)
        if(s[i] != s1[j])
            return false;
    return true;
}

bool scan(string name, string num)
{
    if(!cmp(name, num)) //num is not substring of name
        return false;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string name;
    int k;
    string num;
    map< string, vector<string> > m;
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> num;
            m[name].push_back(num);
        }
    }
    for(map<string, vector<string> >::iterator itr = m.begin() ; itr != m.end(); itr++)
    {
       // cout << itr->first << endl;
        for(int i = 0; i < itr->second.size(); i++)
        {
            for(int j = 0; j < itr->second.size(); j++)
            {
               // cout << itr->second[i] << " " << itr->second[j] << endl;
                if(j != i && scan(itr->second[j], itr->second[i]))
                {
                  //  cout << "out\n";
                    itr->second.erase(itr->second.begin() + i);
                    i--;
                    break;
                }
            }
        }
       // cout << endl;
    }
    cout << m.size() << endl;
    for(map<string, vector<string> >::iterator itr = m.begin() ; itr != m.end(); itr++)
    {
        cout << (*itr).first << " ";
        vector<string> v = (*itr).second;
        cout << v.size() << " ";
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
            cout << endl;
    }
    return 0;
}
