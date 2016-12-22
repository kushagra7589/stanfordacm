#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int A[N];
int tree[4*N];

void build(int node, int start, int end)
{
	if(start == end){
		tree[node] = A[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int node, int start, int end, int idx, int val){
	if(start == end){
		A[idx] += val;
		tree[node] += val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid){
			update(2*node, start, mid, idx, val);
		}
		else{
			update(2*node+1, mid+1, end, idx, val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int start, int end, int l, int r){
	if(r < start or end < l){
		return 0;
	}
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return (p1 + p2);
}

void updateRange(int node, int start, int end, int l, int r, int val){
	if(lazy[node] != 0){ 
		tree[node] += (end - start + 1) * lazy[node];    // Update it
		if(start != end){
			lazy[node*2] += lazy[node];                  // Mark child as lazy
			lazy[node*2+1] += lazy[node];                // Mark child as lazy
		}
		lazy[node] = 0;                                  // Reset it
	}
	if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
		return;
	if(start >= l and end <= r){
		tree[node] += (end - start + 1) * val;
		if(start != end){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);        // Updating left child
	updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
	tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;         // Out of range
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];            // Update it
		if(start != end)
		{
			lazy[node*2] += lazy[node];         // Mark child as lazy
			lazy[node*2+1] += lazy[node];    // Mark child as lazy
		}
		lazy[node] = 0;                 // Reset it
	}
	if(start >= l and end <= r)             // Current segment is totally within range [l, r]
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
	int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
	return (p1 + p2);
}

int main(){
	return 0;
}