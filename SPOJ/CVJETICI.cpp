#include <cstdio>

using namespace std;

#define MAXN 100000
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int l[MAXN],r[MAXN];
int bit[100001],cont[100001];

void update(int idx, int val){
    for(int x = idx;x <= 100000;x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;

    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];

    return ret;
}

int main(){
    int N;

    scanf("%d",&N);

    for(int i = 0,l,r;i < N;++i){
        scanf("%d %d",&l,&r);

        int q1 = query(l),q2 = query(r);

        printf("%d\n",q1 + q2 - cont[l] - cont[r]);
        cont[l] = q1;
        cont[r] = q2;
        update(l + 1,1);
        update(r,-1);
    }

    return 0;
}
