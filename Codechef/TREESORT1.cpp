#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <unordered_set>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};

ll merge(Tree* left, Tree* right, Tree* root)
{
    if(left == nullptr || right == nullptr) return 0ll;
    Tree *ptr1 = left, *ptr2 = right;
    while(ptr1->left) ptr1 = ptr1->left;
    while(ptr2->left) ptr2 = ptr2->left;
    if(ptr1->val > ptr2->val)
    {
        root->left = right;
        root->right = left;
        return 1ll;
    }
    return 0;
}

ll steps(Tree* root)
{
    if(root == nullptr) return 0ll;
    ll s1 = steps(root->left);
    ll s2 = steps(root->right);
    ll s3 = merge(left, right, root);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> g[n];
        Tree *root = root();
        forn(i,0,n)
        {
            int a;
            cin >> a;
            if(a == -1)
            {
                int val_;
                cin >> val_;
                val[i] = val_;
            }
            else
            {
                int b;
                cin >> b;
                a--;
                b--;
                g[i].push_back(a);
                g[i].push_back(b);            }
        }
        bool vis[n];
        forn(i,0,n) vis[i] = false;
        //dfs(g, vis, 0);
        //forn(i,0,a.size()) cout << a[i] << " ";
        cout << steps(0, a.size()-1) << endl;

    }
}

