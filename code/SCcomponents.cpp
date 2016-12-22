tack<int> dfs_scc; // additional information for SCC
set<int> in_stack; // for dfs_low update check
void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	dfs_scc.push(u); in_stack.insert(u); // stores u based on order of visitation
	TRvii (AdjList[u], v) {
		if (dfs_num[v->first] == DFS_WHITE) // a tree edge
			tarjanSCC(v->first);
		if (in_stack.find(v->first) != in_stack.end()) // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v->first]); // update dfs_low[u]
	}
	if (dfs_low[u] == dfs_num[u]) { // if this is a root of SCC
		printf("SCC: ");
		while (!dfs_scc.empty() && dfs_scc.top() != u) {
			printf("%d ", dfs_scc.top()); in_stack.erase(dfs_scc.top()); dfs_scc.pop();
		}
		printf("%d\n", dfs_scc.top()); in_stack.erase(dfs_scc.top()); dfs_scc.pop();
	} }

