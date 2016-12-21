#include <bits/stdc++.h>

using namespace std;

//all primes strictly smaller than limit -> stored in vectpr prime
void simpleSieve(int limit, vector<int> &prime)
{
	bool mark[limit + 1];
	memset(mark, true, sizeof(mark));

	for(int p=2; p*p < limit; p++)
	{
		if(mark[p] == true)
		{
			prime.push_back(p);
			for(int i=p*p; i<limit; i += p)
				mark[i] = false;
		}
	}
}

void segmentedSieve(int n)
{
	int limit = floor(sqrt(n)) + 1;
	vector<int> prime;
	simpleSieve(limit, prime);

	int low = limit;
	int high = 2*limit;

	while(low < n)
	{
		bool mark[limit + 1];
		memset(mark, true, sizeof(mark));

		//mark non-primes in bucket
		for(int i=0; i<prime.size(); i++)
		{
			//get smallest non-prime divisible by prime[i];
			int loLim = floor(low/prime[i]) * prime[i];
			if(loLim < low)
				loLim += prime[i];

			//mark all multiples of prime[i]
			for(int j=loLim; j<high; j += prime[i])
				mark[j - low] = false;
		}

		//print primes
		for(int i=low; i<high; i++)
			if(mark[i - low] == true)
				cout << i << " ";

		// update low and high
		low += limit;
		high += limit;

		if(high >= n) high = n;
	}
}

int main()
{
	return 0;
}