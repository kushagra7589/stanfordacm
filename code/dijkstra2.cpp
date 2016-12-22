le (!pq.empty()) { // main loop
	ii top = pq.top(); pq.pop(); // greedy: pick shortest unvisited vertex
	int d = top.first, u = top.second;
	if (d == dist[u]) // This check is important! We want to process vertex u only once but we can
		// actually enqueue u several times in priority_queue... Fortunately, other occurrences of u
		// in priority_queue will have greater distances and can be ignored (the overhead is small) :)
		TRvii (AdjList[u], it) { // all outgoing edges from u
			int v = it->first, weight_u_v = it->second;
			if (dist[u] + weight_u_v < dist[v]) { // if can relax
				dist[v] = dist[u] + weight_u_v; // relax
				pq.push(ii(dist[v], v)); // enqueue this neighbor
			} } } // regardless whether it is already in pq or not

