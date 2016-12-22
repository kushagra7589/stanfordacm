tor<int> dist(V, INF); dist[s] = 0; // INF = 2B not MAX_INT to avoid overflow
REP (i, 0, V - 1) // relax all E edges V-1 times, O(V)
	REP (u, 0, V - 1) // these two loops = O(E)
	TRvii (AdjList[u], v) // has edge and can be relaxed
	dist[v->first] = min(dist[v->first], dist[u] + v->second);
	REP (i, 0, V - 1)
	printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

	bool negative_cycle_exist = false;
	REP (u, 0, V - 1) // one more pass to check
	TRvii (AdjList[u], v)
	if (dist[v->first] > dist[u] + v->second) // should be false, but if possible
	negative_cycle_exist = true; // then negative cycle exists!
	printf("Negative Cycle Exist? %s\n", negative_cycle_exist ? "Yes" : "No");

