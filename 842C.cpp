#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void bfs(vector<int> v[], int cost[], int n);
void gcd(int parent[], int cost[], int n);
int gcd_2(int parent[], int cost[], int n, int i, int min_i);
int main()
{
    int n;
    cin >> n;
    int cost[n];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    vector<int> v[n];
    for(int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(v, cost, n);
}
void bfs(vector<int> v[], int cost[], int n)
{
    stack<int> s;
    bool visited[n] = {false};
    s.push(0);
    visited[0] = true;
    /*int gcd[n] = {1};
    gcd[0] = cost[0];
    int min_[n] = {0};
    min_[0] = cost[0];
    */
    int parent[n];
    parent[0] = -1;
    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        for(int i = 0; i < v[t].size(); i++)
        {
            if(!visited[v[t][i]])
            {
                /*
                parent[v[t][i]] = t;
                if(min_[t] < cost[v[t][i]])
                    min_[v[t][i]] = min_[t];
                else
                    min_[v[t][i]] = cost[v[t][i]];
                GCD(gcd, cost, gcd, min_, v[t][i], parent);
                */
                parent[v[t][i]] = t;
                visited[v[t][i]] = true;
                s.push(v[t][i]);
            }
        }
    }
    gcd(parent, cost, n);
}
/*
void GCD(int gcd[], int cost[], int min_[], int i, int parent[])
{
    if(i == 0)
    {
        gcd[0] = cost[0];
    }
    if(min_[i] >= gcd[parent[i]])
    {
        gcd[i] = gcd[parent[i]];
    }
    else
    {

    }
}
*/
void gcd(int parent[], int cost[], int n)
{
    if(n <= 0)
        return;
    int ans[n] = {0};
    ans[0] = cost[0];
    for(int i = 1; i < n; i++)
    {
        int min_i = i;
        int j = i;
        int mini = cost[j];
        while(j != 0)
        {
            if(mini > cost[parent[j]])
            {
                min_i = parent[j];
                mini = cost[parent[j]];
            }
            j = parent[j];
        }
        ans[i] = gcd_2(parent, cost, n, i, min_i);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
int gcd_2(int parent[], int cost[], int n, int i, int min_i)
{
    int ma_ = cost[i];
    int j = i;
    while(j != 0)
    {
        if(ma_ < cost[j])
            ma_ = cost[j];
        j = parent[j];
    }
    if(ma_ < cost[0])
        ma_ = cost[0];
    bool ch[ma_] = {false};
    if(min_i != i)
    {
        for(int k = 1; k <= ma_ && k <= cost[i]; k++)
            if(!cost[i]%k)
            ch[k] = 1;
    }
    else
    {
        for(int k = 1; k <= ma_ && k <= cost[parent[i]]; k++)
            if(!(cost[parent[i]]%k))
            ch[k] = 1;
    }
    j = i;
    for(j = i; j >= 0; j = parent[j])
    {
        if(j == min_i)
        {
            continue;
        }
        for(int k = 1; k < ma_; k++)
        {
            if(!cost[j]%k && ch[j])
            {}
            else
                ch[j] = 0;
        }
    }
    j = i;
    for(int k = ma_; k > 0; k--)
    {
        if(ch[k])
        {
            return k;
        }
    }
    return 0;
}
