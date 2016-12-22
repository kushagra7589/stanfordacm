ulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	TRvii (AdjList[u], v)
		if (dfs_num[v->first] == DFS_WHITE) { // a tree edge
			dfs_parent[v->first] = u; // parent of this children is me
			if (u == dfsRoot) // special case
				rootChildren++; // count children of root
			articulationPointAndBridge(v->first);
			if (dfs_low[v->first] >= dfs_num[u]) // for articulation point
				articulation_vertex[u] = true; // store this information first
			if (dfs_low[v->first] > dfs_num[u]) // for bridge
				printf(" Edge (%d, %d) is a bridge\n", u, v->first);
			dfs_low[u] = min(dfs_low[u], dfs_low[v->first]); // update dfs_low[u]
		}
		else if (v->first != dfs_parent[u]) // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v->first]); // update dfs_low[u]
}

// inside int main()
dfsNumberCounter = 0;
memset(dfs_num, DFS_WHITE, sizeof dfs_num);
printf("Bridges:\n");
REP (i, 0, V - 1)
	if (dfs_num[i] == DFS_WHITE) {
		dfsRoot = i; rootChildren = 0;
		articulationPointAndBridge(i);
		articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
	}
printf("Articulation Points:\n");
REP (i, 0, V - 1)
	if (articulation_vertex[i])
	printf(" Vertex %d\n", i);
