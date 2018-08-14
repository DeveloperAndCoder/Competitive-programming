#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

struct Node
{
    char letter;
    int index;
    bool over;
    int overat;
    Node* next[26];

    Node()
    {
        letter = 0;
        index = 0;
        over = false;
        overat = -1;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    Node(char c, int index) : letter(c), index(index)
    {
        over = false;
        overat = -1;
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }
    ~Node()
    {
        delete[] next;
    }
};

void insert(Node* root, string s, int index)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(root->next[s[i]-'a'] == NULL)
        {
            Node* node = new Node(s[i], index);
            root->next[s[i]-'a'] = node;
            root = node;
        }
        else
        {
            root = root->next[s[i]-'a'];
        }
    }
    root->over = true;
    if(root->overat == -1)
        root->overat = index;
    return;
}

string prefix(Node* root, string s, int R)
{
    string prefix;
    int i = 0;
    while(i < s.size() && root->next[s[i]-'a'] != NULL && root->next[s[i]-'a']->index <= R)
    {
        root = root->next[s[i]-'a'];
        prefix.push_back(s[i]);
        i++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(root->over && root->overat <= R) return prefix;
        if(root->next[i] != NULL && root->next[i]->index <= R)
        {
            root = root->next[i];
            prefix.push_back(i+'a');
            i = -1;
        }
    }
    return prefix;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node* root = new Node;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string current;
        cin >> current;
        insert(root, current, i+1);
    }
    int queries;
    cin >> queries;
    while(queries--)
    {
        int R;
        string query;
        cin >> R >> query;
        cout << prefix(root, query, R) << endl;
    }
    return 0;
}
