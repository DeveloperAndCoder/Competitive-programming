#include <iostream>
#include <climits>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 131074
#define M INT_MIN

using namespace std;

struct node
{
    long long int prefix{0};
    long long int suffix{0};
    long long int sum{0};
    long long int best{0};
public:
    node() = default;
    node(long long n)
    {
        prefix = suffix = sum = best = n;
    }
    node& operator=(long long n)
    {
        prefix = suffix = sum = best = n;
        return *this;
    }
    friend ostream& operator<<(ostream&, const node&);
} tree[MAX];

ostream& operator<<(ostream& out, const node& nd)
{
    out << "prefix: " << nd.prefix << endl;
    out << "suffix: " << nd.suffix << endl;
    out << "sum: " << nd.sum << endl;
    out << "best: " << nd.best << endl;
    return out;
}

void constructST(int arr[], int ss, int se, int si)
{
    if(ss > se) return;
    if(ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = ss + (se-ss)/2;
    constructST(arr, ss, mid, 2*si+1);
    constructST(arr, mid+1, se, 2*si+2);
    tree[si].best = tree[2*si+1].suffix + tree[2*si+2].prefix;
    tree[si].prefix = max(tree[2*si+1].prefix, tree[2*si+2].prefix + tree[2*si+1].sum);
    tree[si].suffix = max(tree[2*si+2].suffix, tree[2*si+2].sum + tree[2*si+1].suffix);
    tree[si].sum = tree[2*si+1].sum+tree[2*si+2].sum;
    if(tree[2*si+1].best > tree[si].best)
    {
        tree[si].best = tree[2*si+1].best;
    }
    if(tree[2*si+2].best > tree[si].best)
    {
        tree[si].best = tree[2*si+2].best;
    }
    return;
}

node getmax(int qs, int qe, int ss, int se, int si, int n)
{
    //cout << "present index: " << si << endl;
    if(ss > qe || se < qs || qs > qe) return node(M);
    //cout << ss << " " << se << "\n" << tree[si] << endl;

    if(ss >= qs && se <= qe) return tree[si];

    int mid = ss + (se-ss)/2;

    node left = getmax(qs,qe,ss,mid,2*si+1,n);
    node right = getmax(qs,qe,mid+1,se,2*si+2,n);

    if(left.best == M) return right;
    else if(right.best == M) return left;

    node ans(M);

    ans.best = max(left.best, right.best);
    ans.best = max(ans.best, left.suffix + right.prefix);
    ans.prefix = max(left.prefix, left.sum+right.prefix);
    ans.suffix = max(right.suffix, right.sum+left.suffix);
    ans.sum = left.sum+right.sum;
//    if(si == 0)
//    {
//        cout << left << "\n" << right << "\n" << ans;
//    }
    return ans;
}

void update(int arr[], int ss, int se, int i, int new_val, int si)
{
    if(ss > se) return;
    if(ss > i || se < i) return;
    if(ss == se)
    {
        arr[i] = new_val;
        tree[si] = new_val;
        return;
    }
    int mid = ss + (se-ss)/2;

    update(arr, ss, mid, i, new_val, 2*si+1);
    update(arr, mid+1, se, i, new_val, 2*si+2);

    tree[si].best = tree[2*si+1].suffix + tree[2*si+2].prefix;
    tree[si].prefix = max(tree[2*si+1].prefix, tree[2*si+2].prefix + tree[2*si+1].sum);
    tree[si].suffix = max(tree[2*si+2].suffix, tree[2*si+2].sum + tree[2*si+1].suffix);
    tree[si].sum = tree[2*si+1].sum+tree[2*si+2].sum;
    if(tree[2*si+1].best > tree[si].best)
    {
        tree[si].best = tree[2*si+1].best;
    }
    if(tree[2*si+2].best > tree[si].best)
    {
        tree[si].best = tree[2*si+2].best;
    }
    return;
}

int main()
{
    boost;
    int n;
    cin >> n;
    int arr[n];
    forn(i,0,n)
    {
        cin >> arr[i];
    }
    constructST(arr,0,n-1,0);
    int m;
    cin >> m;
    while(m--)
    {
        int type;
        cin >> type;
        switch(type)
        {
        case 0:
        {
            int i, y;
            cin >> i >> y;
            i--;
            update(arr,0,n-1,i,y,0);
            break;
        }
        case 1:
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << getmax(l,r,0,n-1,0,n).best << endl;
            break;
        }
        }
    }
}
