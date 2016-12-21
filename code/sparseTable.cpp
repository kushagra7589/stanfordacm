#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_SIZE = 1e5+10;
const int K = 16;
const int ZERO = 0; //define zero according to F

ll arr[MAX_SIZE];
ll Table[MAX_SIZE][K+1];

ll F(ll a, ll b)
{
	return max(a, b);
}

void buildTable(int n)
{
	for(int i=0; i<n; i++)
		Table[i][0] = arr[i];
	for(int j = 1; j<=K; j++)
	{
		for(int i=0; i<= n - (1<<j); i++)
		{
			Table[i][j] = F(Table[i][j-1], Table[i + (1<<(j-1))][j-1]);
		}
	}
}

ll query(int l, int r)
{
	ll answer = ZERO;
	for(int j=K; j>=0; j--)
	{
		if(l + (1<<j) - 1  <= r)
			answer = F(answer, Table[l][j]);
		l += (1<<j);
	}
}

int main()
{
	
	return 0;
}