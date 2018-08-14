#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
#include<stack>
#include<math.h>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define fr first
#define sc second
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

int N, Q;
int answers[200000];
pair< pair<int, int>, int > queries[200000];
int answer;
int block_size;
int arr[30000];
int cnt[1000001];

inline bool mo_cmp(const pair< pair<int, int>, int > &x,
                   const pair< pair<int, int>, int > &y)
{
    int block_x = x.fr.fr / block_size;
    int block_y = y.fr.fr / block_size;
    if(block_x != block_y)
        return block_x < block_y;
    return x.fr.sc < y.fr.sc;
}

int main()
{
    boost;
    cin >> N;
    block_size = sqrt(N);
    forn(i,0,N) cin >> arr[i];
    cin >> Q;
    forn(i,0,Q)
    {
        cin >> queries[i].fr.fr >> queries[i].fr.sc;
        queries[i].fr.fr--;
        queries[i].fr.sc--;
        queries[i].sc = i;
    }
    sort(queries, queries+Q, mo_cmp);
    int mo_left = 0, mo_right = -1;
    forn(i,0,Q)
    {
        int left = queries[i].fr.fr;
        int right = queries[i].fr.sc;
        while(mo_right < right){
            mo_right++;
            if(cnt[arr[mo_right]] == 0)
                answer++;
            cnt[arr[mo_right]]++;
        }
        while(mo_right > right){
            if(cnt[arr[mo_right]] == 1)
                answer--;
            cnt[arr[mo_right]]--;
            mo_right--;
        }
        while(mo_left > left){
            mo_left--;
            if(cnt[arr[mo_left]] == 0)
                answer++;
            cnt[arr[mo_left]]++;
        }
        while(mo_left < left){
            if(cnt[arr[mo_left]] == 1)
                answer--;
            cnt[arr[mo_left]]--;
            mo_left++;
        }
        answers[queries[i].sc] = answer;
    }
    forn(i,0,Q) cout << answers[i] << '\n';
    return 0;
}
