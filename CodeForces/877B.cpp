#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> v;

void rec(int p,int r, int n)
{
    if(r-p < 0)
    {
        return;
    }
    if(r-p == 0)
    {
        v.push_back(p);
        return;
    }
    if(r-p == 1)
    {
        v.push_back(p+1);
        v.push_back(p);
        v.push_back(p+1);
        return;
    }
    int mid = (p+r)/2;
    v.push_back(mid);

    rec(p, mid-1, n);
    rec(mid+1, r, n);


    v.push_back(mid);
    return;
}

int main()
{
    int n;
    cin >> n;
    rec(0,n-1,n);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i]+1 << " ";
    return 0;
}
