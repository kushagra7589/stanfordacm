#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

vector< pll > adj[MAX_SIZE];

void create_Edge(int x, int y, ll w)
{
	adj[x].pb(mp(y, w));
	adj[y].pb(mp(x, w));
}

void shortestPath(int src)
{
	priority_queue< pll, vector< pll >, greater< pll > > pq;
	vector<ll> dist(MAX_SIZE, INF);
	pq.push(mp(0, src));
	dist[src] = 0;

	while(!pq.empty())
	{
		int u = pq.top().S;
		pq.pop();

		for(auto it : adj[u])
		{
			int v = it.F;
			ll weight = it.S;

			if(dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

int main()
{
	return 0;
}