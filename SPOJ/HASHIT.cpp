#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <unordered_set>
#include <iomanip>

#define ll long long
#define ull unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

class node
{
    string value{""};
public:
    node() = default;
    node(string val) : value(val) {}
    ~node() {}
    string getvalue()
    {
        return value;
    }
};

int HashKey(string key)
{
    int n = key.size();
    int ans = 0;
    forn(i,0,n)
    {
        ans += key[i]*(i+1);
        ans = ans % 101;
    }
    ans *= 19;
    return ans%101;
}

int next(int key, int j)
{
    return (key + j*j + 23*j)%101;
}

int search(node data[101], string value)
{
    int original_key = HashKey(value);
    int key = original_key;
    int j = 1;
    while(j < 20 && data[key].getvalue() != value)
    {
        key = next(original_key, j++);
    }
    if(data[key].getvalue() != value) return -1;
    return key;
}

int whereto(node data[101], string value)
{
    int original_key = HashKey(value);
    int key = original_key;
    int j = 1;
    while(j < 20 && data[key].getvalue() != "")
    {
        key = next(original_key, j++);
    }
    return key;
}

void insert(node data[101], string value)
{
    int key = HashKey(value);
    //cout << "result = " << search(data, value) << " : " << value << endl;
    if(search(data, value) == -1)
    {
        int pos = whereto(data, value);
        data[pos] = value;
    }
    return;
}

void delete_(node data[101], string value)
{
    int key = HashKey(value);
    int pos = search(data, value);
    //cout << "pos = " << pos <<endl;
    if(pos != -1)
    {
        data[pos] = node();
    }
}

void print(node data[101])
{
    vector<pair<int, string> > ans;
    forn(i,0,100)
    {
        if(data[i].getvalue() != "")
        {
            ans.push_back({i, data[i].getvalue()});
        }
    }
    cout << ans.size() << endl;
    forn(i,0,ans.size())
    {
        cout << ans[i].first << ":" << ans[i].second << endl;
    }
    return;
}

int main()
{
	boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        node data[101];
        while(n--)
        {
            string s;
            cin >> s;
            switch(s[0])
            {
                case 'A':
                {
                    string val(s.begin()+4, s.end());
                    insert(data, val);
                    break;
                }
                case 'D':
                {
                    string val(s.begin()+4, s.end());
                    delete_(data, val);
                    break;
                }
            }
        }
        print(data);
    }
    return 0;
}
