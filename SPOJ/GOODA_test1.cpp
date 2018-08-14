#define _CRT_SECURE_NO_WARNINGS

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

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1100000;

int n, m, s, e;

vector<pair<int, int> > S;
int used[N];
vector<int> g[N], gr[N];
vector<int> order;
int cost[N];
int C;
queue<int> qu;

long long COST[N];
vector<int> G[N];
long long dp[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> s >> e;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	// dfs for traversal order

	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
		used[i] = 1;
		S.push_back(make_pair(i, 0));

		while (S.size())
		{
			pair<int, int> P = S.back();
			S.pop_back();
			int qv = P.first;
			int qptr = P.second;
			used[qv] = 1;

			if (qptr == g[qv].size())
			{
				order.push_back(qv);
				continue;
			}

			S.push_back(make_pair(qv, qptr + 1));
			int to = g[qv][qptr];
			if (used[to])
				continue;
			S.push_back(make_pair(to, 0));
		}
	}

	reverse(order.begin(), order.end());

	for (int i = 1; i <= n; i++)
		used[i] = 0;

	for (int i = 0; i < order.size(); i++)
	{
		int id = order[i];
		if (used[id])
			continue;
		++C;
		qu.push(id);
		while (qu.size())
		{
			int v = qu.front();
			used[v] = C;
			COST[C] += cost[v];
			qu.pop();
			for (int j = 0; j < gr[v].size(); j++)
			{
				int to = gr[v][j];
				if (used[to])
					continue;
				used[to] = C;
				qu.push(to);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			int to = g[i][j];
			if (used[i] == used[to])
				continue;
			G[used[i]].push_back(used[to]);
			assert(used[i] < used[to]);
		}
	}

	int v1 = used[s];
	int v2 = used[e];

	assert(v1 <= v2);

	for (int i = 1; i <= C; i++)
	{
		dp[i] = -1e18;
	}

	for (int i = C; i; --i)
	{
		if (i == v2)
			dp[i] = COST[i];
		else
		{
			for (int j = 0; j < G[i].size(); j++)
			{
				int to = G[i][j];
				dp[i] = max(dp[i], dp[to] + COST[i]);
			}
		}
	}

	assert(dp[v1] >= 0);

	cout << dp[v1] << endl;

	//	cout << v1 << "%" << v2 << endl;

	cin.get(); cin.get();
	return 0;
}
